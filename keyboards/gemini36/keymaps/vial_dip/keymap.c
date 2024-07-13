#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "wrappers_keymap.h"

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
TO(4),_______,
_qwert_L1_, _qwert_R1_,
_qwert_L2_, _qwert_R2_,
_qwert_L3_, _qwert_R3_,
_qwert_L4_, _qwert_R4_
),

[1] = LAYOUT_wrapper(
TO(4),_______,
_num_L1_, _num_R1_,
_num_L2_, _num_R2_,
_num_L3_, _num_R3_,
_num_L4_, _num_R4_
),

[2] = LAYOUT_wrapper(
TO(4),_______,
_ms_L1_, _ms_R1_,
_ms_L2_, _ms_R2_,
_ms_L3_, _ms_R3_,
_ms_L4_, _ms_R4_
),

[3] = LAYOUT_wrapper(
TO(4),_______,
_func_L1_, _func_R1_,
_func_L2_, _func_R2_,
_func_L3_, KC_F1,KC_F2,KC_F3,KC_RCTL,TO(4),
_func_L4_, _func_R4_
),

[4] = LAYOUT(
TO(0),_______,
TO(0),  KC_NO,  KC_NO,  KC_NO,  RGB_TOG,    RGB_TOG, KC_NO,  KC_NO,  KC_NO,  KC_NO,
RGB_HUI,RGB_SAI,RGB_SPI,RGB_VAI,RGB_MOD,    RGB_MOD,RGB_VAI,RGB_SPI,RGB_SAI,RGB_HUI,
RGB_HUD,RGB_SAD,RGB_SPD,RGB_VAD,RGB_RMOD,   RGB_RMOD, RGB_VAD,RGB_SPD,RGB_SAD,RGB_HUD,
                KC_NO,  KC_NO,  KC_NO,      KC_NO,   KC_NO,  KC_NO
),

[5] = LAYOUT(
_______,_______,
KC_NO, KC_NO,KC_NO, KC_NO ,KC_NO,  KC_BTN1,KC_BTN2,KC_NO, KC_NO,KC_NO,
KC_NO, KC_NO,KC_NO, KC_NO ,KC_NO,  KC_BTN1,KC_BTN2,KC_NO, KC_NO,KC_NO,
SPD_LO,KC_NO,SPD_HI,KC_NO ,KC_NO,  KC_BTN1,KC_BTN2,SPD_HI,KC_NO,SPD_LO,
             KC_NO, SPD_LO,KC_NO,  KC_NO,  SPD_LO, KC_NO
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
    return state;
}

// RGBLIGHT_LAYER_SEGMENTS
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// my_capslock_layer
// ye wh wh wh wh   wh wh wh wh wh
// ye  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,  1, HSV_YELLOW},{13, 4, HSV_WHITE},
    {17, 1, HSV_YELLOW},{31, 5, HSV_WHITE}
);
// my_layer1_layer
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// wh 16 15 14 13   bl bl bl bl 35
//  8  9 10 11 12   bl bl bl 27 26
// --  6  5  4  3   bl bl bl 24 25
//       pi wh pi   pi -- pi
//
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_PINK},  {1,  1, HSV_WHITE},
    {2,  1, HSV_PINK},
    {7,  1, HSV_OFF},   {17, 1, HSV_WHITE},
//
    {18, 1, HSV_PINK},  {19, 1, HSV_OFF},
    {20, 1, HSV_PINK},
    {21, 3, HSV_BLUE},  {28, 7, HSV_BLUE}
);
// my_layer2_layer
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// wh pi gr pi 13   31 pi gr pi 35
//  8 gr gr gr 12   30 gr gr gr 26
// wh  6 pi  4  3   21 22 23 24 --
//       bl -- bl   bl wh bl
//
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_BLUE},  {1,  1, HSV_OFF},
    {2,  1, HSV_BLUE},
    {5,  1, HSV_PINK},  {7,  1, HSV_WHITE},
    {9,  3, HSV_GREEN}, {14, 1, HSV_PINK},
    {15, 1, HSV_GREEN}, {16, 1, HSV_PINK},
    {17, 1, HSV_WHITE},
//
    {18, 1, HSV_BLUE},  {19, 1, HSV_WHITE},
    {20, 1, HSV_BLUE},
    {25, 1, HSV_OFF},
    {27, 3, HSV_GREEN}, {32, 1, HSV_PINK},
    {33, 1, HSV_GREEN}, {34, 1, HSV_PINK}
);
// my_layer3_layer
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// -- 16 15 14 13   re re re re re
// ye  9 10 11 12   re re re re --
// ye  6  5  4  3   re re re gr wh
//       gr gr gr   gr gr gr
//
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  3, HSV_GREEN},
    {7,  2, HSV_YELLOW},{17, 1, HSV_OFF},
//
    {18, 3, HSV_GREEN},
    {21, 3, HSV_RED},   {24, 1, HSV_GREEN},
    {25, 1, HSV_WHITE}, {26, 1, HSV_OFF},
    {27, 9, HSV_RED}
);
// my_layer4_layer
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//       bl bl bl   bl bl bl
//
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  3, HSV_BLUE},  {18, 3, HSV_BLUE}
);
// RGBLIGHT_LAYER_SEGMENTS
// 17 16 15 14 13   31 32 33 34 35
//  8  9 10 11 12   30 29 28 27 26
//  7  6  5  4  3   21 22 23 24 25
//        0  1  2   18 19 20
//
// -- -- -- -- --   re bl -- -- --
// -- -- -- -- --   re bl -- -- --
// gr -- wh -- --   re bl wh -- gr
//       -- gr --   -- gr --
//
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1, HSV_OFF},   {1,  1, HSV_GREEN},
    {2,  3, HSV_OFF},   {5,  1, HSV_WHITE},
    {6,  1, HSV_OFF},   {7,  1, HSV_GREEN},
    {8, 10, HSV_OFF},
//
    {18, 1, HSV_OFF},   {19, 1, HSV_GREEN},
    {20, 1, HSV_OFF},   {21, 1, HSV_RED},
    {22, 1, HSV_BLUE},  {23, 1, HSV_WHITE},
    {24, 1, HSV_OFF},   {25, 1, HSV_GREEN},
    {26, 3, HSV_OFF},   {29, 1, HSV_BLUE},
    {30, 2, HSV_RED},   {32, 1, HSV_BLUE},
    {33, 3, HSV_OFF}
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
#define CURSOR_DIV   -1

// Variables to store accumulated values
float cursor_accumulated_x = 0;
float cursor_accumulated_y = 0;
float spd_multi = 1;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  // Check if drag scrolling is active
  if (set_spd_lo) {
    spd_multi = 2.5;
  } else if (set_spd_hi){
    spd_multi = 5;
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

/*
//RK dip switch
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { audio_on(); } else { audio_off(); }
            break;
        case 1:
            if(active) { clicky_on(); } else { clicky_off(); }
            break;
        case 2:
            if(active) { music_on(); } else { music_off(); }
            break;
        case 3:
            if (active) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(plover_song);
                #endif
                layer_on(_PLOVER);
            } else {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(plover_gb_song);
                #endif
                layer_off(_PLOVER);
            }
            break;
    }
    return true;
}
*/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U), ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[1] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U), ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[2] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U), ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[3] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U), ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
[4] = {ENCODER_CCW_CW(RGB_MOD,RGB_RMOD), ENCODER_CCW_CW(RGB_VAD,RGB_VAI)},
[5] = {ENCODER_CCW_CW(KC_WH_D,KC_WH_U), ENCODER_CCW_CW(KC_WH_D,KC_WH_U)},
};
#endif
