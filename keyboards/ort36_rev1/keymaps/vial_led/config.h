#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}

#ifdef RGBLIGHT_ENABLE
    #define WS2812_DI_PIN GP16
    #define RGBLED_NUM 1
//    #define RGBLED_SPLIT {1,1}

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYER_BLINK
    #define SPLIT_LAYER_STATE_ENABLE
//
    #define RGBLIGHT_EFFECT_BREATHING
//    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//    #define RGBLIGHT_EFFECT_SNAKE
//    #define RGBLIGHT_EFFECT_KNIGHT
//    #define RGBLIGHT_EFFECT_CHRISTMAS
//    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//    #define RGBLIGHT_EFFECT_RGB_TEST
//    #define RGBLIGHT_EFFECT_ALTERNATING
//    #define RGBLIGHT_EFFECT_TWINKLE
//    #define RGBLIGHT_LIMIT_VAL 120
//    #define RGBLIGHT_HUE_STEP 5
//    #define RGBLIGHT_SAT_STEP 5
//    #define RGBLIGHT_VAL_STEP 5
#endif
