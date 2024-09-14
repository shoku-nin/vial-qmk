#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "wrappers_keymap.h"

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(5);
    set_auto_mouse_enable(true);
}
#endif

enum custom_keycodes {
    SPD_LO = SAFE_RANGE,
    SPD_MID,
    SPD_HI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

[1] = LAYOUT_wrapper(
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

[2] = LAYOUT_wrapper(
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

[3] = LAYOUT_wrapper(
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, KC_F1,KC_F2,KC_F3,KC_RCTL,TO(4),
_func_L4_, _func_R4_,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

[4] = LAYOUT(
TO(0),  KC_NO,  KC_NO,  KC_NO,  RGB_TOG,  RGB_TOG, KC_NO,  KC_NO,  KC_NO,  KC_NO,
RGB_HUI,RGB_SAI,RGB_SPI,RGB_VAI,RGB_MOD,  RGB_MOD, RGB_VAI,RGB_SPI,RGB_SAI,RGB_HUI,
RGB_HUD,RGB_SAD,RGB_SPD,RGB_VAD,RGB_RMOD, RGB_RMOD,RGB_VAD,RGB_SPD,RGB_SAD,RGB_HUD,
                KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,  KC_NO,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

[5] = LAYOUT(
_______,_______,_______,_______,_______, KC_BTN1,KC_BTN2,_______,_______,_______,
_______,_______,_______,_______,_______, KC_BTN1,KC_BTN2,_______,_______,_______,
SPD_LO, SPD_MID,SPD_HI, _______,_______, KC_BTN1,KC_BTN2,SPD_LO, SPD_MID,SPD_HI,
                _______,_______,_______,    _______,_______,_______,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN,
KC_MS_WH_UP,KC_MS_BTN3,KC_MS_WH_DOWN
),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

bool set_spd_lo = false;
bool set_spd_mid = false;
bool set_spd_hi = false;
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
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
//
// my_capslock_layer
//    {0, 2, HSV_WHITE}
//    {0, 2,   0,  0,200}
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_WHITE},
    {15, 1, HSV_WHITE}
//    {0, 3,   0,  0,200}
);
// my_layer1_layer
//    {0, 2, HSV_BLUE}
//    {0, 2, 150,255,200}
//
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_BLUE},
    {15, 1, HSV_BLUE}
//    {0, 3, 150,255,200}
);
// my_layer2_layer
//    {0, 2, HSV_MAGENTA}
//    {0, 2, 245,255,160}
//
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_MAGENTA},
    {15, 1, HSV_MAGENTA}
//    {0, 3, 245,255,160}
);
// my_layer3_layer
//    {0, 2, HSV_YELLOW}
//    {0, 2,  43,255,200}
//
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_YELLOW},
    {15, 1, HSV_YELLOW}
//    {0, 3,  43,255,200}
);
// my_layer4_layer
//
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_PINK},
    {15, 1, HSV_PINK}
);
// my_layer5_layer
//
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,  1, HSV_RED},
    {15, 1, HSV_RED}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,     // Overrides other layers
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

#ifdef POINTING_DEVICE_ENABLE

// Modify these values to adjust the scrolling speed
#define CURSOR_DIV    1

// Variables to store accumulated values
float cursor_accumulated_x = 0;
float cursor_accumulated_y = 0;
float spd_multi = 1;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  // Check if drag scrolling is active
  if (set_spd_lo) {
    spd_multi = 0.3;
  } else if (set_spd_mid){
    spd_multi = 0.7;
  } else if (set_spd_hi){
    spd_multi = 3;
  } else {
    spd_multi = 1;
  }
  // Calculate and accumulate cursor values based on mouse movement and divisors
  cursor_accumulated_x += (float)mouse_report.x * spd_multi * 1 / CURSOR_DIV;
  cursor_accumulated_y += (float)mouse_report.y * spd_multi * (-1) / CURSOR_DIV;

  // Assign integer parts of accumulated cursor values to the mouse report
    mouse_report.x = (int8_t)cursor_accumulated_x;
    mouse_report.y = (int8_t)cursor_accumulated_y;

  // Update accumulated cursor values by subtracting the integer parts
    cursor_accumulated_x -= (int8_t)cursor_accumulated_x;
    cursor_accumulated_y -= (int8_t)cursor_accumulated_y;

    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPD_LO:
            set_spd_lo = record->event.pressed;
            break;
        case SPD_MID:
            set_spd_mid = record->event.pressed;
            break;
        case SPD_HI:
            set_spd_hi = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}
#endif
