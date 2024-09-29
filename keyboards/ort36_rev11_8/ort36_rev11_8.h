#pragma once

#include "quantum.h"

/*
"matrix_pins": {
    "rows": ["GP27","GP14","GP10","GP4", "GP26","GP15","GP9"],
    "cols": ["GP26","GP15","GP9",        "GP27","GP14","GP10","GP4"]
},
*/

#define LAYOUT( \
  LC1, LC2,         RC1, RC2, \
  LL1, LL2, LL3,    RL1, RL2, RL3, \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L11, L12, L13, LC1,         KC_NO, KC_NO, KC_NO }, \
  { L21, L22, L23, LC2,         KC_NO, KC_NO, KC_NO }, \
  { L31, L32, L33, KC_NO,       KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L14, L24, L34 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L15, L25, L35 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, L43, L44, L45 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, LL1, LL2, LL3 }, \
  { R15, R14, R13, RC1,         KC_NO, KC_NO, KC_NO }, \
  { R25, R24, R23, RC2,         KC_NO, KC_NO, KC_NO }, \
  { R35, R34, R33, KC_NO,       KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R12, R22, R32 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R11, R21, R31 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, R43, R42, R41 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, RL1, RL2, RL3 } \
}
