#include "combos.c"
#include "tapdance.c"
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────────┬──────────┬─────────────┐
//    │ TD(TD_1) │ TD(TD_2) │  TD(TD_3)   │
//    ├──────────┼──────────┼─────────────┤
//    │ TD(TD_4) │ TD(TD_5) │  TD(TD_6)   │
//    ├──────────┼──────────┼─────────────┤
//    │ TD(TD_7) │ TD(TD_8) │  TD(TD_9)   │
//    ├──────────┼──────────┼─────────────┤
//    │   rsft   │ TD(TD_0) │ LT(1, bspc) │
//    └──────────┴──────────┴─────────────┘
[0] = LAYOUT_ortho_4x3(
  TD(TD_1) , TD(TD_2) , TD(TD_3)      ,
  TD(TD_4) , TD(TD_5) , TD(TD_6)      ,
  TD(TD_7) , TD(TD_8) , TD(TD_9)      ,
  KC_RSFT  , TD(TD_0) , LT(1, KC_BSPC)
),

//    ┌──────┬─────────┬──────┐
//    │ tab  │   up    │ ent  │
//    ├──────┼─────────┼──────┤
//    │ left │  down   │ rght │
//    ├──────┼─────────┼──────┤
//    │ caps │ QK_BOOT │ del  │
//    ├──────┼─────────┼──────┤
//    │      │         │      │
//    └──────┴─────────┴──────┘
[1] = LAYOUT_ortho_4x3(
  KC_TAB  , KC_UP   , KC_ENTER ,
  KC_LEFT , KC_DOWN , KC_RIGHT ,
  KC_CAPS , QK_BOOT , KC_DELETE,
  KC_TRNS , KC_TRNS , KC_TRNS
)
};
// clang-format on
