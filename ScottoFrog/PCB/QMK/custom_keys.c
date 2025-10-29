#include QMK_KEYBOARD_H

// Force num lock always on
bool led_update_user(led_t state) {
  if (!state.num_lock) {
    tap_code(KC_NUM_LOCK);
  }
  return true;
}

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
    case KC_NUM_LOCK:
      return false;
  }
  return true;
}
