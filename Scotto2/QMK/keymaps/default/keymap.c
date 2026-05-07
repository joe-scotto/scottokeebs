#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬──────┐
//    │ left │ rght │
//    └──────┴──────┘
[0] = LAYOUT(
  KC_LEFT , KC_RIGHT
)
};
// clang-format on
