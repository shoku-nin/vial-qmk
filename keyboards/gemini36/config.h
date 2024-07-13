// Copyright 2023 shoku_nin (@shoku_nin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef POINTING_DEVICE_ENABLE
#   define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#   define ANALOG_JOYSTICK_Y_AXIS_PIN GP27
#   define ANALOG_JOYSTICK_SPEED_REGULATOR 40 // (lower makes it faster)
//#   define POINTING_DEVICE_INVERT_X_LEFT
//#   define POINTING_DEVICE_ROTATION_180_LEFT
//#   define POINTING_DEVICE_INVERT_Y_LEFT
//#   define POINTING_DEVICE_INVERT_X_RIGHT
//#   define POINTING_DEVICE_INVERT_Y_RIGHT
#   define SPLIT_POINTING_ENABLE
//#   define POINTING_DEVICE_LEFT
#   define POINTING_DEVICE_RIGHT
//#   define POINTING_DEVICE_COMBINED
#   define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#   define AUTO_MOUSE_TIME 1000
#endif

/* Rotary encoder */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { GP14 }
#   define ENCODERS_PAD_B { GP15 }
#   define ENCODER_RESOLUTION 4
#endif

//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 1000
//#define SPLIT_USB_TIMEOUT_POLL 25

//#define SERIAL_USART_TX_PIN GP1
#define SOFT_SERIAL_PIN GP1
#define MASTER_RIGHT

//#define MK_COMBINED

/*
#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_MOVE_DELTA  1
#   define MOUSEKEY_MAX_SPEED   1
#   define MOUSEKEY_TIME_TO_MAX 0
#endif
*/

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP0
    #define RGBLIGHT_LED_COUNT 36
//    #define RGBLED_NUM 36
    #define RGBLED_SPLIT {18,18}

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYER_BLINK
    #define SPLIT_LAYER_STATE_ENABLE
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
//
    #define RGBLIGHT_DEFAULT_HUE 60
    #define RGBLIGHT_DEFAULT_SAT 80
    #define RGBLIGHT_DEFAULT_VAL 180
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING+3
#endif
