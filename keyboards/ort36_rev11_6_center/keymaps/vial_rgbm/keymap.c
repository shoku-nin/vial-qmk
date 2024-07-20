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
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[1] = LAYOUT_wrapper(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[2] = LAYOUT_wrapper(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[3] = LAYOUT_wrapper(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[4] = LAYOUT(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[5] = LAYOUT(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
),

[6] = LAYOUT(
JP_1,JP_2,
JP_4,JP_5,JP_6,
JP_7,JP_8,JP_9
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
//static uint8_t layer = 0;

// Function to handle layer changes and disable hi-speed when not in AUTO_MOUSE_DEFAULT_LAYER

#ifdef RGB_MATRIX_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
//
// Disable hi-speed if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER

/*
uint8_t layer = get_highest_layer(state);
    if (layer != AUTO_MOUSE_DEFAULT_LAYER) {
        set_spd_hi = false;
        set_spd_lo = false;
    }
*/

/*
    if (layer == 1) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect1);
    }
    if (layer == 2) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect2);
    }
    else {
        rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    }
*/
/*
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
*/
    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  int current_layer = get_highest_layer(layer_state|default_layer_state);
  HSV hsv = {0, 255, rgblight_get_val()};
  if (current_layer == 1) {
    hsv.h = 169; //BLUE
    hsv.s = 255;
  } else if (current_layer == 2)  {
    hsv.h = 85; //GREEN
    hsv.s = 255;
  } else if (current_layer == 3)  {
    hsv.h = 21; //ORANGE
    hsv.s = 255;
  } else if (current_layer == 4)  {
    hsv.h = 222; //ROSE
    hsv.s = 255;
  } else if (current_layer == 5)  {
    hsv.h = 0; //RED
    hsv.s = 255;
  } else if (current_layer == 6)  {
    hsv.h = 0; //RED
    hsv.s = 255;
  } else {
    hsv.h = 0;
    hsv.s = 0;
    hsv.v = 0;
  }
  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i <= led_max -1; i++) {
      if (HAS_FLAGS(g_led_config.flags[i], 0x08)) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
/*
      if (host_keyboard_led_state().caps_lock){
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)){
        rgb_matrix_set_color(i, RGB_WHITE); break;}
      }
*/
  }
  return false;
}

#endif


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
