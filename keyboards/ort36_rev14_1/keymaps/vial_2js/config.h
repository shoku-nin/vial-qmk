#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}

#ifdef POINTING_DEVICE_ENABLE
#   undef POINTING_DEVICE_RIGHT
#   define POINTING_DEVICE_COMBINED
#endif
