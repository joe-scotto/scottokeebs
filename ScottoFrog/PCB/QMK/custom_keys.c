#include QMK_KEYBOARD_H

// Force num lock always on
void keyboard_post_init_user(void) {
  if (!host_keyboard_led_state().num_lock) {
    register_code(KC_NUM_LOCK);
    unregister_code(KC_NUM_LOCK);
  }
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
