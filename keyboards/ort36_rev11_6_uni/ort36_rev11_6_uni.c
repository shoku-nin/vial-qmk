#include "ort36_rev11_6_uni.h"

/*
"matrix_pins": {
"rows": [
    "GP5", "GP4", "GP6",
    "GP1", "GP2", "GP3", "GP27","GP26","GP15",
    "GP13","GP7", "GP10","GP12","GP8"
],
"cols": [
    "GP1", "GP2", "GP3", "GP27","GP26","GP15",
    "GP5", "GP4", "GP6",
    "GP12","GP8",        "GP13","GP7", "GP10"
]
},
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b00000000111111,
  0b00000000111111,
  0b00000000111111,
  0b00000111000000,
  0b00000111000000,
  0b00000111000000,
  0b00000111000000,
  0b00000111000000,
  0b00000111000000,
  0b00011000000000,
  0b00011000000000,
  0b00011000000000,
  0b11100000000000,
  0b11100000000000,
};

// RGBLIGHT_LAYER_SEGMENTS
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14     x    33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20

/*
     0 1 2 3 4 5 6 7 8 9 0 1 2 3
0  { q w e p o i = = = = = = = = },
1  { a s d B l k = = = = = = = = },
2  { z x c . , - = = = = = = = = },

     0 1 2 3 4 5 6 7 8 9 0 1 2 3
3  { = = = = = = r f v = = = = = },
4  { = = = = = = t g b = = = = = },
5  { = = = = = = A T S = = = = = },

     0 1 2 3 4 5 6 7 8 9 0 1 2 3
6  { = = = = = = u j m = = = = = },
7  { = = = = = = y h n = = = = = },
8  { = = = = = = D T E = = = = = },

     0 1 2 3 4 5 6 7 8 9 0 1 2 3
9  { = = = = = = = = = 1 = = = = },
10 { = = = = = = = = = 4 5 6 = = },

     0 1 2 3 4 5 6 7 8 9 0 1 2 3
11 { = = = = = = = = = = = = 2 7 },
12 { = = = = = = = = = = = = = 8 },
13 { = = = = = = = = = = = = = 9 }

// Per Key Backlight
// 20 19 18 17 16     0     35 36 37 38 39
// 11 12 13 14 15     1     34 33 32 31 30
// 10  9  8  7  6  5     24 25 26 27 28 29
//        2  3  4           23 22 21
*/

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// Key Matrix to LED Index
{20,19,18, 39,38,37, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, 5 },
{11,12,13, 30,31,32, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, 24 },
{10, 9, 8, 29,28,27, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },

{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 17,14, 7,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 16,15, 6,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,  2, 3, 4,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },

{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 36,33,26,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 35,34,25,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 21,22,23,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },

{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
     0,     NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },

{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, 1,      NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
{ NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,
    NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
// LED Index to Physical Position
// Per Key Backlight
// 20 19 18 17 16     0     35 36 37 38 39
// 11 12 13 14 15     1     34 33 32 31 30
// 10  9  8  7  6  5     24 25 26 27 28 29
//        2  3  4           23 22 21
{ 105,   0 },
{ 108,  60 },
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
8, 4,
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
