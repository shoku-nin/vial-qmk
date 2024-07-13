#include QMK_KEYBOARD_H
#include "quantum.h"
#include "wrappers_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_U,KC_BTN1,KC_WH_D,
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_U,KC_BTN1,KC_WH_D,
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_U,KC_BTN1,KC_WH_D,
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_U,KC_BTN1,KC_WH_D,
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, _func_R3_,
_func_L4_, _func_R4_
),

[4] = LAYOUT(
_______,_______,_______,    _______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
                _______,_______,_______,    _______,_______,_______
),

[5] = LAYOUT(
_______,_______,_______,    _______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,
                _______,_______,_______,    _______,_______,_______
),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
