# MCU name
MCU = atmega32u4
F_CPU = 16000000

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Build Options
#   change yes to no to disable
#

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no     # Breathing sleep LED during USB suspend

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MIDI_ENABLE = no          # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no       # Unicode
BLUETOOTH_ENABLE = no     # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no         # Audio output on port C6
FAUXCLICKY_ENABLE = no    # Use buzzer to emulate clicky switches
HD44780_ENABLE = no       # Enable support for HD44780 based LCDs (+400)

LTO_ENABLE = yes
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = no
CAPS_WORD_ENABLE = yes
