#include "keys.h"
#include QMK_KEYBOARD_H

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

typedef struct {
  bool is_held;
} td_tap_t;

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

// Macro to generate tap-dance functions, including long-press = number
#define TD_4(name, kc1, kc2, kc3, kc4, kc_num)                                                                         \
  void td_##name##_finished(tap_dance_state_t *state, void *user_data) {                                               \
    td_state = cur_dance(state);                                                                                       \
    switch (td_state) {                                                                                                \
      case TD_SINGLE_TAP:                                                                                              \
        register_code(kc1);                                                                                            \
        break;                                                                                                         \
      case TD_SINGLE_HOLD:                                                                                             \
        register_code(kc_num);                                                                                         \
        break;                                                                                                         \
      case TD_DOUBLE_TAP:                                                                                              \
        register_code(kc2);                                                                                            \
        break;                                                                                                         \
      case TD_TRIPLE_TAP:                                                                                              \
        register_code(kc3);                                                                                            \
        break;                                                                                                         \
      case TD_QUAD_TAP:                                                                                                \
        register_code(kc4);                                                                                            \
        break;                                                                                                         \
      default:                                                                                                         \
        break;                                                                                                         \
    }                                                                                                                  \
  }                                                                                                                    \
                                                                                                                       \
  void td_##name##_reset(tap_dance_state_t *state, void *user_data) {                                                  \
    td_state = cur_dance(state);                                                                                       \
    switch (td_state) {                                                                                                \
      case TD_SINGLE_TAP:                                                                                              \
        unregister_code(kc1);                                                                                          \
        break;                                                                                                         \
      case TD_SINGLE_HOLD:                                                                                             \
        unregister_code(kc_num);                                                                                       \
        break;                                                                                                         \
      case TD_DOUBLE_TAP:                                                                                              \
        unregister_code(kc2);                                                                                          \
        break;                                                                                                         \
      case TD_TRIPLE_TAP:                                                                                              \
        unregister_code(kc3);                                                                                          \
        break;                                                                                                         \
      case TD_QUAD_TAP:                                                                                                \
        unregister_code(kc4);                                                                                          \
        break;                                                                                                         \
      default:                                                                                                         \
        break;                                                                                                         \
    }                                                                                                                  \
    td_state = TD_NONE;                                                                                                \
  }

// Tap-dance key definitions (letters + hold = number)
TD_4(1, KC_DOT, KC_COMMA, KC_MINUS, KC_NO, KC_1);
TD_4(2, KC_A, KC_B, KC_C, KC_NO, KC_2);
TD_4(3, KC_D, KC_E, KC_F, KC_NO, KC_3);
TD_4(4, KC_G, KC_H, KC_I, KC_NO, KC_4);
TD_4(5, KC_J, KC_K, KC_L, KC_NO, KC_5);
TD_4(6, KC_M, KC_N, KC_O, KC_NO, KC_6);
TD_4(7, KC_P, KC_Q, KC_R, KC_S, KC_7);
TD_4(8, KC_T, KC_U, KC_V, KC_NO, KC_8);
TD_4(9, KC_W, KC_X, KC_Y, KC_Z, KC_9);

// Register tap-dance actions
tap_dance_action_t tap_dance_actions[] = {
    [TD_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_1_finished, td_1_reset),
    [TD_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_2_finished, td_2_reset),
    [TD_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_3_finished, td_3_reset),
    [TD_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_4_finished, td_4_reset),
    [TD_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_5_finished, td_5_reset),
    [TD_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_6_finished, td_6_reset),
    [TD_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_7_finished, td_7_reset),
    [TD_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_8_finished, td_8_reset),
    [TD_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_9_finished, td_9_reset),
};
