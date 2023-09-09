#pragma once

#include "quantum.h"

/*
        "rows": [
            "GP18","GP19","GP20","GP5",
            "GP8", "GP21","GP22","GP9", "GP10","GP11"
        ],
        "cols": [
            "GP8", "GP21","GP22","GP9", "GP10","GP11",
            "GP18","GP19","GP20","GP5"
        ]
*/

#define LAYOUT( \
  RE, \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L12, L11, L13, R14, R15, R13,  KC_NO,KC_NO,KC_NO,KC_NO }, \
  { L22, L21, L23, R24, R25, R23,  KC_NO,KC_NO,KC_NO,KC_NO }, \
  { L32, L31, L33, R34, R35, R33,  KC_NO,KC_NO,KC_NO,KC_NO }, \
  { RE,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    L15, L25, L35, KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    L14, L24, L34, KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    L43, L44, L45, KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    R11, R21, R31, KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    R12, R22, R32, KC_NO }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    R43, R42, R41, KC_NO } \
}
