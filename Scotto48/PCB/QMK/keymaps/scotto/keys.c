#include "keys.h"
#include QMK_KEYBOARD_H

#define SCALE(x) ((x * RGB_BRIGHTNESS) / 255)

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

void flash_led(uint8_t r, uint8_t g, uint8_t b) {
  rgblight_enable_noeeprom();
  rgblight_setrgb(SCALE(r), SCALE(g), SCALE(b));
  wait_ms(333);
  rgblight_reload_from_eeprom();
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
      case RSFT_T(KC_Z):
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
        flash_led(255, 255, 0); // Yellow
        layer_move(get_highest_layer(layer_state) == 1 ? 0 : 1);
        return false;

      case TO_NUMBER:
        flash_led(0, 0, 255); // Blue
        layer_move(get_highest_layer(layer_state) == 2 ? 0 : 2);
        return false;

      case TO_FUNCTION:
        flash_led(255, 64, 0); // Orange
        layer_move(get_highest_layer(layer_state) == 3 ? 0 : 3);
        return false;

      case TO_MOUSE:
        flash_led(128, 0, 255); // Purple
        layer_move(get_highest_layer(layer_state) == 4 ? 0 : 4);
        return false;

      case OS_TOGGLE:
        flash_led(user_config.is_windows ? 255 : 0,
                  user_config.is_windows ? 255 : 255,
                  user_config.is_windows ? 255 : 0); // White -> Green or Green -> White

        user_config.is_windows = !user_config.is_windows;
        keymap_config.swap_lctl_lgui = user_config.is_windows;
        eeconfig_update_user(user_config.raw);
        return false;

      case GAME_TOGGLE:
        user_config.is_game_mode = !user_config.is_game_mode;
        eeconfig_update_user(user_config.raw);

        if (user_config.is_game_mode) {
          flash_led(255, 0, 0); // Entering game mode -> Red
        } else if (user_config.is_windows) {
          flash_led(0, 255, 0); // Back to Windows -> Green
        } else {
          flash_led(255, 255, 255); // Back to Mac -> White
        }

        return false;
      case LAYOUT_SWAP:
        user_config.is_qwerty = !user_config.is_qwerty;
        flash_led(255, 105, 180); // Pink
        eeconfig_update_user(user_config.raw);
        return false;
      case HARD_BOOT:
        eeconfig_init_user();
        reset_keyboard();
        return false;
      case KC_BACK:
        tap_code(KC_BSPC);
        return false;
    }
  }

  return true;
}

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_MULTI):
    case TD(TD_MODS_X):
    case TD(TD_MODS_QUOT):
    case LGUI_T(KC_SPC):
    case LT(1, KC_TAB):
    case LT(2, KC_ENT):
      return 200;
    default:
      return TAPPING_TERM;
  }
};

// OS Detection
bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
  switch (detected_os) {
    case OS_MACOS:
    case OS_IOS:
      user_config.is_windows = false;
      keymap_config.swap_lctl_lgui = false;
      eeconfig_update_user(user_config.raw);
      break;
    case OS_WINDOWS:
      user_config.is_windows = true;
      keymap_config.swap_lctl_lgui = true;
      break;
    case OS_LINUX:
      user_config.is_windows = true;
      keymap_config.swap_lctl_lgui = true;
      break;
    case OS_UNSURE:
      user_config.is_windows = false;
      keymap_config.swap_lctl_lgui = false;
      eeconfig_update_user(user_config.raw);
      break;
  }

  return true;
}
