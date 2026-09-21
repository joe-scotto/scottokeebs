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
  TD_LAYERS,
};

enum combos {
  G_COMBO,
  D_COMBO,
  B_COMBO,
  J_COMBO,
  H_COMBO,
  K_COMBO,

  // CODE
  COLN_COMBO,
  PIPE_COMBO,
  SCLN_COMBO,
  GRV_COMBO,
  ESC_COMBO,
  TILDE_COMBO,

  // NUMBER
  PERC_COMBO,
  FIVE_COMBO,
  CIRC_COMBO,
  SIX_COMBO,

  // FUNCTION
  F5_COMBO,
  F6_COMBO,

  TAB_COMBO,
  ENTER_COMBO,
  SPACE_COMBO,
};

enum layers {
  BASE,
  GAME,
  CODE,
  NUMBER,
  FUNCTION,
  MOUSE
};
