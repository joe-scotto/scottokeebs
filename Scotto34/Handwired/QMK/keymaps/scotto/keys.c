#include "keys.h"
#include "action.h"
#include QMK_KEYBOARD_H

bool is_mac = true;
bool is_game_mode = false;

// Always ensure keyboard is in Mac mode first
void keyboard_post_init_user(void) { keymap_config.swap_lctl_lgui = false; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (is_game_mode) {
    uint16_t game_mode_keycode = KC_NO;

    switch (keycode) {
      case LSFT_T(KC_Z):
        game_mode_keycode = KC_Z;
        break;
      case RSFT_T(KC_SLSH):
        game_mode_keycode = KC_SLSH;
        break;
      case TD(TD_MODS_X):
        game_mode_keycode = KC_X;
        break;
      case TD(TD_MODS_DOT):
        game_mode_keycode = KC_DOT;
        break;
      case TD(TD_MULTI):
        game_mode_keycode = KC_LCTL;
        break;
      case LGUI_T(KC_SPC):
        game_mode_keycode = KC_SPC;
        break;
    }

    if (game_mode_keycode != KC_NO) {
      record->event.pressed ? register_code(game_mode_keycode) : unregister_code(game_mode_keycode);
      return false;
    }
  }

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
