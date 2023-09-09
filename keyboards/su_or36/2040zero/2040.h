// Copyright 2022 @geigeigeist
// SPDX-License-Identifier: GPL-2.0+

#pragma once

/*
"rows": [    "GP29","GP28","GP27","GP26","GP15",    ],
"cols": [    "GP1","GP2","GP3","GP4",    ]

[left]
A5 A4 A3 A2 A1
B5 B4 B3 B2 B1
C5 C4 C3 C2 C1
      D3 D2 D1

[right]
C1 C2 C3 C4 C5
B1 B2 B3 B4 B5
A1 A2 A3 A4 A5
D1 D2 D3
*/

#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L15, L25, L35, L45 }, \
  { L14, L24, L34, L44 }, \
  { L13, L23, L33, L43 }, \
  { L12, L22, L32, KC_NO }, \
  { L11, L21, L31, KC_NO }, \
  { R31, R21, R11, R41 }, \
  { R32, R22, R12, R42 }, \
  { R33, R23, R13, R43 }, \
  { R34, R24, R14, KC_NO }, \
  { R35, R25, R15, KC_NO } \
}
