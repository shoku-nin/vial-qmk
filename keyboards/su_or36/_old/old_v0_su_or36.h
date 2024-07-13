.#pragma once

#include "quantum.h"

/*
#define MATRIX_ROWS 3*2  //master: 3 rows, slave: 3 rows
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D1, D0, D4 }  // A,B,C
#define MATRIX_COL_PINS { F6, F7, B1, F6, F7, B1 }  // 1,2,3

[left]
A2 A1 A3 A2 A1
B2 B1 B3 B2 B1
C2 C1 C3 C2 C1
      A3 B3 C3

[right]
A1 A2 A3 A1 A2
B1 B2 B3 B1 B2
C1 C2 C3 C1 C2
C3 B3 A3
*/

#define LAYOUT( \
  L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35, \
            L43, L44, L45,   R41, R42, R43 \
) \
{ \
  { L12, L11, L43, L15, L14, L13 }, \
  { L22, L21, L44, L25, L24, L23 }, \
  { L32, L31, L45, L35, L34, L33 }, \
  { R11, R12, R13, R14, R15, R43 }, \
  { R21, R22, R23, R24, R25, R42 }, \
  { R31, R32, R33, R34, R35, R41 } \
}
