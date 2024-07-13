#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}

#ifdef RGBLIGHT_ENABLE
    #undef  WS2812_DI_PIN
    #undef  RGBLED_NUM
    #undef  RGBLED_SPLIT
//
    #define WS2812_DI_PIN GP16
    #define RGBLED_NUM 2
    #define RGBLED_SPLIT {1,1}
#endif
