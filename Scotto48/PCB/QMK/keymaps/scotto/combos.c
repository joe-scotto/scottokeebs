#include "keys.h"
#include QMK_KEYBOARD_H

// Define combos
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_Y, KC_BSPC, COMBO_END};
const uint16_t PROGMEM space_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM middle_click_combo[] = {LT(2, KC_TAB), LT(3, KC_ENT), COMBO_END};
const uint16_t PROGMEM default_combo[] = {KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM code_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM number_combo[] = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM function_combo[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM function_combo_2[] = {LT(2, KC_TAB), LT(3, KC_ENT), COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {KC_P, KC_L, COMBO_END};

// Create combos
combo_t key_combos[] = {
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [ENTER_COMBO] = COMBO(enter_combo, KC_ENT),
    [SPACE_COMBO] = COMBO(space_combo, KC_SPC),
    [MIDDLE_CLICK_COMBO] = COMBO(middle_click_combo, MS_BTN3),
    [DEFAULT_COMBO] = COMBO(default_combo, TO_DEFAULT),
    [CODE_COMBO] = COMBO(code_combo, TO_CODE),
    [NUMBER_COMBO] = COMBO(number_combo, TO_NUMBER),
    [FUNCTION_COMBO] = COMBO(function_combo, TO_FUNCTION),
    [FUNCTION_COMBO_2] = COMBO(function_combo_2, MO(4)),
    [MOUSE_COMBO] = COMBO(mouse_combo, TO_MOUSE),
};

// Lock combos to layers
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // Only allow middle click on mouse layer
  if (combo_index == MIDDLE_CLICK_COMBO) {
    return layer_state_is(5);
  }

  // Disable layer toggle on mouse layer
  if (combo_index == FUNCTION_COMBO_2) {
    return !layer_state_is(5);
  }

  return true;
}
