#include "combos.c"
#include "tapdance.c"
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//         ┌──────┬──────────┬──────────┬──────────┬─────────────┐
//         │  no  │ TD(TD_1) │ TD(TD_2) │ TD(TD_3) │     no      │
//         ├──────┼──────────┼──────────┼──────────┼─────────────┤
//         │  no  │ TD(TD_4) │ TD(TD_5) │ TD(TD_6) │     no      │
//         ├──────┼──────────┼──────────┼──────────┼─────────────┤
//         │  no  │ TD(TD_7) │ TD(TD_8) │ TD(TD_9) │     no      │
//    ┌────┼──────┼──────────┴──────────┴──────────┼─────────────┼────┐
//    │ no │ rsft │            TD(TD_0)            │ LT(1, bspc) │ no │
//    └────┴──────┴────────────────────────────────┴─────────────┴────┘
[0] = LAYOUT_ortho_4x5(
          KC_NO   , TD(TD_1) , TD(TD_2) , TD(TD_3) , KC_NO                 ,
          KC_NO   , TD(TD_4) , TD(TD_5) , TD(TD_6) , KC_NO                 ,
          KC_NO   , TD(TD_7) , TD(TD_8) , TD(TD_9) , KC_NO                 ,
  KC_NO , KC_RSFT ,            TD(TD_0)            , LT(1, KC_BSPC) , KC_NO
),

//         ┌─────┬──────┬─────────┬──────┬─────┐
//         │ no  │ esc  │   up    │ ent  │ no  │
//         ├─────┼──────┼─────────┼──────┼─────┤
//         │ no  │ left │  down   │ rght │ no  │
//         ├─────┼──────┼─────────┼──────┼─────┤
//         │ no  │ caps │ QK_BOOT │ del  │ no  │
//    ┌────┼─────┼──────┴─────────┴──────┼─────┼─────┐
//    │ no │     │                       │     │     │
//    └────┴─────┴───────────────────────┴─────┴─────┘
[1] = LAYOUT_ortho_4x5(
          KC_NO   , KC_ESC  , KC_UP   , KC_ENTER  , KC_NO            ,
          KC_NO   , KC_LEFT , KC_DOWN , KC_RIGHT  , KC_NO            ,
          KC_NO   , KC_CAPS , QK_BOOT , KC_DELETE , KC_NO            ,
  KC_NO , KC_TRNS ,            KC_TRNS            , KC_TRNS , KC_TRNS
)
};
// clang-format on
