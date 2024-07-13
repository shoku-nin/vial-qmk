#include "uniojr_flat.h"

/*
"rows": [
    "GP2", "GP3", "GP4", "GP1",
    "GP23","GP20","GP21","GP7","GP6","GP5","GP22"
],
"cols": [
    "GP23","GP20","GP21","GP7","GP6","GP5","GP22",
    "GP2", "GP3", "GP4", "GP1"
]

left rows:
left cols:

right rows:
right cols:
*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
//  10987654321
  0b00001111111,
  0b00001111111,
  0b00001111111,
  0b00001111111,
  0b11110000000,
  0b11110000000,
  0b11110000000,
  0b11110000000,
  0b11110000000,
  0b11110000000,
  0b11110000000,
};
