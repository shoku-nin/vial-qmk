#pragma once

#include "quantum.h"

/*
"matrix_pins": {
    "rows": ["GP3","GP4","GP5","GP6","GP7","GP8","GP14"],
    "cols": ["GP7","GP8","GP14",     "GP3","GP4","GP5","GP6"]
},
*/
#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L15, L14, L13,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { L25, L24, L23,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { L35, L34, L33,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { L45, L44, L43,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, L12, L22, L32, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, L11, L21, L31, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}, \
  { R11, R12, R13,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { R21, R22, R23,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { R31, R32, R33,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { R41, R42, R43,       KC_NO, KC_NO, KC_NO, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, R14, R24, R34, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, R15, R25, R35, KC_NO}, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO} \
}



/*
#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L15, L14, L13,       KC_NO, KC_NO, KC_NO }, \
  { L25, L24, L23,       KC_NO, KC_NO, KC_NO }, \
  { L35, L34, L33,       KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, L12, L22, L32 }, \
  { KC_NO, KC_NO, KC_NO, L11, L21, L31 }, \
  { KC_NO, KC_NO, KC_NO, L45, L44, L43 }, \
  { R11, R12, R13,       KC_NO, KC_NO, KC_NO }, \
  { R21, R22, R23,       KC_NO, KC_NO, KC_NO }, \
  { R31, R32, R33,       KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, R14, R24, R34 }, \
  { KC_NO, KC_NO, KC_NO, R15, R25, R35 }, \
  { KC_NO, KC_NO, KC_NO, R41, R42, R43 } \
}
*/
