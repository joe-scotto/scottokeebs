#include QMK_KEYBOARD_H
#include "keys.h"

// Tap dance declarations
enum tap_dance {
  TD_MODS_X,
  TD_MODS_DOT,
  TD_MODS_QUOT,
  TD_MODS_VOLU,
  TD_MULTI,
};

// Begin quad TD
typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_HOLD,
  TD_DOUBLE_HOLD,
  TD_TRIPLE_HOLD,
  TD_QUAD_HOLD,
  TD_SINGLE_TAP,
  TD_DOUBLE_TAP,
  TD_TRIPLE_TAP,
  TD_QUAD_TAP
} td_state_t;

static td_state_t td_state = TD_NONE;

td_state_t cur_dance(tap_dance_state_t *state) {
  switch (state->count) {
    case 1:
      if (state->interrupted || !state->pressed) {
        return TD_SINGLE_TAP;
      } else {
        return TD_SINGLE_HOLD;
      }

      break;
    case 2:
      if (state->interrupted || !state->pressed) {
        return TD_DOUBLE_TAP;
      } else {
        return TD_DOUBLE_HOLD;
      }

      break;
    case 3:
      if (state->interrupted || !state->pressed) {
        return TD_TRIPLE_TAP;
      } else {
        return TD_TRIPLE_HOLD;
      }

      break;
    case 4:
      if (state->interrupted || !state->pressed) {
        return TD_QUAD_TAP;
      } else {
        return TD_QUAD_HOLD;
      }

      break;
    default:
      return TD_UNKNOWN;
  }
}

void td_hold(bool press, uint8_t keycode, uint8_t mac_esc, uint8_t win_esc, uint8_t mac, uint8_t win) {
  uint8_t code = is_mac ? mac : win;

  // If not modifier key
  if (keycode == KC_ESC) {
    code = is_mac ? mac_esc : win_esc;
  }

  press ? register_code(code) : unregister_code(code);
}

void modfin(tap_dance_state_t *state, uint8_t keycode) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code(keycode);
      break;
    case TD_SINGLE_HOLD:
      td_hold(true, keycode, KC_RALT, KC_LCTL, KC_RGUI, KC_RCTL);
      break;
    case TD_DOUBLE_HOLD:
      td_hold(true, keycode, KC_RCTL, KC_RALT, KC_RALT, KC_RALT);
      break;
    case TD_TRIPLE_HOLD:
      td_hold(true, keycode, KC_RGUI, KC_RGUI, KC_RCTL, KC_RCTL);
      break;
    case TD_DOUBLE_TAP:
      is_mac ? tap_code16(RCMD(KC_SPC)) : tap_code(KC_RGUI);
      break;
    case TD_TRIPLE_TAP:
      is_mac ? tap_code16(RCTL(RCMD(KC_SPC))) : tap_code16(RGUI(KC_DOT));
      break;
    default:
      break;
  }
}

void modres(tap_dance_state_t *state, uint8_t keycode) {
  switch (td_state) {
    case TD_SINGLE_HOLD:
      td_hold(false, keycode, KC_RALT, KC_LCTL, KC_RGUI, KC_RCTL);
      break;
    case TD_DOUBLE_HOLD:
      td_hold(false, keycode, KC_RCTL, KC_RALT, KC_RALT, KC_RALT);
      break;
    case TD_TRIPLE_HOLD:
      td_hold(false, keycode, KC_RGUI, KC_RGUI, KC_RCTL, KC_RCTL);
      break;
    default:
      break;
  }
  td_state = TD_NONE;
}

// Macro for functions
#define TD_MODS(name, keycode)                                                                                         \
  void td_mods_##name##_finished(tap_dance_state_t *state, void *user_data) { modfin(state, keycode); }                \
  void td_mods_##name##_reset(tap_dance_state_t *state, void *user_data) { modres(state, keycode); }

// Create custom double and triple tap for dot and x to send xx xxx and .. ...

TD_MODS(x, KC_X)
TD_MODS(dot, KC_DOT)
TD_MODS(quot, KC_QUOT)
TD_MODS(volu, KC_VOLU)
TD_MODS(lalt, KC_ESC)

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MULTI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_lalt_finished, td_mods_lalt_reset),
    [TD_MODS_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_x_finished, td_mods_x_reset),
    [TD_MODS_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_dot_finished, td_mods_dot_reset),
    [TD_MODS_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_quot_finished, td_mods_quot_reset),
    [TD_MODS_VOLU] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_volu_finished, td_mods_volu_reset),
};
