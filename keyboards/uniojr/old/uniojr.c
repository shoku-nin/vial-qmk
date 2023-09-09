#include "uniojr.h"

/*
        "rows": [
            "GP8", "GP21","GP22","GP9", "GP10","GP11",
            "GP18","GP19","GP20","GP5"
        ],
        "cols": [
            "GP8", "GP21","GP22","GP9", "GP10","GP11",
            "GP18","GP19","GP20","GP5"
        ]

left rows:   "GP18","GP19","GP20"
left cols:   "GP8", "GP21","GP22"

right rows:  "GP18","GP19","GP20"
right cols:  "GP9", "GP10","GP11"

center rows: "GP5"
center cols: "GP8", "GP21","GP22","GP9", "GP10","GP11"

*/

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
//  543210987654321
  0b000001111111110,
  0b000001111111101,
  0b000001111111011,
  0b000001111110111,
  0b000001111101111,
  0b000001111011111,
  0b000001110111111,
  0b000001101111111,
  0b000001011111111,
  0b000000111111111,
};
