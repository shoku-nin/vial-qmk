#include "ort36_rev11_8.h"

/*
"matrix_pins": {
    "rows": ["GP27","GP14","GP10","GP4", "GP26","GP15","GP9"],
    "cols": ["GP26","GP15","GP9",        "GP27","GP14","GP10","GP4"]
},
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b00001111,
  0b00001111,
  0b00001111,
  0b01110000,
  0b01110000,
  0b01110000,
  0b01110000,
  0b00001111,
  0b00001111,
  0b00001111,
  0b01110000,
  0b01110000,
  0b01110000,
  0b01110000,
};
