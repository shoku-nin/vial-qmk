#pragma once

#include "quantum.h"

/*
"rows": [
    "GP2", "GP3", "GP4", "GP1",
    "GP20","GP23","GP21","GP7","GP6","GP5","GP22"
],
"cols": [
    "GP20","GP23","GP21","GP7","GP6","GP5","GP22",
    "GP2", "GP3", "GP4", "GP1"
]
rows:      "GP2", "GP3", "GP4", "GP1",
left cols: "GP20","GP23","GP21",
right cols:"GP7", "GP6", "GP5"

   20 23 21 7  6  5  22 2  3  4  1
2  e  r  t  y  u  i
3  d  f  g  h  j  k
4  c  v  b  n  m  -
1  Al L2 SP Et L1 De
20                               CL
23                      q* a* z*
21                      w* s* x*
7                       o* l* ,*
6                       p* B* .*
5                                CR
22

    GP20 GP23 GP21 GP20 GP23 GP21   GP7 GP6 GP5 GP7 GP6 GP5   GP22
GP2      q*   w*   e    r    t      y   u   i   o*  p*
GP3      a*   s*   d    f    g      h   j   k   l*  BS*
GP4      z*   x*   c    v    b      n   m   -   ,*  .*
GP1 CL*            Alt  L2   SP     Ent L1  Del         CR*   RE
*/

#define LAYOUT( \
  CL,  CR,  RE, \
  L11, L12, L13, L14, L15,  R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,  R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,  R31, R32, R33, R34, R35, \
            L43, L44, L45,  R41, R42, R43 \
) \
{ \
  { KC_NO,R15,  R14,  L12,  L11,  KC_NO,KC_NO, KC_NO,KC_NO,KC_NO,KC_NO}, \
  { KC_NO,R25,  R24,  L22,  L21,  KC_NO,KC_NO, KC_NO,KC_NO,KC_NO,KC_NO}, \
  { KC_NO,R35,  R34,  L32,  L31,  KC_NO,KC_NO, KC_NO,KC_NO,KC_NO,KC_NO}, \
  { CL,  ,KC_NO,KC_NO,KC_NO,KC_NO,CR,   KC_NO, KC_NO,KC_NO,KC_NO,KC_NO}, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, L13,  L23,  L33,  L43  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, L14,  L24,  L34,  L44  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, L15,  L25,  L35,  L45  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, R11,  R21,  R31,  R41  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, R12,  R22,  R32,  R42  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, R13,  R23,  R33,  R43  }, \
  { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, KC_NO,KC_NO,KC_NO,RE   } \
}
