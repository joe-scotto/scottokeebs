#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//          ┌───┬───┬───┬───┬──────┐
//          │ q │ w │ e │ r │  t   │
//          ├───┼───┼───┼───┼──────┤
//          │ a │ s │ d │ f │  g   │
//          ├───┼───┼───┼───┼──────┤
//          │ z │ x │ c │ v │  b   │
//    ┌─────┼───┼───┴───┴───┼──────┼─────┐
//    │ esc │ k │     j     │ lctl │ spc │
//    └─────┴───┴───────────┴──────┴─────┘
[0] = LAYOUT_ortho_4x5(
           KC_Q , KC_W , KC_E , KC_R , KC_T            ,
           KC_A , KC_S , KC_D , KC_F , KC_G            ,
           KC_Z , KC_X , KC_C , KC_V , KC_B            ,
  KC_ESC , KC_K ,        KC_J        , KC_LCTL , KC_SPC
)
};
// clang-format on
