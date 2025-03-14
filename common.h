#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#ifndef COMMON_H
#define COMMON_H

typedef struct channel_t channel_t;
typedef struct track_t track_t;
typedef struct state_t state_t;
typedef struct sequence_t sequence_t;
typedef struct composition_t composition_t;
typedef void(*instrument)(channel_t *channel, state_t *state);

typedef struct channel_t
{
    // paths to linux device files
    char enable_path[32];
    char period_path[32];
    char duty_path[32];
    // the number of pitches represented by this channel
    uint8_t currentPitchCount;
    // array of pitches represented by this channel
    uint32_t currentPitches[4];
    // index of next pitch to sound on this channel
    uint8_t nextPitchIndex;
    // current "tone" (voltage?) set on this channel
    uint32_t currentTone;
    uint16_t polyCycleThreshold;
    uint16_t polyCycleCounter;
    // the "instrument" function assigned to this channel, controlling the waveform etc.
    void (*instrument)(channel_t *channel, state_t *state);
} channel_t;

typedef struct track_t
{
    // target channel associated with this track
    channel_t *channel;
    // the sequence of commands associated with this track
    const uint32_t *sequence;
    // the length of the command sequence
    uint16_t sLength;
    // the current position of the command sequence
    uint16_t sPosition;
    // the last position from which a jump was triggered
    uint16_t jPosition;
    // remaining track sleep time in microseconds
    uint64_t remainingSleepTime;
} track_t;

typedef struct state_t
{
    uint8_t numChannels;
    uint8_t numTracks;
    uint16_t rhythmUnit;
    float volume;
    channel_t *channels;
    track_t *tracks;
} state_t;

typedef struct sequence_t
{
    const uint16_t sequenceLength;
    const uint32_t *sequence;
} sequence_t;

typedef struct composition_t
{
    const uint8_t numSequences;
    const uint16_t initialRhythmUnit;
    const sequence_t sequences[];
} composition_t;

extern bool should_terminate;

void initialize_signal_handler(void);
void signal_handler(int signum);
int random_range(int min, int max);

#endif // COMMON_H
