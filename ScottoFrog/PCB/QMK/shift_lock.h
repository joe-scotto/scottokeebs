#pragma once
#include QMK_KEYBOARD_H

// Tap dance enum
enum {
  SFT_LOCK
};

// Tap dance state types
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

// Function declarations
td_state_t cur_dance(tap_dance_state_t *state);
void sft_lock_finished(tap_dance_state_t *state, void *user_data);
void sft_lock_reset(tap_dance_state_t *state, void *user_data);
