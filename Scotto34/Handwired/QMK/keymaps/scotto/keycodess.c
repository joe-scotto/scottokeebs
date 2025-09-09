#include QMK_KEYBOARD_H
#include "keycodess.h"

bool is_mac = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TO_DEFAULT:
      if (record->event.pressed) {
        layer_move(is_mac ? 0 : 1);
      }
      return false;
      break;
    case TO_CODE:
      if (record->event.pressed) {
        layer_move(2);
      }
      return false;
      break;
    case TO_NUMBER:
      if (record->event.pressed) {
        layer_move(3);
      }
      return false;
      break;
    case OS_TOGGLE:
      if (record->event.pressed) {
        is_mac = !is_mac;
        layer_move(is_mac ? 0 : 1);
      }
      return false;
    default:
      return true;
  }
}
