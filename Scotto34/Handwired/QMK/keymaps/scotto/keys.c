#include "keys.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

bool is_mac = true;
bool is_game_mode = false;

uint8_t get_base_layer(void) { return is_game_mode ? 2 : (is_mac ? 0 : 1); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed)
    return true;

  switch (keycode) {
    case TO_DEFAULT:
      layer_move(get_base_layer());
      return false;
      break;
    case TO_CODE:
      layer_move(3);
      return false;
      break;
    case TO_NUMBER:
      layer_move(4);
      return false;
      break;
    case OS_TOGGLE:
      is_mac = !is_mac;
      layer_move(get_base_layer());
      return false;
    case GAME_TOGGLE:
      is_game_mode = !is_game_mode;
      layer_move(get_base_layer());
      return false;
    default:
      return true;
  }
}
