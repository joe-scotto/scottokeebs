#include "keys.h"
#include QMK_KEYBOARD_H

bool is_mac = true;
bool is_game_mode = false;

void keyboard_post_init_user(void) { keymap_config.swap_lctl_lgui = false; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed)
    return true;

  switch (keycode) {
    case TO_DEFAULT:
      layer_move(0);
      return false;
      break;
    case TO_CODE:
      layer_move(1);
      return false;
      break;
    case TO_NUMBER:
      layer_move(2);
      return false;
      break;
    case OS_TOGGLE:
      is_mac = !is_mac;
      keymap_config.swap_lctl_lgui = is_mac ? false : true;
      return false;
    case GAME_TOGGLE:
      is_game_mode = !is_game_mode;
      return false;
    default:
      return true;
  }
}
