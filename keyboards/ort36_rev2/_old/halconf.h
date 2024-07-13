#pragma once

#undef  PAL_USE_CALLBACK
#define PAL_USE_CALLBACK TRUE
#define HAL_USE_SERIAL TRUE

#include_next <halconf.h>
