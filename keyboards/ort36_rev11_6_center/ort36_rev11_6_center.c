#include "ort36_rev11_6_center.h"

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

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b00011,
  0b00011,
  0b00011,
  0b11100,
  0b11100,
};

/*
     0 1 2 3 4
 0 { 1 = = = = },
 1 { 4 5 6 = = },
 2 { = = = 2 7 },
 3 { = = = = 8 },
 4 { = = = = 9 }

*/

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// Key Matrix to LED Index
{    0,     NO_LED, NO_LED, NO_LED, NO_LED },
{   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },

{   NO_LED, NO_LED, NO_LED, 1,      NO_LED },
{   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
// LED Index to Physical Position
// Per Key Backlight
// 20 19 18 17 16     0     35 36 37 38 39
// 11 12 13 14 15     1     34 33 32 31 30
// 10  9  8  7  6  5     24 25 26 27 28 29
//        2  3  4           23 22 21
{ 105,   0 },
{ 108,  60 }
}, {
// LED Index to Flag
8, 4,
} };
#endif
