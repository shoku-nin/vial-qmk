#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}

#ifdef JOYSTICK_ENABLE
#   undef JS_X_PIN
#   define JS_X_PIN GP26
#   undef JS_Y_PIN
#   define JS_Y_PIN GP27
#endif

#ifdef POINTING_DEVICE_ENABLE
#   undef ANALOG_JOYSTICK_X_AXIS_PIN
#   define ANALOG_JOYSTICK_X_AXIS_PIN GP29
#   undef ANALOG_JOYSTICK_Y_AXIS_PIN
#   define ANALOG_JOYSTICK_Y_AXIS_PIN GP28
#endif
