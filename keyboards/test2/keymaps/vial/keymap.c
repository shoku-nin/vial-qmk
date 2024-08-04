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
    SPD_HI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_wrapper(
TO(6),TO(4),
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
TO(6),TO(4),
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
TO(6),TO(4),
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
TO(6),TO(4),
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, KC_F1,KC_F2,KC_F3,KC_RCTL,TO(4),
_func_L4_, _func_R4_
),

[4] = LAYOUT(
TO(6),TO(4),
TO(0),  KC_NO,KC_NO,KC_NO,RGB_TOG,  RGB_TOG, KC_NO,KC_NO,KC_NO,KC_NO,
RGB_HUI,RGB_SAI,RGB_SPI,RGB_VAI,RGB_MOD,  RGB_MOD, RGB_VAI,RGB_SPI,RGB_SAI,RGB_HUI,
RGB_HUD,RGB_SAD,RGB_SPD,RGB_VAD,RGB_RMOD, RGB_RMOD,RGB_VAD,RGB_SPD,RGB_SAD,RGB_HUD,
                KC_NO,KC_NO,KC_NO,  KC_NO, KC_NO,KC_NO
),

[5] = LAYOUT(
KC_BTN1,TO(0),
_______,_______,_______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,_______,_______,
_______,_______,_______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,_______,_______,
SPD_LO, SPD_HI, _______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,SPD_LO, SPD_HI,
                _______,_______,_______,    _______,_______,_______
),

[6] = LAYOUT(
TO(0),TO(0),
_______,_______,_______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,_______,_______,
_______,_______,_______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,_______,_______,
SPD_LO, SPD_HI, _______,KC_BTN1,_______,    KC_BTN1,KC_BTN2,_______,SPD_LO, SPD_HI,
                _______,_______,_______,    _______,_______,_______
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

#ifdef POINTING_DEVICE_ENABLE
    if (layer != AUTO_MOUSE_DEFAULT_LAYER) {
        set_spd_hi = false;
        set_spd_lo = false;
    }
#endif

/*
    if (layer != 0) {
        set_spd_hi = false;
        set_spd_lo = true;
    }
*/
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20
//
// my_capslock_layer
// ye wh wh wh wh    wh    wh wh wh wh wh
// ye 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5 wh    wh 24 25 26 27 28
//        1  2  3          22 21 20
//
//    {0, 2, HSV_WHITE}
//    {0, 2,   0,  0,200}
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_WHITE},
    {4,  1, HSV_WHITE},
    {10, 1, HSV_YELLOW},
    {15, 4, HSV_WHITE},    {19, 1, HSV_YELLOW},
//
    {23, 1, HSV_WHITE},
    {34, 5, HSV_WHITE}
);
// my_layer1_layer
// wh 18 17 16 15    bl    bl bl bl bl 38
// 10 11 12 13 14          bl bl bl 30 29
// --  8  7  6  5 bl    bl bl bl bl 27 28
//        1 wh  3          22 -- 20
//
//    {0, 2, HSV_BLUE}
//    {0, 2, 150,255,200}
//
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_BLUE},
    {2,  1, HSV_WHITE},
    {4,  1, HSV_BLUE},
    {9,  1, HSV_OFF},   {19, 1, HSV_WHITE},
//
    {21, 1, HSV_OFF},
    {23, 1, HSV_BLUE},
    {24, 3, HSV_BLUE},  {31, 7, HSV_BLUE}
);
// my_layer2_layer
// wh pi gr pi 15    mg    34 pi gr pi 38
// 10 gr gr gr 14          33 gr gr gr 29
//  9  8 pi  6  5 mg    mg 24 25 26 27 --
//        1 --  3          22 wh 20
//
//    {0, 2, HSV_MAGENTA}
//    {0, 2, 245,255,160}
//
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_MAGENTA},
    {2,  1, HSV_OFF},
    {4,  1, HSV_MAGENTA},
    {7,  1, HSV_PINK},  {11,  3, HSV_GREEN},
    {16, 1, HSV_PINK},  {17, 1, HSV_GREEN},
    {18, 1, HSV_PINK},  {19, 1, HSV_WHITE},
//
    {21, 1, HSV_WHITE},
    {23, 1, HSV_MAGENTA},
    {28, 1, HSV_OFF},   {30, 3, HSV_GREEN},
    {35, 1, HSV_PINK},  {36, 1, HSV_GREEN},
    {37, 1, HSV_PINK}
);
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20
// my_layer3_layer
// -- 18 17 16 15    ye    mg mg mg mg mg
// 10 11 12 13 14          mg mg mg mg --
//  9  8  7  6  5 ye    ye mg mg mg -- wh
//        1  2  3          22 21 20
//
//    {0, 2, HSV_YELLOW}
//    {0, 2,  43,255,200}
//
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_YELLOW},
    {4,  1, HSV_YELLOW},
    {19, 1, HSV_OFF},
//
    {23, 1, HSV_YELLOW},
    {24, 3, HSV_MAGENTA},
    {27, 1, HSV_OFF},   {28, 1, HSV_WHITE},
    {29, 1, HSV_OFF},   {30, 9, HSV_MAGENTA}
);
// my_layer4_layer
// 19 18 17 16 15    re    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5 bl    ye 24 25 26 27 28
//        1  2  3          22 21 20
//
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
    {4,  1, HSV_BLUE},
    {23, 1, HSV_YELLOW}
);
// 19 18 17 16 15     0    34 35 36 37 38
// 10 11 12 13 14          33 32 31 30 29
//  9  8  7  6  5  4    23 24 25 26 27 28
//        1  2  3          22 21 20
// my_layer5_layer
// -- -- -- re --    re    re bl -- -- --
// -- -- -- re --          re bl -- -- --
// gr cy -- re -- cy    cy re bl -- gr cy
//       -- -- --          -- re --
//
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_RED},   {1,  3, HSV_OFF},
    {4,  1, HSV_CYAN},  {5,  1, HSV_OFF},
    {6,  1, HSV_RED},   {7,  1, HSV_OFF},
    {8,  1, HSV_CYAN},  {9,  1, HSV_GREEN},
    {10, 3, HSV_OFF},   {13, 1, HSV_RED},
    {14, 2, HSV_OFF},   {16, 1, HSV_RED},
    {17, 3, HSV_OFF},
//
    {20, 1, HSV_OFF},
    {21, 1, HSV_RED},    {22, 1, HSV_OFF},
    {23, 1, HSV_CYAN},
    {24, 1, HSV_RED},   {25, 1, HSV_BLUE},
    {26, 1, HSV_OFF},   {27, 1, HSV_GREEN},
    {28, 1, HSV_CYAN},  {29, 3, HSV_OFF},
    {32, 1, HSV_BLUE},  {33, 2, HSV_RED},
    {35, 1, HSV_BLUE},  {36, 3, HSV_OFF}
);

const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_RED},   {1,  3, HSV_OFF},
    {4,  1, HSV_CYAN},  {5,  1, HSV_OFF},
    {6,  1, HSV_RED},   {7,  1, HSV_OFF},
    {8,  1, HSV_CYAN},  {9,  1, HSV_GREEN},
    {10, 3, HSV_OFF},   {13, 1, HSV_RED},
    {14, 2, HSV_OFF},   {16, 1, HSV_RED},
    {17, 3, HSV_OFF},
//
    {20, 1, HSV_OFF},
    {21, 1, HSV_RED},    {22, 1, HSV_OFF},
    {23, 1, HSV_CYAN},
    {24, 1, HSV_RED},   {25, 1, HSV_BLUE},
    {26, 1, HSV_OFF},   {27, 1, HSV_GREEN},
    {28, 1, HSV_CYAN},  {29, 3, HSV_OFF},
    {32, 1, HSV_BLUE},  {33, 2, HSV_RED},
    {35, 1, HSV_BLUE},  {36, 3, HSV_OFF}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,    // Overrides other layers
    my_layer5_layer,     // Overrides other layers
    my_layer6_layer     // Overrides other layers
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
    spd_multi = 0.5;
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
[0] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[1] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[2] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[3] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[4] = {ENCODER_CCW_CW(RGB_MOD,RGB_RMOD)},
[5] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[6] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
};
#endif
