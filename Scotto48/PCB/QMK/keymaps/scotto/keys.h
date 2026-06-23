#pragma once
#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool is_windows;
    bool is_game_mode;
    bool is_qwerty;
  };
} user_config_t;

user_config_t user_config;
enum custom_keycodes {
  OS_TOGGLE = SAFE_RANGE,
  GAME_TOGGLE,
  MODE_CHECK,
  LAYOUT_SWAP,
  HARD_BOOT,
  TO_DEFAULT,
  TO_CODE,
  TO_NUMBER,
  TO_FUNCTION,
  TO_MOUSE,
  KC_BACK
};

enum tap_dance_keycodes {
  TD_MODS_X,
  TD_MODS_QUOT,
  TD_MULTI,
};

enum combos {
  TAB_COMBO,
  ENTER_COMBO,
  SPACE_COMBO,
  MIDDLE_CLICK_COMBO,
  WHEEL_UP_COMBO,
  WHEEL_DOWN_COMBO,
  WHEEL_LEFT_COMBO,
  WHEEL_RIGHT_COMBO,
  DEFAULT_COMBO,
  CODE_COMBO,
  NUMBER_COMBO,
  FUNCTION_COMBO,
  MOUSE_COMBO
};
