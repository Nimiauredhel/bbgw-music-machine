#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

#include "musicdata.h"
#include "common.h"

static void initializeChannel(channel_t *channel, const char *device_path);
static channel_t* initializeChannels(uint8_t numChannels);
static void initializeTrack(track_t *track, channel_t *channel, const sequence_t *sequence);
static track_t* initializeTracks(uint8_t numTracks, channel_t *channels, const composition_t *pComposition);
static state_t* initializeState(const composition_t *pComposition);
static void readTrack(track_t *target, uint16_t *rhythmUnit);
static void readTracks(state_t *state);
static void playChannels(state_t *state);
static void instSilence(channel_t *channel, state_t *state);
static void instRegular(channel_t *channel, state_t *state);
static void write_file(const char *path, const uint32_t value);
static void delay_ms (uint16_t ms);

static const uint16_t sleepUnit = 1;

const instrument instruments[] =
{
    instSilence, instRegular
};

int main(void)
{
    system("sh setup.sh");
    // initialize data
    state_t *state = initializeState(&composition);

    // take a deep breath
    sleep(1);

    // let's gooo
    for(;;)
    {
        readTracks(state);
        playChannels(state);
	delay_ms(sleepUnit);
    }

    return 0;
}

static void initializeChannel(channel_t *channel, const char *device_path)
{
    sprintf(channel->enable_path, "%s/enable", device_path);
    sprintf(channel->period_path, "%s/period", device_path);
    sprintf(channel->duty_path, "%s/duty_cycle", device_path);
    channel->currentTone = 0;
    write_file(channel->duty_path, 0);
    write_file(channel->enable_path, 1);
    for(int i = 0; i < 4; i++)
    {
        channel->currentPitches[i] = 255;
    }
    channel->currentPitchCount = 0;
    channel->nextPitchIndex = 0;
    channel->polyCycleThreshold = 2;
    channel->polyCycleCounter = 0;
    channel->instrument = instruments[0];
}

static channel_t* initializeChannels(uint8_t numChannels)
{
    static const char device_paths[4][32] =
    {
	"/dev/bone/pwm/0/a/",
	"/dev/bone/pwm/0/b/",
	"/dev/bone/pwm/1/a/",
	"/dev/bone/pwm/1/b/",
    };

    channel_t *channels = malloc((numChannels) * sizeof(channel_t));

    for (int i = 0; i < numChannels; i++)
    {
        initializeChannel(&channels[i], device_paths[i]);
    }
    return channels;
}

static void initializeTrack(track_t *track, channel_t *channel, const sequence_t *sequence)
{
    track->channel = channel;
    track->sequence = sequence->sequence;
    track->sLength = sequence->sequenceLength;
    track->sPosition = 0;
    track->remainingSleepTime = 0;
    track->jPosition = 0;
}

static track_t* initializeTracks(uint8_t numTracks, channel_t *channels, const composition_t *pComposition)
{
    track_t *tracks = malloc((numTracks) * sizeof(track_t));

    for (int i = 0; i < numTracks; i++)
    {
        initializeTrack(&tracks[i], &channels[i], &pComposition->sequences[i]);
    }

    return tracks;
}

static state_t* initializeState(const composition_t *pComposition)
{
    state_t *state = malloc(sizeof(state_t));
    state->rhythmUnit = pComposition->initialRhythmUnit;
    state->numChannels = pComposition->numSequences;
    state->numTracks = pComposition->numSequences;
    // initialize the channels - device usage & state management
    state->channels = initializeChannels(state->numChannels);
    // initialize the tracks - parallel streams of commands to the channels
    state->tracks = initializeTracks(state->numTracks, state->channels, pComposition);
    // giving up on ADC volume for now -
    // clearly not as straightforward as it was in the atmega,
    // and it wasn't the right way anyway
    state->volume = 512.0;

    return state;
}

static void readTrack(track_t *target, uint16_t *rhythmUnit)
{
    if (target->remainingSleepTime > 0)
    {
        target->remainingSleepTime-=sleepUnit;
        return;
    }
    
    if (target->sPosition >= target->sLength - 1)
    {
        target->remainingSleepTime = 0;
        return;
    }

    const uint32_t *tSequence = target->sequence;
    uint16_t position = target->sPosition;
    uint8_t code = tSequence[position];
    channel_t *tChannel = target->channel;

    switch (code) 
    {
        case 0:
            // sleep for duration
            target->remainingSleepTime =
                tSequence[position+1] * sleepUnit * (*rhythmUnit);
            target->sPosition = position+2;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            // Set pitches
            // pitches + sleep combo to save space
            target->remainingSleepTime =
                tSequence[position+code+1] * sleepUnit * (*rhythmUnit);
            tChannel->currentPitchCount = code;
            target->sPosition = position + code + 2;
            for (int i = 0; i < code; i++)
            {
                tChannel->currentPitches[i] = tSequence[position+i+1];
            }
            tChannel->nextPitchIndex = 0;
            break;
        case 11:
        case 12:
        case 13:
        case 14:
            code -= 10;
            // Set pitches
            // pitches + sleep + volume combo to save space
            target->channel->currentTone = tSequence[position+code+1];
            target->remainingSleepTime =
                tSequence[position+code+2] * sleepUnit * (*rhythmUnit);
            target->sPosition = position + code + 3;
            tChannel->currentPitchCount = code;
            for (int i = 0; i < code; i++)
            {
                tChannel->currentPitches[i] = tSequence[position+i+1];
            }
            tChannel->nextPitchIndex = 0;
            break;
        case 5:
            // Set "volume" (voltage)
            tChannel->currentTone =
                tSequence[position+1];
            target->sPosition = position+2;
            break;
        case 6:
            // Set instrument function
            tChannel->instrument =
                instruments[tSequence[position+1]];
            target->sPosition = position+2;
            break;
        case 7:
            // Set rhythm unit (tempo)
            (*rhythmUnit) =
                tSequence[position+1];
            target->sPosition = position+2;
            break;
        case 8:
            // Jump back (repeat)
            if (target->jPosition == position)
            {
                target->sPosition = position+2;
                target->jPosition = 0;
            }
            else
            {
                target->jPosition = position;
                target->sPosition = position-(tSequence[position+1]);
            }
            break;
        case 9:
            // volume + sleep
            tChannel->currentTone =
                tSequence[position+1];
            target->remainingSleepTime =
                tSequence[position+2] * sleepUnit * (*rhythmUnit);
            target->sPosition = position+3;
            break;
        default:
            // TODO: add some sort of warning behavior
        break;
    }
}

static void readTracks(state_t* state)
{
    track_t* tracks = state->tracks;
    // check if it's time to loop
    // and manually resync tracks
    for (int i = 0; i < state->numTracks; i++)
    {
        if (tracks[i].sPosition >= tracks[i].sLength-1
            && tracks[i].remainingSleepTime <= 0)
        {
            // if true for ONE, sync ALL then continue!
            for(int j = 0; j < state->numTracks; j++)
            {
                tracks[j].sPosition = 0;
                tracks[j].jPosition = 0;
                tracks[j].remainingSleepTime = 0;
            }
            break;
        }
    }
    
    // proceed to execute track commands
    for (int i = 0; i < state->numTracks; i++)
    {
        readTrack(&tracks[i], &state->rhythmUnit);
    }
}

static void playChannels(state_t *state)
{
    channel_t* channels = state->channels;

    for (int i = 0; i < state->numChannels; i++)
    {
        channels[i].instrument(&channels[i], state);
    }
}

static void instSilence(channel_t *channel, state_t *state)
{
}

static void instRegular(channel_t *channel, state_t *state)
{
    if (channel->currentPitchCount == 0) return;

    if (channel->nextPitchIndex >= channel->currentPitchCount)
    {
        channel->nextPitchIndex = 0;
    }

    uint32_t pitch = channel->currentPitches[channel->nextPitchIndex];
    write_file(channel->period_path, pitch);
    uint32_t finalTone = (channel->currentTone)*(state->volume);
    write_file(channel->duty_path, finalTone);

    channel->polyCycleCounter++;

    if (channel->polyCycleCounter >= channel->polyCycleThreshold)
    {
        channel->polyCycleCounter = 0;
        if (channel->nextPitchIndex < channel->currentPitchCount-1)
        {
            channel->nextPitchIndex++;
        }
        else if (channel->nextPitchIndex == channel->currentPitchCount-1)
        {
            channel->nextPitchIndex = 0;
        }
    }
}

static void write_file(const char *path, const uint32_t value)
{
    char value_str[32] = {0};
    int fd = open(path, O_RDWR, S_IWUSR);

    if (fd == -1)
    {
            printf("Failed to open \"%s\". Error: %s.\n", path, strerror(errno));
            exit(1);
    }

    sprintf(value_str, "%lu", value);

    write(fd, value_str, strlen(value_str));

    close(fd);
}

static void delay_ms (uint16_t ms)
{
    usleep(ms * 1000);
}
