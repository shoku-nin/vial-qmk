#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user

// Defines the keycodes used by our macros in process_record_user

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define _test_L1_ KC_Q,KC_W,KC_E,KC_R,KC_T
#define _test_L2_ KC_A,KC_S,KC_D,KC_F,KC_G
#define _test_L3_ KC_Z,KC_X,KC_C,KC_V,KC_B
#define _test_L4_ KC_1,KC_2,KC_3

#define _test_R1_ KC_Y,KC_U,KC_I,KC_O,KC_P
#define _test_R2_ KC_H,KC_J,KC_K,KC_L,KC_4
#define _test_R3_ KC_N,KC_M,KC_MINS,KC_COMM,KC_DOT
#define _test_R4_ KC_5,KC_6,KC_7


#define _qwert_L1_ LT(3,KC_Q),KC_W,KC_E,KC_R,KC_T
#define _qwert_L2_ KC_A,KC_S,KC_D,LT(4,KC_F),KC_G
#define _qwert_L3_ LT(1,KC_Z),MT(MOD_LALT,KC_X),KC_C,MT(MOD_LSFT,KC_V),KC_B
#define _qwert_L4_ MT(MOD_LALT,KC_GRV),LT(2,KC_TAB),MT(MOD_LCTL,KC_SPC)

#define _qwert_R1_ KC_Y,KC_U,KC_I,KC_O,KC_P
#define _qwert_R2_ KC_H,LT(4,KC_J),KC_K,LT(1,KC_L),KC_BSPC
#define _qwert_R3_ KC_N,KC_M,MT(MOD_LSFT,KC_MINS),MT(MOD_LCTL,KC_COMM),LT(2,KC_DOT)
#define _qwert_R4_ KC_ENT,LT(1,KC_TAB),KC_DEL

#define _num_L1_ KC_QUES,KC_EQL,KC_PLUS,KC_DQUO,KC_RBRC
#define _num_L2_ MT(MOD_LSFT,KC_LBRC),KC_SLSH,S(KC_RO),KC_QUOT,KC_SCLN
#define _num_L3_ KC_TRNS,KC_LALT,KC_UNDS,KC_LSFT,KC_BSLS
#define _num_L4_ KC_TRNS,KC_TRNS,KC_TRNS

#define _num_R1_ KC_7,KC_8,KC_9,KC_0,KC_COLN
#define _num_R2_ KC_4,KC_5,KC_6,LT(1,KC_JYEN),KC_DEL
#define _num_R3_ KC_1,KC_2,KC_3,KC_TRNS,KC_DOT
#define _num_R4_ KC_TRNS,KC_TRNS,KC_RSFT

#define _ms_L1_ _______,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_MS_WH_UP
#define _ms_L2_ KC_TAB,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_LGUI
#define _ms_L3_ KC_LCTL,KC_LALT,KC_MS_BTN3,KC_LSFT,KC_MS_WH_DOWN
#define _ms_L4_ KC_TRNS,KC_TRNS,KC_TRNS

#define _ms_R1_ KC_PGUP,KC_WWW_BACK,KC_UP,KC_WWW_FORWARD,_______
#define _ms_R2_ KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL
#define _ms_R3_ KC_PGDN,KC_HOME,KC_END,KC_RCTL,KC_TRNS
#define _ms_R4_ KC_TRNS,KC_TRNS,KC_RSFT

#define _func_L1_ KC_TRNS,KC_ESC,G(KC_E),G(KC_R),A(KC_F4)
#define _func_L2_ KC_TAB,_______,G(KC_D),KC_WWW_HOME,KC_APP
#define _func_L3_ KC_GRV,KC_LALT,KC_LCTL,KC_LSFT,A(KC_PSCR)
#define _func_L4_ KC_TRNS,KC_TRNS,KC_TRNS

#define _func_R1_ KC_F7,KC_F8,KC_F9,KC_F10,KC_F12
#define _func_R2_ KC_F4,KC_F5,KC_F6,G(KC_L),_______
#define _func_R3_ KC_F11,KC_F2,KC_F3,KC_RCTL,_______
#define _func_R4_ KC_TRNS,KC_TRNS,KC_RSFT



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, _func_R3_,
_func_L4_, _func_R4_
),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
