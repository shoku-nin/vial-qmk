#pragma once

#include "quantum.h"

/*
#define MATRIX_ROWS 3
#define MATRIX_COLS 3*2

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
  R11, R12, R13, R14, R15, \
  R21, R22, R23, R24, R25, \
  R31, R32, R33, R34, R35, \
  R41, R42, R43 \
) \
{ \
  { R11, R12, R13, R14, R15, R43 }, \
  { R21, R22, R23, R24, R25, R42 }, \
  { R31, R32, R33, R34, R35, R41 } \
}
