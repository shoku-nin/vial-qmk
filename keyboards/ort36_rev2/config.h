// Copyright 2023 shoku_nin (@shoku_nin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SOFT_SERIAL_PIN GP1
//#define FORCED_SYNC_THROTTLE_MS 100
//#define SERIAL_PIO_USE_PIO1
//#define SELECT_SOFT_SERIAL_SPEED 1
#define MASTER_LEFT
//#define SPLIT_HAND_PIN GP15
//SPLIT_HAND_PIN:
// If pin is high, it's the left side,
// if low, the half is determined to be the right side.

//#undef  SPLIT_USB_DETECT
//#define USB_VBUS_PIN GP15
//#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 5000
#define SPLIT_USB_TIMEOUT_POLL 25

//#define SPLIT_WATCHDOG_ENABLE
//#define SPLIT_WATCHDOG_TIMEOUT 5000

/*
#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_MOVE_DELTA  1
#   define MOUSEKEY_MAX_SPEED   1
#   define MOUSEKEY_TIME_TO_MAX 0
#endif
*/

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP16
    #define RGBLIGHT_LED_COUNT 2
//    #define RGBLED_NUM 2
    #define RGBLED_SPLIT {1,1}

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYER_BLINK
    #define SPLIT_LAYER_STATE_ENABLE
//
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING+3
#endif
