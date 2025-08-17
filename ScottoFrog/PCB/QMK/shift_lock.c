#include "shift_lock.h"
#include QMK_KEYBOARD_H // include your keyboard’s QMK header if needed

// static state variables
static td_tap_t xtap_state = {.is_press_action = true, .state = TD_NONE};
static bool shift_locked = false;

// determine tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return TD_SINGLE_TAP;
    } else {
      return TD_SINGLE_HOLD;
    }
  }
  return TD_UNKNOWN;
}

// finished callback
void sft_lock_finished(tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP:
      if (shift_locked) {
        unregister_code(KC_LSFT);
        shift_locked = false;
      } else {
        register_code(KC_LSFT);
        shift_locked = true;
      }
      break;
    case TD_SINGLE_HOLD:
      register_code(KC_LSFT);
      break;
    default:
      break;
  }
}

// reset callback
void sft_lock_reset(tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_HOLD:
      unregister_code(KC_LSFT);
      break;
    default:
      break;
  }
  xtap_state.state = TD_NONE;
}

// expose tap dance action
tap_dance_action_t tap_dance_actions[] = {
    [SFT_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_lock_finished, sft_lock_reset),
};
