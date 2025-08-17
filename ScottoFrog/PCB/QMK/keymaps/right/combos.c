#include QMK_KEYBOARD_H

enum combos {
  GREEN_TAB,
  GREEN_APOSTROPHE,
  GREEN_B,
  GREEN_M,
  GREEN_J,
  GREEN_Q,
  GREEN_Z,
  GREEN_L,
  GREEN_C,
  GREEN_V,
  GREEN_CMD,
  GREEN_APP,
  GREEN_K,
  GREEN_G,
  GREEN_X,
  GREEN_COMMA,
  GREEN_PERIOD,
  NUMBER_F7,
  NUMBER_F8,
  NUMBER_F9,
  NUMBER_F11,
  NUMBER_F4,
  NUMBER_F5,
  NUMBER_F6,
  NUMBER_F12,
  NUMBER_F1,
  NUMBER_F2,
  NUMBER_F3,
  NUMBER_EQUAL,
  SYMBOL_COMMA
};

// Green
const uint16_t PROGMEM green_tab[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM green_apostrophe[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM green_b[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM green_m[] = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM green_j[] = {KC_SPC, KC_P, COMBO_END};
const uint16_t PROGMEM green_q[] = {KC_SPC, KC_O, COMBO_END};
const uint16_t PROGMEM green_z[] = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM green_l[] = {KC_SPC, KC_H, COMBO_END};
const uint16_t PROGMEM green_c[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM green_v[] = {KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM green_cmd[] = {KC_SPC, KC_U, COMBO_END};
const uint16_t PROGMEM green_app[] = {KC_SPC, KC_I, COMBO_END};
const uint16_t PROGMEM green_k[] = {KC_SPC, KC_N, COMBO_END};
const uint16_t PROGMEM green_g[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM green_x[] = {KC_SPC, KC_Y, COMBO_END};
const uint16_t PROGMEM green_comma[] = {KC_SPC, TO(2), COMBO_END};
const uint16_t PROGMEM green_period[] = {KC_SPC, KC_ENTER, COMBO_END};

// Number
const uint16_t PROGMEM number_f7[] = {KC_SPC, KC_7, COMBO_END};
const uint16_t PROGMEM number_f8[] = {KC_SPC, KC_8, COMBO_END};
const uint16_t PROGMEM number_f9[] = {KC_SPC, KC_9, COMBO_END};
const uint16_t PROGMEM number_f11[] = {KC_SPC, KC_SLASH, COMBO_END};
const uint16_t PROGMEM number_f4[] = {KC_SPC, KC_4, COMBO_END};
const uint16_t PROGMEM number_f5[] = {KC_SPC, KC_5, COMBO_END};
const uint16_t PROGMEM number_f6[] = {KC_SPC, KC_6, COMBO_END};
const uint16_t PROGMEM number_f12[] = {KC_SPC, KC_PLUS, COMBO_END};
const uint16_t PROGMEM number_f1[] = {KC_SPC, KC_1, COMBO_END};
const uint16_t PROGMEM number_f2[] = {KC_SPC, KC_2, COMBO_END};
const uint16_t PROGMEM number_f3[] = {KC_SPC, KC_3, COMBO_END};
const uint16_t PROGMEM number_equal[] = {KC_SPC, KC_EQUAL, COMBO_END};

// Symbol
const uint16_t PROGMEM symbol_comma[] = {KC_SPC, TO(0), COMBO_END};

combo_t key_combos[] = {
    [GREEN_TAB] = COMBO(green_tab, KC_TAB),
    [GREEN_APOSTROPHE] = COMBO(green_apostrophe, KC_QUOTE),
    [GREEN_B] = COMBO(green_b, KC_B),
    [GREEN_M] = COMBO(green_m, KC_M),
    [GREEN_J] = COMBO(green_j, KC_J),
    [GREEN_Q] = COMBO(green_q, KC_Q),
    [GREEN_Z] = COMBO(green_z, KC_Z),
    [GREEN_L] = COMBO(green_l, KC_L),
    [GREEN_C] = COMBO(green_c, KC_C),
    [GREEN_V] = COMBO(green_v, KC_V),
    [GREEN_CMD] = COMBO(green_cmd, KC_LGUI),
    [GREEN_APP] = COMBO(green_app, KC_APP),
    [GREEN_K] = COMBO(green_k, KC_K),
    [GREEN_G] = COMBO(green_g, KC_G),
    [GREEN_X] = COMBO(green_x, KC_X),
    [GREEN_COMMA] = COMBO(green_comma, KC_COMMA),
    [GREEN_PERIOD] = COMBO(green_period, KC_DOT),
    [NUMBER_F7] = COMBO(number_f7, KC_F7),
    [NUMBER_F8] = COMBO(number_f8, KC_F8),
    [NUMBER_F9] = COMBO(number_f9, KC_F9),
    [NUMBER_F11] = COMBO(number_f11, KC_F11),
    [NUMBER_F4] = COMBO(number_f4, KC_F4),
    [NUMBER_F5] = COMBO(number_f5, KC_F5),
    [NUMBER_F6] = COMBO(number_f6, KC_F5),
    [NUMBER_F12] = COMBO(number_f12, KC_F12),
    [NUMBER_F1] = COMBO(number_f1, KC_F1),
    [NUMBER_F2] = COMBO(number_f2, KC_F2),
    [NUMBER_F3] = COMBO(number_f3, KC_F3),
    [NUMBER_EQUAL] = COMBO(number_equal, KC_EQUAL),
    [SYMBOL_COMMA] = COMBO(symbol_comma, KC_COMMA),
};
