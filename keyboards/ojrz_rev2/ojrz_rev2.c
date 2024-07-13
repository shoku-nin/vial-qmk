//#include "ojrz_rev2.h"

#define LAYOUT( \
  LRE,                       RRE, \
  LL,  LC,  LR,              RL,  RC,  RR, \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L11,   L12,   L13, L14, L15 }, \
  { L21,   L22,   L23, L24, L25 }, \
  { L31,   L32,   L33, L34, L35 }, \
  { KC_NO, LRE,   L43, L44, L45 }, \
  { KC_NO, KC_NO, LL,  LC,  LR }, \
  { R15,   R14,   R13, R12, R11 }, \
  { R25,   R24,   R23, R22, R21 }, \
  { R35,   R34,   R33, R32, R31 }, \
  { KC_NO, RRE,   R43, R42, R41 }, \
  { KC_NO, KC_NO, RR,  RC,  RL } \
}


#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// Key Matrix to LED Index
// master = right
// Left Side
{ 22,21,20,19,18 },
{ 23,24,25,26,27 },
{ 32,31,30,29,28 },
{ NO_LED,NO_LED,33,34,35 },
{ NO_LED,NO_LED,NO_LED,NO_LED,NO_LED },
// Right Side
{  4, 3, 2, 1, 0 },
{  5, 6, 7, 8, 9 },
{ 14,13,12,11,10 },
{ NO_LED,NO_LED,15,16,17 },
{ NO_LED,NO_LED,NO_LED,NO_LED,NO_LED }
}, {
// LED Index to Physical Position
// Per Key Backlight
// Right Side
{ 120,   0 }, { 144,   0 }, { 168,   0 }, { 192,   0 }, { 216,   0 },
{ 216,  20 }, { 196,  20 }, { 168,  20 }, { 144,  20 }, { 120,  20 },
{ 120,  40 }, { 144,  40 }, { 168,  40 }, { 192,  40 }, { 216,  40 },
{ 168,  60 }, { 144,  60 }, { 120,  60 },
// Left Side
{   0,   0 }, {  24,   0 }, {  48,   0 }, {  72,   0 }, {  96,   0 },
{  96,  20 }, {  72,  20 }, {  48,  20 }, {  24,  20 }, {   0,  20 },
{   0,  40 }, {  24,  40 }, {  48,  40 }, {  72,  40 }, {  96,  40 },
                            {  48,  60 }, {  72,  60 }, {  96,  60 }
}, {
// LED Index to Flag
8, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4,
8, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4
} };
#endif
