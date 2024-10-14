#include "ort36_rev14_1.h"

/*
"matrix_pins": {
"rows": [
    "GP26","GP27","GP15",
    "GP5","GP4", "GP3","GP2"
],
"cols": [
    "GP5","GP4", "GP3","GP2",
    "GP26","GP27","GP15"
]
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
