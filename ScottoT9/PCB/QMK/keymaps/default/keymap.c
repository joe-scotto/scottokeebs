#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┐   ┌──────┐
//    │ left │   │ rght │
//    ├──────┼───┼──────┤
//    │  1   │ 2 │  3   │
//    ├──────┼───┼──────┤
//    │  4   │ 5 │  6   │
//    ├──────┼───┼──────┤
//    │  7   │ 8 │  9   │
//    ├──────┼───┼──────┤
//    │  *   │ 0 │  #   │
//    └──────┴───┴──────┘
[0] = LAYOUT_ortho_2_4x3(
  KC_LEFT     ,        KC_RIGHT,
  KC_1        , KC_2 , KC_3    ,
  KC_4        , KC_5 , KC_6    ,
  KC_7        , KC_8 , KC_9    ,
  KC_ASTERISK , KC_0 , KC_HASH
)
};
// clang-format on
