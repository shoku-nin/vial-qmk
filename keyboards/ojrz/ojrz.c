#include "ojrz.h"

/*
    "matrix_pins": {
        "rows": ["GP5", "GP4", "GP3", "GP8", "GP7", "GP6"],
        "cols": ["GP8", "GP7", "GP6", "GP5", "GP4", "GP3"]
    },
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b00000111,
  0b00000111,
  0b00000111,
  0b00111000,
  0b00111000,
  0b00111000,
  0b00000111,
  0b00000111,
  0b00000111,
  0b00111000,
  0b00111000,
  0b00111000,
};
