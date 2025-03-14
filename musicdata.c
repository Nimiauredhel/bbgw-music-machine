#include "musicdata.h"

#include "notationdefines.h"

uint32_t voiceOne[] =
{
    INSTRUMENT(SQUARE)
        TEMPO(16)
    NOTE(G4, 48, 8)
    NOTE(F4, 42, 4) SILENCE(4)
    //
    NOTE(E4, 48, 8)
    NOTE(D4, 48, 4)
    PITCHS(C4, 4)
    PITCHS(B3, 4)
    PITCHS(Db4, 3) SILENCE(1)
    //
    NOTE(D4, 42, 8)
    NOTE(E4, 48, 4)
    PITCHS(Gb4, 4)
    PITCHS(G4, 4)
    PITCHS(E4, 3) SILENCE(1)
    //
    NOTE(Gb4, 48, 16)
    PITCHS(D4, 16)
    NOTE(G4, 48, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(A4, 48, 8)
    NOTE(G4, 42, 4)
    PITCHS(F4, 4)
    PITCHS(E4, 4)
    PITCHS(F4, 3) SILENCE(1)
    //
    NOTE(G4, 42, 8)
    NOTE(F4, 48, 4)
    PITCHS(E4, 4)
    PITCHS(D4, 4)
    PITCHS(E4, 3) SILENCE(1)
    //
    NOTE(C4, 48, 4)
    VOLUMES(40, 4)
    VOLUMES(32, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(D4, 48, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(A4, 48, 8)
    VOLUMES(42, 4)
    NOTE(G4, 48, 4)
    PITCHS(Gb4, 4) SILENCE(4)
    //
    NOTE(Ab4, 48, 8)
    VOLUMES(32, 4)
    PITCHS(A5, 4)
    NOTE(B4, 24, 4) SILENCE(4)
    //
    NOTE(A4, 48, 4)
    VOLUMES(40, 4)
    VOLUMES(32, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(C4, 48, 6) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(G4, 42, 8)
    VOLUMES(48, 4)
    NOTE(F4, 32, 4)
    PITCHS(E4, 4) SILENCE(4)
    //
    NOTE(Gb4, 48, 8) VOLUMES(24, 4)
    NOTE(G4, 32, 4)
    PITCHS(A4, 4) SILENCE(4)
    //
    NOTE(G4, 42, 4) VOLUMES(48, 4) VOLUMES(32, 6) SILENCE(2)
    JUMPBACK(13)
    // vocal part
    NOTE(E5, 48, 7) SILENCE(1)
    JUMPBACK(7)
    NOTE(E5, 48, 15) SILENCE(1)
    NOTE(C5, 48, 3) SILENCE(1)
    JUMPBACK(7)
    NOTE(B4, 42, 15) SILENCE(2)
    NOTE(B4, 32, 3) SILENCE(1)
    JUMPBACK(7)
    NOTE(A4, 48, 14) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(E4, 42, 7) SILENCE(1)
    JUMPBACK(7)
    NOTE(G4, 48, 15) SILENCE(1)
    NOTE(G4, 48, 3) SILENCE(1)
    JUMPBACK(7)
    NOTE(A4, 42, 15) SILENCE(1)
    NOTE(B4, 32, 3) SILENCE(1)
    JUMPBACK(7)
    NOTE(B4, 42, 14) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(A4, 32, 6) SILENCE(2)
    NOTE(B4, 48, 6) SILENCE(2)
    NOTE(C5, 42, 12) SILENCE(4)
    NOTE(D5, 48, 12) SILENCE(4)
    NOTE(D5, 42, 6) SILENCE(2)
    NOTE(C5, 48, 6) SILENCE(2)
    //
    NOTE(C5, 48, 12) SILENCE(4)
    NOTE(C5, 48, 16)
    NOTE(E5, 42, 8)
    NOTE(C5, 48, 8)
    NOTE(D5, 48, 8) VOLUMES(48, 8)
    PITCHS(B4, 8)
    PITCHS(C5, 4) SILENCE(4)
    NOTE(A4, 48, 12) SILENCE(4)
    NOTE(B4, 48, 12) SILENCE(4)
    NOTE(A4, 32, 12) SILENCE(4)
    //
    NOTE(G4, 32, 8)
    PITCHS(Gb4, 8)
    NOTE(G4, 48, 16)
    NOTE(A4, 42, 6) SILENCE(2)
    NOTE(A4, 48, 16)
    NOTE(G4, 48, 6) SILENCE(2)
    NOTE(G4, 32, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(E5, 48, 6) SILENCE(2)
    JUMPBACK(7)
    NOTE(E5, 42, 14) SILENCE(2)
    NOTE(C5, 48, 2) SILENCE(2)
    JUMPBACK(7)
    NOTE(B4, 48, 14) SILENCE(2)
    NOTE(B4, 32, 2) SILENCE(2)
    JUMPBACK(7)
    NOTE(A4, 48, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(E4, 42, 6) SILENCE(2)
    NOTE(F4, 48, 6) SILENCE(2)
    NOTE(G4, 42, 8) VOLUMES(20, 4)
    NOTE(A4, 32, 4)
    PITCHS(B4, 4) VOLUMES(32, 4)
    NOTE(A4, 48, 12) SILENCE(4)
    NOTE(A4, 42, 2) SILENCE(2)
    JUMPBACK(7)
    NOTE(G4, 48, 12) SILENCE(4)
    JUMPBACK(7)
};

uint32_t voiceTwo[] =
{
    INSTRUMENT(SQUARE)
        TEMPO(16)
    NOTE(B1, 24, 4) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(C2, 32, 12)
    NOTE(D2, 24, 4)
    PITCHS(E2, 4) SILENCE(4)
    NOTE(D2, 32, 8) VOLUMES(24, 8)
    PITCHS(A1, 4) SILENCE(4)
    NOTE(D2, 32, 4) VOLUMES(28, 4) VOLUMES(24, 4) SILENCE(4)
    JUMPBACK(13)
    //
    NOTE(E2, 24, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(F2, 32, 8) VOLUMES(24, 4)
    PITCHS(G2, 2) SILENCE(2)
    NOTE(A2, 24, 4) SILENCE(4)
    //
    NOTE(G2, 24, 8) VOLUMES(24, 8)
    PITCHS(G1, 4) SILENCE(4)
    //
    NOTE(C2, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(G2, 24, 6) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(F2, 32, 8) VOLUMES(24, 4)
    PITCHS(E2, 2) SILENCE(2)
    NOTE(D2, 24, 4) SILENCE(4)
    //
    NOTE(E3, 32, 8) VOLUMES(32, 8)
    PITCHS(E3, 4) SILENCE(4)
    NOTE(A1, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    //
    NOTE(F2, 24, 4) SILENCE(4)
    JUMPBACK(7)
    NOTE(E2, 32, 8) VOLUMES(24, 4)
    PITCHS(D2, 4)
    NOTE(C2, 24, 4) SILENCE(4)
    NOTE(D2, 32, 8) VOLUMES(24, 8)
    NOTE(D2, 28, 4) SILENCE(4)
    NOTE(G2, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    // vocal part
    NOTE(G2, 16, 16)
    PITCHS(A2, 12) SILENCE(4)
    NOTE(A2, 16, 4) SILENCE(4)
    NOTE(E2, 16, 12) SILENCE(4)
    NOTE(E2, 16, 4) SILENCE(4)
    NOTE(A1, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(A1, 16, 16)
    PITCHS(G1, 12) SILENCE(4)
    NOTE(G1, 16, 4) SILENCE(4)
    NOTE(D2, 16, 12) SILENCE(4)
    NOTE(D2, 16, 4) SILENCE(4)
    NOTE(G1, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(G1, 24, 16)
    PITCHS(F2, 32)
    NOTE(G2, 24, 12) SILENCE(4)
    NOTE(C2, 16, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(C3, 16, 6) SILENCE(2)
    JUMPBACK(7)
    NOTE(B2, 24, 12) SILENCE(4)
    NOTE(B2, 16, 6) SILENCE(2)
    NOTE(A2, 16, 12) SILENCE(4)
    NOTE(D2, 16, 6) SILENCE(2)
    NOTE(G2, 24, 16)
    PITCHS(F2, 16)
    //
    NOTE(E2, 16, 8)
    PITCHS(D2, 8)
    NOTE(B1, 24, 12) SILENCE(4)
    NOTE(C2, 16, 6) SILENCE(2)
    NOTE(D2, 16, 12) SILENCE(4)
    NOTE(D2, 16, 6) SILENCE(2)
    NOTE(G1, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(G1, 16, 16)
    PITCHS(A2, 12) SILENCE(4)
    NOTE(A2, 16, 6) SILENCE(2)
    NOTE(E2, 16, 12) SILENCE(4)
    NOTE(E2, 16, 6) SILENCE(2)
    NOTE(A1, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(A1, 16, 16)
    PITCHS(G1, 12) SILENCE(4)
    NOTE(G1, 16, 6) SILENCE(2)
    NOTE(D2, 16, 12) SILENCE(4)
    NOTE(D2, 24, 6) SILENCE(2)
    NOTE(G1, 32, 12) SILENCE(4)
    JUMPBACK(7)
};

uint32_t voiceThree[] =
{
    INSTRUMENT(SQUARE)
        TEMPO(16)
    NOTE(D4, 16, 8)
    NOTE(D4, 24, 4) SILENCE(4)
    //
    NOTE(C4, 32, 8)
    NOTE(B3, 24, 4)
    PITCHS(A3, 4)
    PITCHS(G3, 7) SILENCE(1)
    //
    NOTE(A3, 32, 4)
    NOTE(B3, 32, 4)
    NOTE(Db4, 24, 4)
    PITCHS(D4, 4)
    PITCHS(E4, 4)
    PITCHS(Db4, 3) SILENCE(1)
    //
    NOTE(D4, 32, 16)
    PITCHS(A3, 16)
    NOTE(C4, 24, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(C4, 32, 12) SILENCE(4)
    NOTE(C4, 32, 6) SILENCE(2)
    NOTE(C4, 32, 12) SILENCE(4)
    NOTE(B3, 32, 6) SILENCE(2)
    //
    NOTE(G3, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(B3, 24, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(C4, 32, 16)
    NOTE(D4, 16, 8)
    NOTE(B3, 32, 16)
    NOTE(E4, 16, 6) SILENCE(2)
    //
    NOTE(C4, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(A3, 24, 6) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(B3, 32, 8)
    VOLUMES(24, 8)
    NOTE(E4, 16, 4) SILENCE(4)
    NOTE(D4, 32, 12)
    NOTE(E4, 24, 4)
    NOTE(Gb4, 16, 4) SILENCE(4)
    //
    NOTE(D4, 16, 4) VOLUMES(24, 4) VOLUMES(28, 6) SILENCE(2)
    NOTE(D4, 32, 4) VOLUMES(28, 4) VOLUMES(24, 4) SILENCE(4)
    // vocal part - accompaniement
    SILENCE(16)
    //
    NOTE3(C4, E4, A4, 10, 16)
    NOTE3(C4, F4, A4, 10, 8)
    NOTE3(B3, E4, G4, 10, 24)
    NOTE3(C4, E4, A4, 10, 32)
    NOTE3(C4, F4, A4, 10, 16)
    //
    NOTE3(B3, D4, G4, 10, 24)
    NOTE3(A3, D4, Gb4,10, 24)
    NOTE3(B3, D4, G4, 10, 48)
    //
    NOTE3(A3, C4, F4, 10, 32)
    NOTE3(G3, D4, F4, 10, 16)
    NOTE3(G3, C4, E4, 10, 48)
    //
    NOTE3(G3, D4, G4, 10, 24)
    NOTE3(Gb3, D4, A4,10, 24)
    NOTE3(G3, D4, B4, 10, 32)
    NOTE3(D4, Gb4, C5,10, 16)
    //
    NOTE3(D4, G4, B4, 10, 24)
    NOTE3(C4, Gb4, A4,10, 24)
    NOTE3(B3, D4, G4, 10, 32)
    NOTE3(B3, E4, Ab4,10, 16)
    //
    NOTE3(C4, E4, A4, 10, 16)
    NOTE3(C3, F4, A4, 10, 8)
    NOTE3(B3, E4, Ab4, 10, 24)
    NOTE3(C4, F4, Ab4, 10, 32)
    NOTE3(Db4, E4, A4, 11, 16)
    //
    NOTE3(B3, D4, G4, 12, 24)
    NOTE3(A3, D4, Gb4, 13, 24)
    NOTE4(G3, B3, D4, G4, 14, 32)
};

uint32_t voiceFour[] =
{
    INSTRUMENT(SQUARE)
        TEMPO(16)
    NOTE(B0, 24, 4) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(C1, 32, 12)
    NOTE(D1, 24, 4)
    PITCHS(E1, 4) SILENCE(4)
    NOTE(D1, 32, 8) VOLUMES(24, 8)
    PITCHS(A0, 4) SILENCE(4)
    NOTE(D1, 32, 4) VOLUMES(28, 4) VOLUMES(24, 4) SILENCE(4)
    JUMPBACK(13)
    //
    NOTE(E1, 24, 7) SILENCE(1)
    JUMPBACK(7)
    //
    NOTE(F1, 32, 8) VOLUMES(24, 4)
    PITCHS(G1, 2) SILENCE(2)
    NOTE(A1, 24, 4) SILENCE(4)
    //
    NOTE(G1, 24, 8) VOLUMES(24, 8)
    PITCHS(G0, 4) SILENCE(4)
    //
    NOTE(C1, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    NOTE(G1, 24, 6) SILENCE(2)
    JUMPBACK(7)
    //
    NOTE(F1, 32, 8) VOLUMES(24, 4)
    PITCHS(E1, 2) SILENCE(2)
    NOTE(D1, 24, 4) SILENCE(4)
    //
    NOTE(E2, 32, 8) VOLUMES(32, 8)
    PITCHS(E2, 4) SILENCE(4)
    NOTE(A0, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    //
    NOTE(F1, 24, 4) SILENCE(4)
    JUMPBACK(7)
    NOTE(E1, 32, 8) VOLUMES(24, 4)
    PITCHS(D1, 4)
    NOTE(C1, 24, 4) SILENCE(4)
    NOTE(D1, 32, 8) VOLUMES(24, 8)
    NOTE(D1, 28, 4) SILENCE(4)
    NOTE(G1, 32, 4)
    VOLUMES(28, 4)
    VOLUMES(24, 4)
    SILENCE(4)
    JUMPBACK(13)
    // vocal part
    NOTE(G1, 16, 16)
    PITCHS(A1, 12) SILENCE(4)
    NOTE(A1, 16, 4) SILENCE(4)
    NOTE(E1, 16, 12) SILENCE(4)
    NOTE(E1, 16, 4) SILENCE(4)
    NOTE(A0, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(A0, 16, 16)
    PITCHS(G0, 12) SILENCE(4)
    NOTE(G0, 16, 4) SILENCE(4)
    NOTE(D1, 16, 12) SILENCE(4)
    NOTE(D1, 16, 4) SILENCE(4)
    NOTE(G0, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(G0, 24, 16)
    PITCHS(F1, 32)
    NOTE(G1, 24, 12) SILENCE(4)
    NOTE(C1, 16, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(C2, 16, 6) SILENCE(2)
    JUMPBACK(7)
    NOTE(B1, 24, 12) SILENCE(4)
    NOTE(B1, 16, 6) SILENCE(2)
    NOTE(A1, 16, 12) SILENCE(4)
    NOTE(D1, 16, 6) SILENCE(2)
    NOTE(G1, 24, 16)
    PITCHS(F1, 16)
    //
    NOTE(E1, 16, 8)
    PITCHS(D1, 8)
    NOTE(B0, 24, 12) SILENCE(4)
    NOTE(C1, 16, 6) SILENCE(2)
    NOTE(D1, 16, 12) SILENCE(4)
    NOTE(D1, 16, 6) SILENCE(2)
    NOTE(G0, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(G0, 16, 16)
    PITCHS(A1, 12) SILENCE(4)
    NOTE(A1, 16, 6) SILENCE(2)
    NOTE(E1, 16, 12) SILENCE(4)
    NOTE(E1, 16, 6) SILENCE(2)
    NOTE(A0, 24, 12) SILENCE(4)
    JUMPBACK(7)
    //
    NOTE(A0, 16, 16)
    PITCHS(G0, 12) SILENCE(4)
    NOTE(G0, 16, 6) SILENCE(2)
    NOTE(D1, 16, 12) SILENCE(4)
    NOTE(D1, 24, 6) SILENCE(2)
    NOTE(G0, 32, 12) SILENCE(4)
    JUMPBACK(7)
};

const composition_t composition =
{
    .numSequences = 4,
    .initialRhythmUnit = 16,
    .sequences =
    {
        {
            .sequenceLength = sizeof(voiceOne) / sizeof(voiceOne[0]),
            .sequence = voiceOne
        },
        {
            .sequenceLength = sizeof(voiceTwo) / sizeof(voiceTwo[0]),
            .sequence = voiceTwo
        },
        {
            .sequenceLength = sizeof(voiceThree) / sizeof(voiceThree[0]),
            .sequence = voiceThree
        },
        {
            .sequenceLength = sizeof(voiceFour) / sizeof(voiceFour[0]),
            .sequence = voiceFour
        },
    }
};
