#include "keys.h"
#include "keycodes.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

bool is_mac = true;
bool is_game_mode = false;

// Mode check
char mode_string[50];
char *os;
char *mode;

void keyboard_post_init_user(void) {
  keymap_config.raw = eeconfig_read_user();

  // If swapped, layout should too
  if (keymap_config.swap_lctl_lgui) {
    is_mac = false;
  } else {
    is_mac = true;
  }
}

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
      eeconfig_update_user(keymap_config.raw);
      break;
      return false;
    case GAME_TOGGLE:
      is_game_mode = !is_game_mode;
      break;
      return false;
    case MODE_CHECK:
      os = is_mac ? "Mac" : "Windows";
      mode = is_game_mode ? " (Game)" : "";
      sprintf(mode_string, "Mode: %s%s", os, mode);
      send_string(mode_string);

      // Wait and delete
      wait_ms(500);
      for (size_t i = 0; i < strlen(mode_string); i++) {
        tap_code16(KC_BSPC);
      }
      break;
      return false;
  }

  return true;
}
