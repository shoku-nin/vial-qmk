#pragma once

#include "quantum.h"

/*
"matrix_pins": {
"rows": [
    "GP13","GP7", "GP10","GP12","GP8"
],
"cols": [
    "GP12","GP8",        "GP13","GP7", "GP10"
]
},
*/

#define LAYOUT( \
  C1,  C2, \
  TL1, TL2, TL3, \
  TR1, TR2, TR3 \
) \
{ \
  { C1,    KC_NO, KC_NO, KC_NO, KC_NO }, \
  { TL1,   TL2,   TL3,   KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, C2,    TR1 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, TR2 }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, TR3 } \
}
