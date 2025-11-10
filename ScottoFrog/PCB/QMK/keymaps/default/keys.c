#include "keys.h"
#include QMK_KEYBOARD_H

// Mode check
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    switch (keycode) {}
  }

  return true;
}
