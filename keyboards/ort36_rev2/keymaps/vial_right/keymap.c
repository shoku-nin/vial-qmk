#include QMK_KEYBOARD_H
#include "quantum.h"
#include "wrappers_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_D,KC_BTN1,KC_WH_U,
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_D,KC_BTN1,KC_WH_U,
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_D,KC_BTN1,KC_WH_U,
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
KC_WH_U,KC_BTN1,KC_WH_D,    KC_WH_D,KC_BTN1,KC_WH_U,
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

#ifdef RGBLIGHT_ENABLE
static uint8_t layer = 0;

// Function to handle layer changes and disable hi-speed when not in AUTO_MOUSE_DEFAULT_LAYER

layer_state_t layer_state_set_user(layer_state_t state) {
//
// Disable hi-speed if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    layer = get_highest_layer(state);

    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
//  0  1
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 2, HSV_WHITE}
    {0, 2,   0,  0,200}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 2, HSV_BLUE}
    {0, 2, 150,255,200}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 2, HSV_MAGENTA}
    {0, 2, 245,255,160}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 2, HSV_YELLOW}
    {0, 2,  43,255,200}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_OFF}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,    // Overrides other layers
    my_layer5_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, is_caps_word_on());
    return true;
}
#endif
