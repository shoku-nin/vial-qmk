/*
Copyright 2023 shoku_nin

このキーボードは、狭ピッチ自作キーボード基板「su120」を活用しています。

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { GP29,GP28,GP27,GP26,GP15 }  // 1,2,3,4,5
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { GP1,GP2,GP3,GP4 }  // A,B,C,D

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN GP7

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

