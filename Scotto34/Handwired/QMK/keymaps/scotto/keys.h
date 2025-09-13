#pragma once
#include QMK_KEYBOARD_H

extern bool is_mac;
extern bool is_game_mode;

enum custom_keycodes {
  OS_TOGGLE = SAFE_RANGE,
  GAME_TOGGLE,
  TO_CODE,
  TO_NUMBER,
  TO_DEFAULT
};

enum tap_dance_keycodes {
  TD_MODS_X,
  TD_MODS_DOT,
  TD_MODS_QUOT,
  TD_MODS_VOLU,
  TD_MULTI,
};
