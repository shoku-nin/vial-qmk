#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "wrappers_0.21.h"

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

  [4] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [5] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______
  ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef POINTING_DEVICE_ENABLE

static uint8_t layer = 0;
static uint8_t scroll_ticks = 0;

#define SCROLL_WAIT_PERIOD 10

layer_state_t layer_state_set_user(layer_state_t state) {
    layer = get_highest_layer(state);
    return state;
}

static inline int8_t sign(const int8_t x) {
    return ((x == 0) ? 0 : (x < 0) ? -1 : 1);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (layer >= 1) {
  // Translate move to scroll when Fn is active
        mouse_report.h = sign(mouse_report.x);
        mouse_report.v = sign(mouse_report.y);
        mouse_report.x = 0;
        mouse_report.y = 0;

  // Only send once every SCROLL_WAIT_PERIOD ticks to slow scroll down
        if (mouse_report.h || mouse_report.v) {
            if (scroll_ticks != 0) {
                mouse_report.h = 0;
                mouse_report.v = 0;
            }
            scroll_ticks = (scroll_ticks + 1) % SCROLL_WAIT_PERIOD;
        }
    }
    return mouse_report;
}
#endif

/* joystick config */
#ifdef JOYSTICK_ENABLE

// Change this
char arrow_keys[4] = {KC_DOWN, KC_LEFT , KC_UP, KC_RIGHT};

static int actuation = 255; // actuation point for arrows (0-511)

bool arrows[4];

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

void joystick_task(){
        if (!arrows[0] && analogReadPin(JS_Y_PIN) - 512 > actuation){
            arrows[0] = true;
            register_code16(arrow_keys[2]);
        }
        else if (arrows[0] &&  analogReadPin(JS_Y_PIN) - 512 < actuation){
            arrows[0] = false;
            unregister_code16(arrow_keys[2]);
        }

        if (!arrows[1] && analogReadPin(JS_Y_PIN) - 512 < -actuation){
            arrows[1] = true;
            register_code16(arrow_keys[0]);
        }
        else if (arrows[1] && analogReadPin(JS_Y_PIN) - 512 > -actuation){
            arrows[1] = false;
            unregister_code16(arrow_keys[0]);
        }

        if (!arrows[2] && analogReadPin(JS_X_PIN) - 512 > actuation){
            arrows[2] = true;
            register_code16(arrow_keys[1]);
        }
        else if (arrows[2] &&  analogReadPin(JS_X_PIN) - 512 < actuation){
            arrows[2] = false;
            unregister_code16(arrow_keys[1]);
        }

        if (!arrows[3] && analogReadPin(JS_X_PIN) - 512 < -actuation){
            arrows[3] = true;
            register_code16(arrow_keys[3]);
        }
        else if (arrows[3] && analogReadPin(JS_X_PIN) - 512 > -actuation){
            arrows[3] = false;
            unregister_code16(arrow_keys[3]);
        }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            rgblight_step();
        } else {
            rgblight_step_reverse();
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
#endif
