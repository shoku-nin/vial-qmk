#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#undef  MASTER_RIGHT
#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DEFAULT_HUE 200
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL 110
#endif

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}
