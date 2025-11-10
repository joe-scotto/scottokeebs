#include "tapdance.c"
#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Space tap, 0 on hold
    case LT(0, KC_SPC):
      if (!record->tap.count && record->event.pressed) {
        tap_code(KC_0);
        return false;
      }
      return true;

    // Backspace tap, # on hold
    case LT(0, KC_BSPC):
      if (!record->tap.count && record->event.pressed) {
        tap_code(KC_2);
        return false;
      }
      return true;
  }
  return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//         ┌─────────────────┬──────────┬──────────┬──────────┬─────────────┐
//         │       no        │ TD(TD_1) │ TD(TD_2) │ TD(TD_3) │     no      │
//         ├─────────────────┼──────────┼──────────┼──────────┼─────────────┤
//         │       no        │ TD(TD_4) │ TD(TD_5) │ TD(TD_6) │     no      │
//         ├─────────────────┼──────────┼──────────┼──────────┼─────────────┤
//         │       no        │ TD(TD_7) │ TD(TD_8) │ TD(TD_9) │     no      │
//    ┌────┼─────────────────┼──────────┴──────────┴──────────┼─────────────┼─────────┐
//    │ no │ MT(MOD_LSFT, ') │           LT(0, spc)           │ LT(0, bspc) │ QK_BOOT │
//    └────┴─────────────────┴────────────────────────────────┴─────────────┴─────────┘
[0] = LAYOUT_ortho_4x5(
          KC_NO                  , TD(TD_1) , TD(TD_2) , TD(TD_3) , KC_NO                   ,
          KC_NO                  , TD(TD_4) , TD(TD_5) , TD(TD_6) , KC_NO                   ,
          KC_NO                  , TD(TD_7) , TD(TD_8) , TD(TD_9) , KC_NO                   ,
  KC_NO , MT(MOD_LSFT, KC_QUOTE) ,         LT(0, KC_SPC)          , LT(0, KC_BSPC) , QK_BOOT
)
};
// clang-format on
