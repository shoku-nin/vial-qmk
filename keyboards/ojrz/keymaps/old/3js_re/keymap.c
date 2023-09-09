#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"
#include "wrappers_0.21.h"

#ifdef POINTING_DEVICE_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_layer(5);
    set_auto_mouse_enable(true);
}

/*
enum layer_names {
    _BL,
    _FL,
    _CL,
};
*/

enum custom_keycodes {
    DRG_SCR = SAFE_RANGE,
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_wrapper(
  _qwert_L1_, _qwert_R1_,
  _qwert_L2_, _qwert_R2_,
  LT(1,JP_Z),MT(MOD_LALT,JP_X),JP_C,MT(MOD_LSFT,JP_V),MT(DRG_SCR,JP_B),
    MT(DRG_SCR,JP_N),JP_M,MT(MOD_LSFT,JP_MINS),MT(MOD_LCTL,JP_COMM),LT(2,JP_DOT),
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
  _func_L3_, KC_F11,KC_F2,KC_F3,KC_RCTL,TO(4),
  _func_L4_, _func_R4_
  ),

  [4] = LAYOUT(
  TO(0),RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,
    RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,
  XXXXXXX,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,
    RGB_RMOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,
  XXXXXXX,XXXXXXX,XXXXXXX,KC_LSFT,XXXXXXX,
    RGB_TOG,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_RSFT
  ),

  [5] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_MS_BTN2, KC_MS_BTN1,    KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_MS_BTN2, KC_MS_BTN1,    KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO
  ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

bool set_scrolling = false;
static uint8_t layer = 0;

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER

layer_state_t layer_state_set_user(layer_state_t state) {
//
// Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    layer = get_highest_layer(state);
    if (layer != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }
    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            rgblight_sethsv(HSV_RED);
            break;
        case 1:
            rgblight_sethsv(HSV_BLUE);
//            rgblight_sethsv_at(HSV_BLUE, 4);
//            rgblight_sethsv_at(HSV_BLUE, 31);
//            rgblight_sethsv_range(HSV_BLUE, 0, 6);
            break;
        case 2:
            rgblight_sethsv(HSV_YELLOW);
//            rgblight_sethsv_at(HSV_PINK, 4);
//            rgblight_sethsv_at(HSV_PINK, 31);
//            rgblight_sethsv_range(HSV_GREEN, 7, 13);
            break;
        case 3:
            rgblight_sethsv(HSV_GREEN);
//            rgblight_sethsv_at(HSV_GREEN, 4);
//            rgblight_sethsv_at(HSV_GREEN, 31);
//            rgblight_sethsv_range(HSV_WHITE, 14, 20);
            break;
        case 4:
              rgblight_sethsv(HSV_GOLD);
//            rgblight_sethsv_at(HSV_WHITE, 0);
//            rgblight_sethsv_at(HSV_WHITE, 31);
//            rgblight_sethsv_range(HSV_WHITE, 21, 27);
            break;
        case 5:
            rgblight_sethsv(HSV_WHITE);
//            rgblight_sethsv_at(HSV_WHITE, 8);
//            rgblight_sethsv_at(HSV_ORANGE,9);
//            rgblight_sethsv_at(HSV_ORANGE,10);
//            rgblight_sethsv_at(HSV_WHITE, 11);
//            rgblight_sethsv_range(HSV_WHITE, 28, 35);
            break;
    }
    return state;
}

#ifdef POINTING_DEVICE_ENABLE

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 12.0
#define SCROLL_DIVISOR_V 12.0

// Variables to store accumulated scroll values
float scroll_accumulated_l_h = 0;
float scroll_accumulated_l_v = 0;
float scroll_accumulated_r_h = 0;
float scroll_accumulated_r_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
  // Check if drag scrolling is active
    if (set_scrolling) {
  // Calculate and accumulate scroll values based on mouse movement and divisors
       scroll_accumulated_l_h += (float)left_report.x / SCROLL_DIVISOR_H;
       scroll_accumulated_l_v += (float)left_report.y / SCROLL_DIVISOR_V;
       scroll_accumulated_r_h += (float)right_report.x / SCROLL_DIVISOR_H;
       scroll_accumulated_r_v += (float)right_report.y / SCROLL_DIVISOR_V;

  // Assign integer parts of accumulated scroll values to the mouse report
        left_report.h = (int8_t)scroll_accumulated_r_h;
        left_report.v = (int8_t)scroll_accumulated_r_v;
        right_report.h = (int8_t)scroll_accumulated_l_h;
        right_report.v = (int8_t)scroll_accumulated_l_v;

  // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_l_h -= (int8_t)scroll_accumulated_l_h;
        scroll_accumulated_l_v -= (int8_t)scroll_accumulated_l_v;
        scroll_accumulated_r_h -= (int8_t)scroll_accumulated_r_h;
        scroll_accumulated_r_v -= (int8_t)scroll_accumulated_r_v;

  // Clear the X and Y values of the mouse report
        left_report.x = 0;
        left_report.y = 0;
        right_report.x = 0;
        right_report.y = 0;
    }
    return pointing_device_combine_reports(left_report, right_report);
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRG_SCR:
// Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

#endif

/* joystick config */
#ifdef JOYSTICK_ENABLE

// Change this
//char arrow_keys[8] = {KC_DOWN, KC_LEFT , KC_UP, KC_RIGHT, KC_DOWN, KC_LEFT , KC_UP, KC_RIGHT};
char arrow_keys[4] = {KC_DOWN, KC_LEFT , KC_UP, KC_RIGHT};

static int actuation = 255; // actuation point for arrows (0-511)

//bool arrows[8];
bool arrows[4];

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
//    [1] = JOYSTICK_AXIS_VIRTUAL,
//    [2] = JOYSTICK_AXIS_VIRTUAL,
//    [3] = JOYSTICK_AXIS_VIRTUAL
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
//
/*
        if (!arrows[0] && analogReadPin(JS_Y_PIN) - 512 > actuation){
            arrows[4] = true;
            register_code16(arrow_keys[2]);
        }
        else if (arrows[0] &&  analogReadPin(JS_Y_PIN) - 512 < actuation){
            arrows[4] = false;
            unregister_code16(arrow_keys[2]);
        }

        if (!arrows[1] && analogReadPin(JS_Y_PIN) - 512 < -actuation){
            arrows[5] = true;
            register_code16(arrow_keys[0]);
        }
        else if (arrows[1] && analogReadPin(JS_Y_PIN) - 512 > -actuation){
            arrows[5] = false;
            unregister_code16(arrow_keys[0]);
        }

        if (!arrows[2] && analogReadPin(JS_X_PIN) - 512 > actuation){
            arrows[6] = true;
            register_code16(arrow_keys[1]);
        }
        else if (arrows[2] &&  analogReadPin(JS_X_PIN) - 512 < actuation){
            arrows[6] = false;
            unregister_code16(arrow_keys[1]);
        }

        if (!arrows[3] && analogReadPin(JS_X_PIN) - 512 < -actuation){
            arrows[7] = true;
            register_code16(arrow_keys[3]);
        }
        else if (arrows[3] && analogReadPin(JS_X_PIN) - 512 > -actuation){
            arrows[7] = false;
            unregister_code16(arrow_keys[3]);
        }
*/
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[1] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[2] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[3] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
[4] = {ENCODER_CCW_CW(RGB_HUD,RGB_HUI), ENCODER_CCW_CW(RGB_SAD,RGB_SAI)},
[5] = {ENCODER_CCW_CW(KC_WH_U,KC_WH_D), ENCODER_CCW_CW(KC_WH_U,KC_WH_D)},
};
#endif

/*
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
    } else if (index == 1) { // Second encoder
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return false;
}
#endif
*/
