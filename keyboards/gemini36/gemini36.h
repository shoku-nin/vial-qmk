#pragma once

#include "quantum.h"

/*
"matrix_pins": {
    "rows": ["GP2", "GP3", "GP4", "GP5"],
    "cols": ["GP10","GP9", "GP8", "GP7", "GP6"]
},
*/

#define LAYOUT( \
  RE_L, RE_R,\
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L11,  L12,  L13, L14, L15 }, \
  { L21,  L22,  L23, L24, L25 }, \
  { L31,  L32,  L33, L34, L35 }, \
  { KC_NO,RE_L, L43, L44, L45 }, \
  { R15,  R14,  R13, R12, R11 }, \
  { R25,  R24,  R23, R22, R21 }, \
  { R35,  R34,  R33, R32, R31 }, \
  { KC_NO,RE_R,R43, R42, R41 } \
}

/*
#define LAYOUT( \
  RE_L, \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L11,  L12,  L13, L14, L15 }, \
  { L21,  L22,  L23, L24, L25 }, \
  { L31,  L32,  L33, L34, L35 }, \
  { KC_NO,RE_L, L43, L44, L45 }, \
  { R15,  R14,  R13, R12, R11 }, \
  { R25,  R24,  R23, R22, R21 }, \
  { R35,  R34,  R33, R32, R31 }, \
  { KC_NO,KC_NO,R43, R42, R41 } \
}
*/
