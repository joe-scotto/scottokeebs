#include "keys.h"
#include QMK_KEYBOARD_H

// Mode check
char mode_string[32];
char *os;
char *mode;
char *layout;

void eeconfig_init_user(void) {
  user_config.raw = 0;
  eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  keymap_config.swap_lctl_lgui = user_config.is_windows;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t remapped_keycode = KC_NO;

  if (user_config.is_qwerty) {
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

  if (user_config.is_game_mode) {
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
      case RGUI_T(KC_DOT):
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
    os = user_config.is_windows ? "Windows" : "Mac";
    mode = user_config.is_game_mode ? " (Game)" : "";
    layout = user_config.is_qwerty ? " (QWERTY)" : " (Colemak)";
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
        user_config.is_windows = !user_config.is_windows;
        keymap_config.swap_lctl_lgui = user_config.is_windows ? true : false;
        eeconfig_update_user(user_config.raw);
        return false;
      case GAME_TOGGLE:
        user_config.is_game_mode = !user_config.is_game_mode;
        eeconfig_update_user(user_config.raw);
        return false;
      case LAYOUT_SWAP:
        user_config.is_qwerty = !user_config.is_qwerty;
        eeconfig_update_user(user_config.raw);
        return false;
      case HARD_BOOT:
        eeconfig_init_user();
        reset_keyboard();
        return false;
    }
  }

  return true;
}
