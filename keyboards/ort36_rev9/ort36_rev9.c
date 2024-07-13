#include "ort36_rev9.h"

/*
"matrix_pins": {
    "rows": ["GP15","GP12","GP10","GP14","GP13","GP9" ],
    "cols": ["GP14","GP13","GP9", "GP15","GP12","GP10"]
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
