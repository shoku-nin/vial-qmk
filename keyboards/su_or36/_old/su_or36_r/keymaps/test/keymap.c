#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SEND_A1 = SAFE_RANGE,
            SEND_B1,  SEND_C1,  SEND_D1,  SEND_E1,
  SEND_A2,  SEND_B2,  SEND_C2,  SEND_D2,  SEND_E2,
  SEND_A3,  SEND_B3,  SEND_C3,  SEND_D3,  SEND_E3,
  SEND_A4,  SEND_B4,  SEND_C4,  SEND_D4,  SEND_E4,
  SEND_A5,  SEND_B5,  SEND_C5,  SEND_D5,  SEND_E5,

  SEND_SA1, SEND_SB1, SEND_SC1, SEND_SD1, SEND_SE1,
  SEND_SA2, SEND_SB2, SEND_SC2, SEND_SD2, SEND_SE2,
  SEND_SA3, SEND_SB3, SEND_SC3, SEND_SD3, SEND_SE3,
  SEND_SA4, SEND_SB4, SEND_SC4, SEND_SD4, SEND_SE4,
  SEND_SA5, SEND_SB5, SEND_SC5, SEND_SD5, SEND_SE5
};

/*
enum custom_keycodes {
  SEND_A1 = SAFE_RANGE,
            SEND_A2,  SEND_A3,  SEND_A4,  SEND_A5,  SEND_A6,
  SEND_B1,  SEND_B2,  SEND_B3,  SEND_B4,  SEND_B5,  SEND_B6,
  SEND_C1,  SEND_C2,  SEND_C3,  SEND_C4,  SEND_C5,  SEND_C6,
  SEND_D1,  SEND_D2,  SEND_D3,  SEND_D4,  SEND_D5,  SEND_D6,
  SEND_E1,  SEND_E2,  SEND_E3,  SEND_E4,  SEND_E5,  SEND_E6,
  SEND_F1,  SEND_F2,  SEND_F3,  SEND_F4,  SEND_F5,  SEND_F6,

  SEND_SA1, SEND_SA2, SEND_SA3, SEND_SA4, SEND_SA5, SEND_SA6,
  SEND_SB1, SEND_SB2, SEND_SB3, SEND_SB4, SEND_SB5, SEND_SB6,
  SEND_SC1, SEND_SC2, SEND_SC3, SEND_SC4, SEND_SC5, SEND_SC6,
  SEND_SD1, SEND_SD2, SEND_SD3, SEND_SD4, SEND_SD5, SEND_SD6,
  SEND_SE1, SEND_SE2, SEND_SE3, SEND_SE4, SEND_SE5, SEND_SE6,
  SEND_SF1, SEND_SF2, SEND_SF3, SEND_SF4, SEND_SF5, SEND_SF6
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-------------------------------
   *  |   F5   E5   D5   C5   B5   A5
   *  |   F4   E4   D4   C4   B4   A4
   *  |   F3   E3   D3   C3   B3   A3
   *  |   F2   E2   D2   C2   B2   A2
   *  |   F1   E1   D1   C1   B1   A1
   *  `-------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-------------------------------
   *  |  SA1  SB1  SC1  SD1  SE1  SF1
   *  |  SA2  SB2  SC2  SD2  SE2  SF2
   *  |  SA3  SB3  SC3  SD3  SE3  SF3
   *  |  SA4  SB4  SC4  SD4  SE4  SF4
   *  |  SA5  SB5  SC5  SD5  SE5  SF5
   *  `-------------------------------
   */

/*
  [0] = LAYOUT(
  SEND_A1,  SEND_B1,  SEND_C1,  SEND_D1,  SEND_E1,
  SEND_A2,  SEND_B2,  SEND_C2,  SEND_D2,  SEND_E2,
  SEND_A3,  SEND_B3,  SEND_C3,  SEND_D3,  SEND_E3,
                                SEND_D4,  SEND_E4, SEND_F4,

            SEND_SB1, SEND_SC1, SEND_SD1, SEND_SE1, SEND_SF1,
            SEND_SB2, SEND_SC2, SEND_SD2, SEND_SE2, SEND_SF2,
            SEND_SB3, SEND_SC3, SEND_SD3, SEND_SE3, SEND_SF3,
  SEND_SA4, SEND_SB4, SEND_SC4
  ),
*/

  [0] = LAYOUT_TEST( /* Base */
  SEND_A1,  SEND_B1,  SEND_C1,  SEND_D1,  SEND_E1,
  SEND_A2,  SEND_B2,  SEND_C2,  SEND_D2,  SEND_E2,
  SEND_A3,  SEND_B3,  SEND_C3,  SEND_D3,  SEND_E3,
  SEND_A4,  SEND_B4,  SEND_C4,  SEND_D4,  SEND_E4,
  SEND_A5,  SEND_B5,  SEND_C5,  SEND_D5,  SEND_E5,

  SEND_SA1, SEND_SB1, SEND_SC1, SEND_SD1, SEND_SE1,
  SEND_SA2, SEND_SB2, SEND_SC2, SEND_SD2, SEND_SE2,
  SEND_SA3, SEND_SB3, SEND_SC3, SEND_SD3, SEND_SE3,
  SEND_SA4, SEND_SB4, SEND_SC4, SEND_SD4, SEND_SE4,
  SEND_SA5, SEND_SB5, SEND_SC5, SEND_SD5, SEND_SE5
),

/*
  [0] = LAYOUT(
    SEND_F6,  SEND_F5,  SEND_F4,  SEND_F3,  SEND_F2,  SEND_F1,
    SEND_E6,  SEND_E5,  SEND_E4,  SEND_E3,  SEND_E2,  SEND_E1,
    SEND_D6,  SEND_D5,  SEND_D4,  SEND_D3,  SEND_D2,  SEND_D1,
    SEND_C6,  SEND_C5,  SEND_C4,  SEND_C3,  SEND_C2,  SEND_C1,
    SEND_B6,  SEND_B5,  SEND_B4,  SEND_B3,  SEND_B2,  SEND_B1,
    SEND_A6,  SEND_A5,  SEND_A4,  SEND_A3,  SEND_A2,  SEND_A1,

    SEND_SA1, SEND_SA2, SEND_SA3, SEND_SA4, SEND_SA5, SEND_SA6,
    SEND_SB1, SEND_SB2, SEND_SB3, SEND_SB4, SEND_SB5, SEND_SB6,
    SEND_SC1, SEND_SC2, SEND_SC3, SEND_SC4, SEND_SC5, SEND_SC6,
    SEND_SD1, SEND_SD2, SEND_SD3, SEND_SD4, SEND_SD5, SEND_SD6,
    SEND_SE1, SEND_SE2, SEND_SE3, SEND_SE4, SEND_SE5, SEND_SE6,
    SEND_SF1, SEND_SF2, SEND_SF3, SEND_SF4, SEND_SF5, SEND_SF6
  ),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_A1: if (record->event.pressed) SEND_STRING("A1 "); break;
    case SEND_B1: if (record->event.pressed) SEND_STRING("B1 "); break;
    case SEND_C1: if (record->event.pressed) SEND_STRING("C1 "); break;
    case SEND_D1: if (record->event.pressed) SEND_STRING("D1 "); break;
    case SEND_E1: if (record->event.pressed) SEND_STRING("E1 "); break;
//    case SEND_F1: if (record->event.pressed) SEND_STRING("F1 "); break;
    case SEND_A2: if (record->event.pressed) SEND_STRING("A2 "); break;
    case SEND_B2: if (record->event.pressed) SEND_STRING("B2 "); break;
    case SEND_C2: if (record->event.pressed) SEND_STRING("C2 "); break;
    case SEND_D2: if (record->event.pressed) SEND_STRING("D2 "); break;
    case SEND_E2: if (record->event.pressed) SEND_STRING("E2 "); break;
//    case SEND_F2: if (record->event.pressed) SEND_STRING("F2 "); break;
    case SEND_A3: if (record->event.pressed) SEND_STRING("A3 "); break;
    case SEND_B3: if (record->event.pressed) SEND_STRING("B3 "); break;
    case SEND_C3: if (record->event.pressed) SEND_STRING("C3 "); break;
    case SEND_D3: if (record->event.pressed) SEND_STRING("D3 "); break;
    case SEND_E3: if (record->event.pressed) SEND_STRING("E3 "); break;
//    case SEND_F3: if (record->event.pressed) SEND_STRING("F3 "); break;
    case SEND_A4: if (record->event.pressed) SEND_STRING("A4 "); break;
    case SEND_B4: if (record->event.pressed) SEND_STRING("B4 "); break;
    case SEND_C4: if (record->event.pressed) SEND_STRING("C4 "); break;
    case SEND_D4: if (record->event.pressed) SEND_STRING("D4 "); break;
    case SEND_E4: if (record->event.pressed) SEND_STRING("E4 "); break;
//    case SEND_F4: if (record->event.pressed) SEND_STRING("F4 "); break;

    case SEND_A5: if (record->event.pressed) SEND_STRING("A5 "); break;
    case SEND_B5: if (record->event.pressed) SEND_STRING("B5 "); break;
    case SEND_C5: if (record->event.pressed) SEND_STRING("C5 "); break;
    case SEND_D5: if (record->event.pressed) SEND_STRING("D5 "); break;
    case SEND_E5: if (record->event.pressed) SEND_STRING("E5 "); break;
//    case SEND_F5: if (record->event.pressed) SEND_STRING("F5 "); break;
/*
    case SEND_A6: if (record->event.pressed) SEND_STRING("A6 "); break;
    case SEND_B6: if (record->event.pressed) SEND_STRING("B6 "); break;
    case SEND_C6: if (record->event.pressed) SEND_STRING("C6 "); break;
    case SEND_D6: if (record->event.pressed) SEND_STRING("D6 "); break;
    case SEND_E6: if (record->event.pressed) SEND_STRING("E6 "); break;
    case SEND_F6: if (record->event.pressed) SEND_STRING("F6 "); break;
*/
    case SEND_SA1: if (record->event.pressed) SEND_STRING("SA1 "); break;
    case SEND_SB1: if (record->event.pressed) SEND_STRING("SB1 "); break;
    case SEND_SC1: if (record->event.pressed) SEND_STRING("SC1 "); break;
    case SEND_SD1: if (record->event.pressed) SEND_STRING("SD1 "); break;
    case SEND_SE1: if (record->event.pressed) SEND_STRING("SE1 "); break;
//    case SEND_SF1: if (record->event.pressed) SEND_STRING("SF1 "); break;
    case SEND_SA2: if (record->event.pressed) SEND_STRING("SA2 "); break;
    case SEND_SB2: if (record->event.pressed) SEND_STRING("SB2 "); break;
    case SEND_SC2: if (record->event.pressed) SEND_STRING("SC2 "); break;
    case SEND_SD2: if (record->event.pressed) SEND_STRING("SD2 "); break;
    case SEND_SE2: if (record->event.pressed) SEND_STRING("SE2 "); break;
//    case SEND_SF2: if (record->event.pressed) SEND_STRING("SF2 "); break;
    case SEND_SA3: if (record->event.pressed) SEND_STRING("SA3 "); break;
    case SEND_SB3: if (record->event.pressed) SEND_STRING("SB3 "); break;
    case SEND_SC3: if (record->event.pressed) SEND_STRING("SC3 "); break;
    case SEND_SD3: if (record->event.pressed) SEND_STRING("SD3 "); break;
    case SEND_SE3: if (record->event.pressed) SEND_STRING("SE3 "); break;
//    case SEND_SF3: if (record->event.pressed) SEND_STRING("SF3 "); break;
    case SEND_SA4: if (record->event.pressed) SEND_STRING("SA4 "); break;
    case SEND_SB4: if (record->event.pressed) SEND_STRING("SB4 "); break;
    case SEND_SC4: if (record->event.pressed) SEND_STRING("SC4 "); break;
    case SEND_SD4: if (record->event.pressed) SEND_STRING("SD4 "); break;
    case SEND_SE4: if (record->event.pressed) SEND_STRING("SE4 "); break;
//    case SEND_SF4: if (record->event.pressed) SEND_STRING("SF4 "); break;

    case SEND_SA5: if (record->event.pressed) SEND_STRING("SA5 "); break;
    case SEND_SB5: if (record->event.pressed) SEND_STRING("SB5 "); break;
    case SEND_SC5: if (record->event.pressed) SEND_STRING("SC5 "); break;
    case SEND_SD5: if (record->event.pressed) SEND_STRING("SD5 "); break;
    case SEND_SE5: if (record->event.pressed) SEND_STRING("SE5 "); break;
//    case SEND_SF5: if (record->event.pressed) SEND_STRING("SF5 "); break;
/*
    case SEND_SA6: if (record->event.pressed) SEND_STRING("SA6 "); break;
    case SEND_SB6: if (record->event.pressed) SEND_STRING("SB6 "); break;
    case SEND_SC6: if (record->event.pressed) SEND_STRING("SC6 "); break;
    case SEND_SD6: if (record->event.pressed) SEND_STRING("SD6 "); break;
    case SEND_SE6: if (record->event.pressed) SEND_STRING("SE6 "); break;
    case SEND_SF6: if (record->event.pressed) SEND_STRING("SF6 "); break;
*/

  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
