#include "keys.h"
#include "keycodes.h"
#include "quantum.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

bool is_windows = false;
bool is_game_mode = false;
bool is_qwerty = false;

// Mode check
char mode_string[32];
char *os;
char *mode;
char *layout;

void keyboard_post_init_user(void) {
  keymap_config.raw = eeconfig_read_user();

  // If swapped, layout should too
  if (keymap_config.swap_lctl_lgui) {
    is_windows = true;
  } else {
    is_windows = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t remapped_keycode = KC_NO;

  if (is_qwerty) {
    switch (keycode) {
      // Top row
      case KC_F:
        remapped_keycode = KC_E;
        break;
      case KC_P:
        remapped_keycode = KC_R;
        break;
      case KC_G:
        remapped_keycode = KC_T;
        break;
      case KC_J:
        remapped_keycode = KC_Y;
        break;
      case KC_L:
        remapped_keycode = KC_U;
        break;
      case KC_U:
        remapped_keycode = KC_I;
        break;
      case KC_Y:
        remapped_keycode = KC_O;
        break;
      case KC_BSPC:
        remapped_keycode = KC_P;
        break;
      case KC_R:
        remapped_keycode = KC_S;
        break;
      case KC_S:
        remapped_keycode = KC_D;
        break;
      case KC_T:
        remapped_keycode = KC_F;
        break;
      case KC_D:
        remapped_keycode = KC_G;
        break;
      case KC_N:
        remapped_keycode = KC_J;
        break;
      case KC_E:
        remapped_keycode = KC_K;
        break;
      case KC_I:
        remapped_keycode = KC_L;
        break;
      case KC_O:
        remapped_keycode = KC_BSPC;
        break;
      case KC_K:
        remapped_keycode = KC_N;
        break;
    }
  }

  if (is_game_mode) {
    switch (keycode) {
      case LSFT_T(KC_Z):
        remapped_keycode = KC_Z;
        break;
      case RSFT_T(KC_SLSH):
        remapped_keycode = KC_SLSH;
        break;
      case TD(TD_MODS_X):
        remapped_keycode = KC_X;
        break;
      case TD(TD_MODS_DOT):
        remapped_keycode = KC_DOT;
        break;
      case TD(TD_MULTI):
        remapped_keycode = KC_LCTL;
        break;
      case LGUI_T(KC_SPC):
        remapped_keycode = KC_SPC;
        break;
    }
  }

  if (remapped_keycode != KC_NO) {
    record->event.pressed ? register_code(remapped_keycode) : unregister_code(remapped_keycode);
    return false;
  }

  if (keycode == MODE_CHECK) {
    os = is_windows ? "Windows" : "Mac";
    mode = is_game_mode ? " (Game)" : "";
    layout = is_qwerty ? " (QWERTY)" : " (Colemak)";
    sprintf(mode_string, "Mode: %s%s%s", os, mode, layout);

    if (record->event.pressed) {
      send_string(mode_string);
    } else {
      for (size_t i = 0; i < strlen(mode_string); i++)
        tap_code16(KC_BSPC);
    }
    return false;
  }

  if (!record->event.pressed) {
    switch (keycode) {
      case TO_DEFAULT:
        layer_move(0);
        return false;
      case TO_CODE:
        layer_move(1);
        return false;
      case OS_TOGGLE:
        is_windows = !is_windows;
        keymap_config.swap_lctl_lgui = is_windows ? true : false;
        eeconfig_update_user(keymap_config.raw);
        return false;
      case GAME_TOGGLE:
        is_game_mode = !is_game_mode;
        return false;
      case LAYOUT_SWAP:
        is_qwerty = !is_qwerty;
        return false;
    }
  }

  return true;
}
