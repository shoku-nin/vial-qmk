# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

VIA_ENABLE = yes

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = yes

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# AUDIO
AUDIO_ENABLE = no
AUDIO_DRIVER = pwm_hardware


BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes      # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes     # Audio control and System control(+450)
CONSOLE_ENABLE = no       # Console for debug(+400)
COMMAND_ENABLE = no       # Commands for debug and configuration

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no     # Breathing sleep LED during USB suspend

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no          # USB Nkey Rollover
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MIDI_ENABLE = no          # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no       # Unicode
BLUETOOTH_ENABLE = no     # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no         # Audio output on port C6
FAUXCLICKY_ENABLE = no    # Use buzzer to emulate clicky switches
HD44780_ENABLE = no       # Enable support for HD44780 based LCDs (+400)

SPLIT_KEYBOARD = no
#SPLIT_KEYBOARD = yes
ENCODER_ENABLE = no

CUSTOM_MATRIX = yes
SRC += my_matrix.c
