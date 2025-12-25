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
  TO_CODE,
  TO_NUMBER,
  TO_DEFAULT
};

enum tap_dance_keycodes {
  TD_MODS_X,
  TD_MODS_QUOT,
  TD_MULTI,
};
