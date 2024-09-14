#include QMK_KEYBOARD_H
#include "quantum.h"
#include "wrappers_keymap.h"

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
_func_L3_, KC_F1,KC_F2,KC_F3,KC_RCTL,TO(4),
_func_L4_, _func_R4_
),

/*
[4] = LAYOUT(
TO(0),  KC_NO,  KC_NO,  KC_NO,  RGB_TOG,  RGB_TOG, KC_NO,  KC_NO,  KC_NO,  KC_NO,
RGB_HUI,RGB_SAI,RGB_SPI,RGB_VAI,RGB_MOD,  RGB_MOD, RGB_VAI,RGB_SPI,RGB_SAI,RGB_HUI,
RGB_HUD,RGB_SAD,RGB_SPD,RGB_VAD,RGB_RMOD, RGB_RMOD,RGB_VAD,RGB_SPD,RGB_SAD,RGB_HUD,
                KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,  KC_NO
),

[5] = LAYOUT(
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______
),
*/

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

bool set_spd_hi = false;
bool set_spd_lo = false;
static uint8_t layer = 0;

// Function to handle layer changes and disable hi-speed when not in AUTO_MOUSE_DEFAULT_LAYER

layer_state_t layer_state_set_user(layer_state_t state) {
//
// Disable hi-speed if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    layer = get_highest_layer(state);

    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
//    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
// 18 17 16 15 14       33 34 35 36 37
//  9 10 11 12 13       32 31 30 29 28
//  8  7  6  5  4  3 22 23 24 25 26 27
//        0  1  2       21 20 19
//
// my_capslock_layer
// ye wh wh wh wh       wh wh wh wh wh
// ye 10 11 12 13       32 31 30 29 28
//  8  7  6  5  4 wh wh 23 24 25 26 27
//        0  1  2       21 20 19
//
//    {0, 2, HSV_WHITE}
//    {0, 2,   0,  0,200}
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_WHITE},
    {22, 1, HSV_WHITE}
);
// my_layer1_layer
// wh 17 16 15 14       bl bl bl bl 37
//  9 10 11 12 13       bl bl bl 29 28
// --  7  6  5  4 bl bl bl bl bl 26 27
//        0 wh  2       21 -- 19
//
//    {0, 2, HSV_BLUE}
//    {0, 2, 150,255,200}
//
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_BLUE},
    {22, 1, HSV_BLUE}
);
// my_layer2_layer
// wh pi gr pi 14       33 pi gr pi 37
//  9 gr gr gr 13       32 gr gr gr 28
//  8  7 pi  5  4 mg mg 23 24 25 26 --
//        0 --  2       21 wh 19
//
//    {0, 2, HSV_MAGENTA}
//    {0, 2, 245,255,160}
//
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_MAGENTA},
    {22, 1, HSV_MAGENTA}
);
// my_layer3_layer
// -- 17 16 15 14       mg mg mg mg mg
//  9 10 11 12 13       mg mg mg mg --
//  8  7  6  5  4 ye ye mg mg mg -- wh
//        0  1  2       21 20 19
//
//    {0, 2, HSV_YELLOW}
//    {0, 2,  43,255,200}
//
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_YELLOW},
    {22, 1, HSV_YELLOW}
);
// my_layer4_layer
// 18 17 16 15 14       33 34 35 36 37
//  9 10 11 12 13       32 31 30 29 28
//  8  7  6  5  4 bl ye 23 24 25 26 27
//        0  1  2       21 20 19
//

/*
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_BLUE},
    {22, 1, HSV_YELLOW}
);
// 18 17 16 15 14       33 34 35 36 37
//  9 10 11 12 13       32 31 30 29 28
//  8  7  6  5  4  3 22 23 24 25 26 27
//        0  1  2       21 20 19
// my_layer5_layer
// -- -- -- -- --       re bl -- -- --
// -- -- -- -- --       re bl -- -- --
// gr -- wh -- -- -- -- re bl wh -- --
//       -- -- --       -- gr --
//
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  3, HSV_OFF},
    {3,  1, HSV_OFF},
    {4,  2, HSV_OFF},   {6,  1, HSV_WHITE},
    {7,  1, HSV_OFF},   {8,  1, HSV_GREEN},
    {9, 10, HSV_OFF},
//
    {19, 1, HSV_OFF},   {20, 1, HSV_GREEN},
    {21, 1, HSV_OFF},
    {22, 1, HSV_OFF},
    {23, 1, HSV_RED},   {24, 1, HSV_BLUE},
    {25, 1, HSV_WHITE}, {26, 5, HSV_OFF},
    {31, 1, HSV_BLUE},  {32, 2, HSV_RED},
    {34, 1, HSV_BLUE},  {35, 3, HSV_OFF}
);
*/


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
//    my_layer3_layer,    // Overrides other layers
//    my_layer4_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, is_caps_word_on());
    return true;
}
