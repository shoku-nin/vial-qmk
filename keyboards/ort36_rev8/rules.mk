# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

SPLIT_KEYBOARD = yes
ENCODER_ENABLE = yes

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = no

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

#SPACE SAVING
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
CAPS_WORD_ENABLE = yes

#PER KEY RGB
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
RGBLIGHT_DRIVER = ws2812    # RGB matrix driver support

POINTING_DEVICE_ENABLE = yes # Generic Pointer
POINTING_DEVICE_DRIVER = analog_joystick
