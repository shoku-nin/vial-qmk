#pragma once

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// Defines the keycodes used by our macros in process_record_user

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define _qwert_L1_ LT(3,JP_Q),JP_W,JP_E,JP_R,JP_T
#define _qwert_L2_ JP_A,JP_S,JP_D,JP_F,JP_G
#define _qwert_L3_ LT(1,JP_Z),MT(MOD_LALT,JP_X),JP_C,MT(MOD_LSFT,JP_V),JP_B
#define _qwert_L4_ MT(MOD_LALT,JP_ZKHK),LT(2,KC_TAB),MT(MOD_LCTL,KC_SPC)

#define _qwert_R1_ JP_Y,JP_U,JP_I,JP_O,JP_P
#define _qwert_R2_ JP_H,JP_J,JP_K,JP_L,KC_BSPC
#define _qwert_R3_ JP_N,JP_M,MT(MOD_LSFT,JP_MINS),MT(MOD_LCTL,JP_COMM),LT(2,JP_DOT)
#define _qwert_R4_ KC_ENT,LT(1,KC_TAB),KC_DEL

#define _num_L1_ KC_TRNS,JP_CIRC,JP_TILD,JP_ASTR,JP_LBRC
#define _num_L2_ MT(MOD_LSFT,JP_AT),JP_SLSH,JP_UNDS,JP_COLN,JP_SCLN
#define _num_L3_ KC_TRNS,KC_LALT,JP_EQL,KC_LSFT,JP_RBRC
#define _num_L4_ KC_TRNS,KC_TRNS,C(KC_SPC)

#define _num_R1_ JP_7,JP_8,JP_9,JP_0,JP_PLUS
#define _num_R2_ JP_4,JP_5,JP_6,JP_YEN,KC_DEL
#define _num_R3_ JP_1,JP_2,JP_3,KC_TRNS,LT(3,JP_DOT)
#define _num_R4_ KC_TRNS,KC_TRNS,KC_RSFT

#define _ms_L1_ KC_TRNS,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_MS_WH_UP
#define _ms_L2_ XXXXXXX,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_APP
#define _ms_L3_ KC_TRNS,KC_LALT,KC_MS_BTN3,KC_LSFT,KC_MS_WH_DOWN
#define _ms_L4_ KC_TRNS,KC_TRNS,KC_TRNS

#define _ms_R1_ KC_PGUP,KC_WWW_BACK,KC_UP,KC_WWW_FORWARD,XXXXXXX
#define _ms_R2_ KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL
#define _ms_R3_ KC_PGDN,KC_HOME,KC_END,KC_RCTL,KC_TRNS
#define _ms_R4_ KC_TRNS,LT(3,KC_TAB),KC_RSFT

#define _func_L1_ KC_TRNS,KC_ESC,G(KC_E),G(KC_R),A(KC_F4)
#define _func_L2_ CW_TOGG,KC_INS,G(KC_D),KC_WWW_HOME,KC_LGUI
#define _func_L3_ JP_ZKHK,KC_LALT,KC_LCTL,KC_LSFT,A(KC_PSCR)
#define _func_L4_ KC_TRNS,KC_TRNS,KC_TRNS

#define _func_R1_ KC_F7,KC_F8,KC_F9,KC_F10,KC_F12
#define _func_R2_ KC_F4,KC_F5,KC_F6,KC_F11,XXXXXXX
#define _func_R3_ KC_F1,KC_F2,KC_F3,KC_RCTL,XXXXXXX
#define _func_R4_ KC_TRNS,KC_TRNS,KC_RSFT

