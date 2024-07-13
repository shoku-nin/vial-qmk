// Copyright 2023 shoku_nin (@shoku_nin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SOFT_SERIAL_PIN GP1
//#define MASTER_LEFT
#define SPLIT_HAND_PIN GP15
//SPLIT_HAND_PIN:
// If pin is high, it's the left side,
// if low, the half is determined to be the right side.

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT_POOL 5000

/*
#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_MOVE_DELTA  1
#   define MOUSEKEY_MAX_SPEED   1
#   define MOUSEKEY_TIME_TO_MAX 0
#endif
*/

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP16
    #define RGBLED_NUM 2
    #define RGBLED_SPLIT {1,1}

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYER_BLINK
    #define SPLIT_LAYER_STATE_ENABLE
//
    #define RGBLIGHT_EFFECT_BREATHING
#endif
