#include QMK_KEYBOARD_H

enum combos {
  ENTER,
};

const uint16_t PROGMEM enter[] = {KC_RSFT, LT(1, KC_BSPC), COMBO_END};

combo_t key_combos[] = {
    [ENTER] = COMBO(enter, KC_ENTER),
};
