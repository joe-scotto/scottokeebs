/*
Copyright 2025 Joe Scotto

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Tap dance declarations
enum {
  TD_MODS_X,
  TD_MODS_DOT,
  TD_MODS_QUOT,
  TD_MODS_VOLU,
  TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI,
  TD_ESC_LCTL_LALT_WINDOWS_EMOJI,
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

void td_esc_lalt_lctl_spotlight_emoji_finished(tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code(KC_ESC);
      break;
    case TD_SINGLE_HOLD:
      register_code(KC_LALT);
      break;
    case TD_DOUBLE_HOLD:
      register_code(KC_LCTL);
      break;
    case TD_TRIPLE_HOLD:
      register_code(KC_RGUI);
      break;
    case TD_DOUBLE_TAP:
      tap_code16(RCMD(KC_SPC));
      break;
    case TD_TRIPLE_TAP:
      tap_code16(C(RCMD(KC_SPC)));
      break;
    default:
      break;
  }
}

void td_esc_lalt_lctl_spotlight_emoji_reset(tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case TD_SINGLE_TAP:
      unregister_code(KC_ESC);
      break;
    case TD_SINGLE_HOLD:
      unregister_code(KC_LALT);
      break;
    case TD_DOUBLE_HOLD:
      unregister_code(KC_LCTL);
      break;
    case TD_TRIPLE_HOLD:
      unregister_code(KC_RGUI);
      break;
    default:
      break;
  }
  td_state = TD_NONE;
}

void td_esc_lctl_lalt_windows_emoji_finished(tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code16(KC_ESC);
      break;
    case TD_SINGLE_HOLD:
      register_code(KC_LCTL);
      break;
    case TD_DOUBLE_HOLD:
      register_code(KC_LALT);
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_LGUI);
      break;
    case TD_TRIPLE_TAP:
      tap_code16(G(KC_DOT));
      break;
    default:
      break;
  }
}

void td_esc_lctl_lalt_windows_emoji_reset(tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case TD_SINGLE_TAP:
      unregister_code(KC_ESC);
      break;
    case TD_SINGLE_HOLD:
      unregister_code(KC_LCTL);
      break;
    case TD_DOUBLE_HOLD:
      unregister_code(KC_LALT);
      break;
    default:
      break;
  }
  td_state = TD_NONE;
}

void modfin(tap_dance_state_t *state, uint8_t keycode) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code(keycode);
      break;
    case TD_SINGLE_HOLD:
      register_code(KC_RGUI);
      break;
    case TD_DOUBLE_HOLD:
      register_code(KC_RALT);
      break;
    case TD_TRIPLE_HOLD:
      register_code(KC_RCTL);
      break;
    case TD_DOUBLE_TAP:
      tap_code16(G(KC_SPC));
      break;
    case TD_TRIPLE_TAP:
      tap_code16(C(G(KC_SPC)));
      break;
    default:
      break;
  }
}

void modres(tap_dance_state_t *state, uint8_t keycode) {
  switch (td_state) {
    case TD_SINGLE_TAP:
      unregister_code(keycode);
      break;
    case TD_SINGLE_HOLD:
      unregister_code(KC_RGUI);
      break;
    case TD_DOUBLE_HOLD:
      unregister_code(KC_RALT);
      break;
    case TD_TRIPLE_HOLD:
      unregister_code(KC_RCTL);
      break;
    default:
      break;
  }
  td_state = TD_NONE;
}

// Macro for functions
#define TD_MODS(name, keycode)                                                                     \
  void td_mods_##name##_finished(tap_dance_state_t *state, void *user_data) {                      \
    modfin(state, keycode);                                                                        \
  }                                                                                                \
  void td_mods_##name##_restart(tap_dance_state_t *state, void *user_data) {                       \
    modres(state, keycode);                                                                        \
  }

// Create custom double and triple tap for dot and x to send xx xxx and .. ...

TD_MODS(x, KC_X)
TD_MODS(dot, KC_DOT)
TD_MODS(quot, KC_QUOT)
TD_MODS(volu, KC_VOLU)

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, td_esc_lalt_lctl_spotlight_emoji_finished, td_esc_lalt_lctl_spotlight_emoji_reset),
    [TD_ESC_LCTL_LALT_WINDOWS_EMOJI] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, td_esc_lctl_lalt_windows_emoji_finished, td_esc_lctl_lalt_windows_emoji_reset),
    [TD_MODS_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_x_finished, td_mods_x_restart),
    [TD_MODS_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_dot_finished, td_mods_dot_restart),
    [TD_MODS_QUOT] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_quot_finished, td_mods_quot_restart),
    [TD_MODS_VOLU] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_volu_finished, td_mods_volu_restart),
};
