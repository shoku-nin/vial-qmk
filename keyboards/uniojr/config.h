// Copyright 2023 shoku_nin (@shoku_nin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef POINTING_DEVICE_ENABLE
#   define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#   define ANALOG_JOYSTICK_Y_AXIS_PIN GP27
#   define ANALOG_JOYSTICK_SPEED_REGULATOR 40 // (lower makes it faster)
//#   define POINTING_DEVICE_INVERT_X
#   define POINTING_DEVICE_ROTATION_180
#   define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#   define AUTO_MOUSE_TIME 1000
#endif

#define MATRIX_MASKED
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 1

/* Rotary encoder */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { GP12 }
#   define ENCODERS_PAD_B { GP13 }
#   define ENCODER_RESOLUTION 4
#endif

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP1
    #define RGBLED_NUM 36

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYER_BLINK
//
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
//    #define RGBLIGHT_LIMIT_VAL 120
//    #define RGBLIGHT_HUE_STEP 5
//    #define RGBLIGHT_SAT_STEP 5
//    #define RGBLIGHT_VAL_STEP 5
#endif
