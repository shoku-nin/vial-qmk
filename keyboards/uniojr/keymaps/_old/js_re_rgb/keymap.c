#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "wrappers_0.21.h"

#ifdef POINTING_DEVICE_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_layer(5);
    set_auto_mouse_enable(true);
}

enum custom_keycodes {
    SPD_LO = SAFE_RANGE,
    SPD_HI
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
KC_1,
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
_______,
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
_______,
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
_______,
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, KC_F11,KC_F2,KC_F3,KC_RCTL,TO(4),
_func_L4_, _func_R4_
),

[4] = LAYOUT(
_______,
TO(0),  KC_NO,  KC_NO,  KC_NO,  RGB_MOD,    RGB_MOD, KC_NO,  KC_NO,  KC_NO,  KC_NO,
RGB_HUI,RGB_SAI,RGB_SPI,RGB_VAI,RGB_RMOD,   RGB_RMOD,RGB_VAI,RGB_SPI,RGB_SAI,RGB_HUI,
RGB_HUD,RGB_SAD,RGB_SPD,RGB_VAD,RGB_TOG,    RGB_TOG, RGB_VAD,RGB_SPD,RGB_SAD,RGB_HUD,
                KC_NO,  KC_NO,  KC_NO,      KC_NO,   KC_NO,  KC_NO
),

[5] = LAYOUT(
_______,
KC_NO, KC_NO,KC_NO, KC_BTN2,KC_BTN1,  KC_BTN1,KC_BTN2,KC_NO, KC_NO,KC_NO,
KC_NO, KC_NO,KC_NO, KC_BTN2,KC_BTN1,  KC_BTN1,KC_BTN2,KC_NO, KC_NO,KC_NO,
SPD_LO,KC_NO,SPD_HI,KC_BTN2,KC_BTN1,  KC_BTN1,KC_BTN2,SPD_HI,KC_NO,SPD_LO,
             KC_NO, SPD_LO, KC_NO,    KC_NO,  SPD_LO, KC_NO
),

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
    if (layer != AUTO_MOUSE_DEFAULT_LAYER) {
        set_spd_hi = false;
        set_spd_lo = false;
    }
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
//  4  3  2  1  0   18 19 20 21 22
//  5  6  7  8  9   27 26 25 24 23
// 14 13 12 11 10   28 29 30 31 32
//       15 16 17   35 34 33
//
// my_capslock_layer
// ye wh wh wh wh   wh wh wh wh wh
// ye  6  7  8  9   27 26 25 24 23
// 14 13 12 11 10   28 29 30 31 32
//       15 16 17   35 34 33
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_WHITE},
    {4, 2, HSV_YELLOW},
    {18, 5, HSV_WHITE}
);
// my_layer1_layer
// wh  3  2  1  0   bl bl bl bl 22
//  5  6  7  8  9   bl bl bl 24 23
// -- 13 12 11 10   bl bl bl 31 32
//       15 wh 17   35 -- 33
//
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_WHITE},   {14, 1, HSV_OFF},
    {16, 1, HSV_WHITE},
//
    {18, 4, HSV_BLUE},   {25, 6, HSV_BLUE},
    {32, 1, HSV_WHITE},  {34, 1, HSV_OFF}
);
// my_layer2_layer
// wh pi gr pi  0   18 pi gr pi 22
//  5 gr gr gr  9   27 gr gr gr 23
// wh 13 pi 11 10   28 29 30 31 --
//       15 -- 17   35 wh 33
//
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_PINK},   {2, 1, HSV_GREEN},
    {3, 1, HSV_PINK},   {4, 1, HSV_WHITE},
    {6, 3, HSV_GREEN},  {12, 1, HSV_PINK},
    {14, 1, HSV_WHITE}, {16, 1, HSV_OFF},
//
    {19, 1, HSV_PINK},  {20, 1, HSV_GREEN},
    {21, 1, HSV_PINK},  {24, 3, HSV_GREEN},
    {32, 1, HSV_OFF},   {34, 1, HSV_WHITE}
);
// my_layer3_layer
// --  3  2  1  0   re re re re 22
//  5 --  7  8  9   re re re gr --
// 14 13 12 11 10   re re re -- wh
//       15 16 17   35 34 33
//
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_OFF},    {6, 1, HSV_OFF},
//
    {18, 4, HSV_RED},   {23, 1, HSV_OFF},
    {24, 1, HSV_GREEN}, {25, 6, HSV_RED},
    {31, 1, HSV_OFF},   {32, 1, HSV_WHITE}
);
// my_layer4_layer
//  4  3  2  1  0   18 19 20 21 22
//  5  6  7  8  9   27 26 25 24 23
// 14 13 12 11 10   28 29 30 31 32
//       bl bl bl   bl bl bl
//
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {15, 3, HSV_BLUE},  {33, 3, HSV_BLUE}
);
// RGBLIGHT_LAYER_SEGMENTS
// -- -- -- bl re   re bl -- -- --
// -- -- -- bl re   re bl -- -- --
// gr -- wh bl re   re bl wh -- gr
//       -- gr --   -- gr --
//
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},    {1, 1, HSV_BLUE},
    {2, 6, HSV_OFF},    {8, 1, HSV_BLUE},
    {9, 2, HSV_RED},    {11, 1, HSV_BLUE},
    {12, 1, HSV_WHITE}, {13, 3, HSV_OFF},
    {14, 1, HSV_GREEN}, {15, 1, HSV_OFF},
    {16, 1, HSV_GREEN}, {17, 1, HSV_OFF},
//
    {18, 1, HSV_RED},   {19, 1, HSV_BLUE},
    {20, 6, HSV_OFF},   {26, 1, HSV_BLUE},
    {27, 2, HSV_RED},   {29, 1, HSV_BLUE},
    {30, 1, HSV_WHITE}, {31, 1, HSV_OFF},
    {32, 1, HSV_GREEN}, {33, 1, HSV_OFF},
    {34, 1, HSV_GREEN}, {35, 1, HSV_OFF}
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
    spd_multi = 0.4;
  } else if (set_spd_hi){
    spd_multi = 2;
  } else {
    spd_multi = 1;
  }
  // Calculate and accumulate cursor values based on mouse movement and divisors
  cursor_accumulated_x += (float)mouse_report.x * spd_multi / CURSOR_DIV;
  cursor_accumulated_y += (float)mouse_report.y * spd_multi / CURSOR_DIV;

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
        case SPD_HI:
            set_spd_hi = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[1] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[2] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[3] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[4] = {ENCODER_CCW_CW(RGB_RMOD,RGB_MOD)},
[5] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
};
#endif
