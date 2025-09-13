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
