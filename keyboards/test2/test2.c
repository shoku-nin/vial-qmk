#include "test2.h"

/*
"matrix_pins": {
"rows": [
    "GP10","GP14","GP9" ,"GP29","GP28","GP15",
    "GP5", "GP4", "GP6", "GP1", "GP2", "GP3",
    "GP8", "GP7"
],
"cols": [
    "GP29","GP28","GP15","GP10","GP14","GP9",
    "GP1", "GP2", "GP3", "GP5", "GP4", "GP6",
    "GP7","GP8"
]
},
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b00000000000111,
  0b00000000000111,
  0b00000000000111,
  0b00000000111000,
  0b00000000111000,
  0b00000000111000,
  0b00000111000000,
  0b00000111000000,
  0b00000111000000,
  0b00111000000000,
  0b00111000000000,
  0b00111000000000,
  0b01000000000000,
  0b10000000000000,
};

// RGBLIGHT_LAYER_SEGMENTS
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20

/*
  { q, w, e, =, =, =, =, =, =, =, =, =, =, = }, \
  { a, s, d, =, =, =, =, =, =, =, =, =, =, = }, \
  { z, x, c, =, =, =, =, =, =, =, =, =, =, = }, \
  { =, =, =, r, f, v, =, =, =, =, =, =, =, = }, \
  { =, =, =, t, g, b, =, =, =, =, =, =, =, = }, \
  { =, =, =, A, T, sp,=, =, =, =, =, =, =, = }, \
  { =, =, =, =, =, =, p, o, i, =, =, =, =, = }, \
  { =, =, =, =, =, =, B, l, k, =, =, =, =, = }, \
  { =, =, =, =, =, =, ., ,  -, =, =, =, =, = }, \
  { =, =, =, =, =, =, =, =, =, u, j, m, =, = }, \
  { =, =, =, =, =, =, =, =, =, y, h, n, =, = }, \
  { =, =, =, =, =, =, =, =, =, D, T, E, =, = }, \
  { =, =, =, =, =, =, =, =, =, =, =, =, C1, = }, \
  { =, =, =, =, =, =, =, =, =, =, =, =, =, RE } \
}
// RGBLIGHT_LAYER_SEGMENTS
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20
*/

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// Key Matrix to LED Index
  {19,18,17, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 4 },
  {10,11,12, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 23 },
  { 9, 8, 7, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED,16,13, 6, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED,15,14, 5, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, 1, 2, 3, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,38,37,36, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,29,30,31, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,28,27,26, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,35,32,25, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,34,33,24, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,20,21,22, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 0, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
// LED Index to Physical Position
// Per Key Backlight
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20
{ 108,   0 },
{  48,  60 }, {  72,  60 }, {  96,  60 },
{ 102,  40 },
{  96,  40 }, {  72,  40 }, {  48,  40 }, {  24,  40 }, {   0,  40 },
{   0,  20 }, {  24,  20 }, {  48,  20 }, {  72,  20 }, {  96,  20 },
{  96,   0 }, {  72,   0 }, {  48,   0 }, {  24,   0 }, {   0,   0 },
//
{ 168,  60 }, { 144,  60 }, { 120,  60 },
{ 114,  40 },
{ 120,  40 }, { 144,  40 }, { 168,  40 }, { 192,  40 }, { 216,  40 },
{ 216,  20 }, { 196,  20 }, { 168,  20 }, { 144,  20 }, { 120,  20 },
{ 120,   0 }, { 144,   0 }, { 168,   0 }, { 192,   0 }, { 216,   0 }
}, {
// LED Index to Flag
8,
4, 4, 4,
4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4,
4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4
} };
#endif
