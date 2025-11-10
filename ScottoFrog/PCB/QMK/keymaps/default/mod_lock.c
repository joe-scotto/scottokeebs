#include QMK_KEYBOARD_H

enum tap_dance {
  SFT_LOCK,
  CMD_LOCK,
  CTRL_LOCK,
  ALT_LOCK
};

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_HOLD,
  TD_SINGLE_TAP,
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

static td_tap_t xtap_state = {.is_press_action = true, .state = TD_NONE};
static bool shift_locked = false;
static bool cmd_locked = false;
static bool ctrl_locked = false;
static bool alt_locked = false;

// Determine state of tap dance
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

// Shift lock
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

// CMD lock
void cmd_lock_finished(tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP:
      if (cmd_locked) {
        unregister_code(KC_LGUI);
        cmd_locked = false;
      } else {
        register_code(KC_LGUI);
        cmd_locked = true;
      }
      break;
    default:
      break;
  }
}

// CTRL lock
void ctrl_lock_finished(tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP:
      if (ctrl_locked) {
        unregister_code(KC_LCTL);
        ctrl_locked = false;
      } else {
        register_code(KC_LCTL);
        ctrl_locked = true;
      }
      break;
    default:
      break;
  }
}

// ALT lock
void alt_lock_finished(tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP:
      if (alt_locked) {
        unregister_code(KC_LALT);
        alt_locked = false;
      } else {
        register_code(KC_LALT);
        alt_locked = true;
      }
      break;
    default:
      break;
  }
}

// Tap dance end
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

void generic_reset(tap_dance_state_t *state, void *user_data) { xtap_state.state = TD_NONE; }

// Define tap dance actions
tap_dance_action_t tap_dance_actions[] = {
    [SFT_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_lock_finished, sft_lock_reset),
    [CMD_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cmd_lock_finished, generic_reset),
    [CTRL_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_lock_finished, generic_reset),
    [ALT_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_lock_finished, generic_reset),
};
