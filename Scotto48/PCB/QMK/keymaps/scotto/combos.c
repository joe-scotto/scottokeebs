#include "keys.h"
#include QMK_KEYBOARD_H

// Define combos
const uint16_t PROGMEM tab_combo[] = {KC_Y, KC_BSPC, COMBO_END};
const uint16_t PROGMEM tab_number_combo[] = {KC_CAPS, KC_BSPC, COMBO_END};
const uint16_t PROGMEM tab_code_combo[] = {KC_MFFD, KC_DEL, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_number_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM enter_code_combo[] = {KC_UNDS, KC_MINS, COMBO_END};
const uint16_t PROGMEM number_combo[] = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM number_code_combo[] = {KC_EXLM, KC_BSPC, COMBO_END};
const uint16_t PROGMEM number_default_combo[] = {KC_AT, KC_CAPS, COMBO_END};
const uint16_t PROGMEM code_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM code_number_combo[] = {KC_MINS, KC_MFFD, COMBO_END};
const uint16_t PROGMEM code_default_combo[] = {KC_UNDS, KC_DEL, COMBO_END};

// Create combos
combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(tab_number_combo, KC_TAB),
    COMBO(tab_code_combo, KC_TAB),
    COMBO(enter_combo, KC_ENT),
    COMBO(enter_number_combo, KC_ENT),
    COMBO(enter_code_combo, KC_ENT),
    COMBO(number_combo, TO_NUMBER),
    COMBO(number_code_combo, TO_CODE),
    COMBO(number_default_combo, TO_DEFAULT),
    COMBO(code_combo, TO_CODE),
    COMBO(code_number_combo, TO_NUMBER),
    COMBO(code_default_combo, TO_DEFAULT),
};
