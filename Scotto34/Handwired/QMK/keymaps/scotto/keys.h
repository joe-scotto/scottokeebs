#pragma once
#include QMK_KEYBOARD_H

extern bool is_mac;

enum custom_keycodes {
  OS_TOGGLE = SAFE_RANGE,
  TO_CODE,
  TO_NUMBER,
  TO_DEFAULT
};
