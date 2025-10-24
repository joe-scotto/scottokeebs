#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_CARET = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CARET:
      if (record->event.pressed) {
        tap_code16(S(KC_6));
      }
      return false;
  }
  return true;
}
