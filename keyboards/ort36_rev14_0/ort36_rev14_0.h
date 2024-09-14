#pragma once

#include "quantum.h"

/*
"matrix_pins": {
"rows": [
    "GP26","GP27","GP15",
    "GP5","GP4", "GP3","GP2"
],
"cols": [
    "GP5","GP4", "GP3","GP2",
    "GP26","GP27","GP15"
]
},
*/

#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43, \
            TL1, TL2, TL3,   TR1, TR2, TR3 \
) \
{ \
  { L11, L12, L13, TL1,         KC_NO, KC_NO, KC_NO }, \
  { L21, L22, L23, TL2,         KC_NO, KC_NO, KC_NO }, \
  { L31, L32, L33, TL3,         KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L14, L24, L34 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L15, L25, L35 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L43, L44, L45 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { R15, R14, R13, TR1,         KC_NO, KC_NO, KC_NO }, \
  { R25, R24, R23, TR2,         KC_NO, KC_NO, KC_NO }, \
  { R35, R34, R33, TR3,         KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R12, R22, R32 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R11, R21, R31 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R43, R42, R41 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}
