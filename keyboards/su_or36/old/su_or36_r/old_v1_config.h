/*
Copyright 2023 shoku_nin

このキーボードは、狭ピッチ自作キーボード基板「su120」を活用しています。

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7724
#define PRODUCT_ID      0x4710
#define DEVICE_VER      0x0013
#define MANUFACTURER    shoku_nin
#define PRODUCT         su_or36_r
#define DESCRIPTION     ortho 3x5 + 3 staggerd thumb keys(right half)

/* key matrix size */
//#define MATRIX_ROWS 3*2  //master: 3 rows, slave: 3 rows
#define MATRIX_ROWS 3*2
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { F6, F7, B1, F6, F7, B1 }  // 1,2,3
#define MATRIX_COL_PINS { D1, D0, D4 }  // A,B,C

//#define MATRIX_ROW_PINS { D1, D0, D4 }  // A,B,C
//#define MATRIX_COL_PINS { F6, F7, B1, F6, F7, B1 }  // 1,2,3

/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION ROW2COL
//#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
//#define SOFT_SERIAL_PIN D2 // or D1, D2, D3, E6

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0

