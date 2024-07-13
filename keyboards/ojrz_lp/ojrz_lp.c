#include "ojrz_lp.h"

/*
"matrix_pins": {
    "rows": ["GP3","GP4","GP5","GP6","GP7","GP8","GP14"],
    "cols": ["GP7","GP8","GP14",     "GP3","GP4","GP5","GP6","GP15"]
},
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b10000111,
  0b10000111,
  0b10000111,
  0b10000111,
  0b01111000,
  0b01111000,
  0b01111000,
  0b10000111,
  0b10000111,
  0b10000111,
  0b10000111,
  0b01111000,
  0b01111000,
  0b01111000,
};
