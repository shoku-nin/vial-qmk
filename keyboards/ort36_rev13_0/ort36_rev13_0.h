#pragma once

#include "quantum.h"

/*
"matrix_pins": {
    "rows": ["GP2","GP3","GP4","GP5","GP28"],
    "cols": ["GP2","GP3","GP4","GP5","GP28"]
},
*/

#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43, \
            LC1, LC2,             RC1, RC2 \
) \
{ \
  { KC_NO, L12,   L11,   L21,   L31 }, \
  { L13,   KC_NO, L23,   L22,   L32 }, \
  { L14,   L24,   KC_NO, L34,   L33 }, \
  { L15,   L25,   L35,   KC_NO, L43 }, \
  { L44,   L45,   LC1,   LC2,   KC_NO }, \
  { KC_NO, R14,   R15,   R25,   R35 }, \
  { R13,   KC_NO, R23,   R24,   R34 }, \
  { R12,   R22,   KC_NO, R32,   R33 }, \
  { R11,   R21,   R31,   KC_NO, R43 }, \
  { R42,   R41,   RC2,   RC1,   KC_NO } \
}
