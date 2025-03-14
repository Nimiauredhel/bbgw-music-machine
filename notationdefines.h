#ifndef NOTATION_DEFINES_H
#define NOTATION_DEFINES_H

#include "stdint.h"
#include "pitches.h"
// sequence encoding:
// first element: music event type (also implying length)
// 0: sleep, 1-4: select 1-4 pitches & sleep
// 5: volume, 
// 6: instrument index 
// 7: rhythm unit (tempo)
// 8: jump x cells back
// 9: volume & sleep
// 11-14: select 1-4 pitches, volume & sleep
// following elements are the function parameters

#define SLEEP(x) 0, x,
#define PITCHS(x, s) 1, x, s,
#define PITCH2S(x, y, s) 2, x, y, s,
#define PITCH3S(x, y, z, s) 3, x, y, z, s,
#define PITCH4S(x, y, z, w, s) 4, x, y, z, w, s,
#define VOLUME(x) 5, (x),
#define INSTRUMENT(x) 6, x,
#define TEMPO(x) 7, x,
#define JUMPBACK(x) 8, x,
#define VOLUMES(x, s) 9, (x), s,

#define NOTE(x, t, sl) 11, x, (t), sl,
#define NOTE2(x, y, t, sl) 12, x, y, (t), sl,
#define NOTE3(x, y, z, t, sl) 13, x, y, z, (t), sl,
#define NOTE4(x, y, z, w, t, sl) 14, x, y, z, w, (t), sl,

#define SILENCE(s) VOLUMES(0, s)

#define QUIET 0
#define SQUARE 1

#endif
