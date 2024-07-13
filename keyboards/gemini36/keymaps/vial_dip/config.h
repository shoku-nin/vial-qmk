#pragma once

//#include "config_common.h"

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define VIAL_KEYBOARD_UID {0x4A, 0xC4, 0x52, 0x82, 0x20, 0x39, 0x4C, 0x6C}

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS_LEFT { GP11, GP12, GP13, GP28 }
