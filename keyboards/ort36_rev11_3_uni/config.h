// Copyright 2023 shoku_nin (@shoku_nin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT

/*
#define SOFT_SERIAL_PIN GP1
//#define FORCED_SYNC_THROTTLE_MS 100
#define MASTER_RIGHT
//#define SPLIT_HAND_PIN GP15
//SPLIT_HAND_PIN:
// If pin is high, it's the left side,
// if low, the half is determined to be the right side.

#define SPLIT_USB_TIMEOUT 5000
#define SPLIT_USB_TIMEOUT_POLL 25
*/

//#define SPLIT_WATCHDOG_ENABLE
//#define SPLIT_WATCHDOG_TIMEOUT 5000

#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_MOVE_DELTA  1
#   define MOUSEKEY_MAX_SPEED   8
#   define MOUSEKEY_TIME_TO_MAX 0
#endif


#ifdef POINTING_DEVICE_ENABLE
#   define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#   define ANALOG_JOYSTICK_Y_AXIS_PIN GP27
#   define ANALOG_JOYSTICK_SPEED_REGULATOR 30 // (lower makes it faster)
//#   define POINTING_DEVICE_INVERT_X_LEFT
//#   define POINTING_DEVICE_ROTATION_180_LEFT
//#   define POINTING_DEVICE_INVERT_Y_LEFT
//#   define POINTING_DEVICE_INVERT_X_RIGHT
//#   define SPLIT_POINTING_ENABLE
//#   define POINTING_DEVICE_LEFT
//#   define POINTING_DEVICE_RIGHT
//#   define POINTING_DEVICE_COMBINED
#   define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#   define AUTO_MOUSE_TIME 1000
#endif

/* Rotary encoder */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { GP13 }
#   define ENCODERS_PAD_B { GP12 }
#   define ENCODER_RESOLUTION 4
#endif

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP11
    #define RGBLIGHT_LED_COUNT 39
//    #define RGBLED_SPLIT {19,19}

#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYER_BLINK
//#    define SPLIT_LAYER_STATE_ENABLE
//
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
//#    define RGBLIGHT_LIMIT_VAL 200
//#    define RGBLIGHT_HUE_STEP 5
//#    define RGBLIGHT_SAT_STEP 5
//#    define RGBLIGHT_VAL_STEP 5
    #define RGBLIGHT_DEFAULT_HUE 200
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL 110
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING+3
//#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+5
#endif
#ifdef RGB_MATRIX_ENABLE
#    define WS2812_DI_PIN GP11
#    define RGB_MATRIX_LED_COUNT 39
//
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#    define RGB_MATRIX_KEYRELEASES // reacts to keyreleases
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#    define RGB_DISABLE_TIMEOUT 0
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
 // turn off effects when suspended
//
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
    #define RGBLIGHT_DEFAULT_HUE 200
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL 110
#    define RGB_MATRIX_STARTUP_SPD 127
//
//#    define RGB_MATRIX_HUE_STEP 4
//#    define RGB_MATRIX_SAT_STEP 4
//#    define RGB_MATRIX_VAL_STEP 4
//#    define RGB_MATRIX_SPD_STEP 4
//#    define RGB_MATRIX_DISABLE_KEYCODES
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_STARLIGHT
#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#    define ENABLE_RGB_MATRIX_RIVERFLOW
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SPLASH
//
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_PINWHEEL
#endif
