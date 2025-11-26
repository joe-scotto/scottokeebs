#include QMK_KEYBOARD_H

enum tap_dance_keycodes {
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_0,
};

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

// Determine current tap-dance state
td_state_t cur_dance(tap_dance_state_t *state) {
  switch (state->count) {
    case 1:
      return (state->interrupted || !state->pressed) ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
    case 2:
      return (state->interrupted || !state->pressed) ? TD_DOUBLE_TAP : TD_DOUBLE_HOLD;
    case 3:
      return (state->interrupted || !state->pressed) ? TD_TRIPLE_TAP : TD_TRIPLE_HOLD;
    case 4:
      return (state->interrupted || !state->pressed) ? TD_QUAD_TAP : TD_QUAD_HOLD;
    default:
      return TD_UNKNOWN;
  }
}

void symbol_finished(tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code(KC_QUOTE);
      break;
    case TD_SINGLE_HOLD:
      tap_code(KC_1);
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_COMMA);
      break;
    case TD_TRIPLE_TAP:
      tap_code(KC_SEMICOLON);
      break;
    case TD_QUAD_TAP:
      tap_code(KC_SLSH);
      break;
    default:
      break;
  }
}

void space_finished(tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      tap_code(KC_SPC);
      break;
    case TD_SINGLE_HOLD:
      tap_code(KC_0);
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_DOT);
      break;
    case TD_TRIPLE_TAP:
      tap_code16(S(KC_SLSH));
      break;
    case TD_QUAD_TAP:
      tap_code16(S(KC_1));
      break;
    default:
      break;
  }
}

void td_reset(tap_dance_state_t *state, void *user_data) { td_state = TD_NONE; }

static void t9_handler(td_state_t state, bool press, uint16_t kc1, uint16_t kc2, uint16_t kc3, uint16_t kc4,
                       uint16_t kc_num) {
  uint16_t key = KC_NO;
  switch (state) {
    case TD_SINGLE_TAP:
      key = kc1;
      break;
    case TD_SINGLE_HOLD:
      key = kc_num;
      break;
    case TD_DOUBLE_TAP:
      key = kc2;
      break;
    case TD_TRIPLE_TAP:
      key = kc3;
      break;
    case TD_QUAD_TAP:
      key = kc4;
      break;
    default:
      return;
  }

  if (key != KC_NO) {
    if (press)
      register_code(key);
    else
      unregister_code(key);
  }
}

// Helper macro for T9 declaration
#define T9(name, kc1, kc2, kc3, kc4, kc_num)                                                                           \
  void td_##name##_finished(tap_dance_state_t *state, void *user_data) {                                               \
    td_state = cur_dance(state);                                                                                       \
    t9_handler(td_state, true, kc1, kc2, kc3, kc4, kc_num);                                                            \
  }                                                                                                                    \
                                                                                                                       \
  void td_##name##_reset(tap_dance_state_t *state, void *user_data) {                                                  \
    t9_handler(td_state, false, kc1, kc2, kc3, kc4, kc_num);                                                           \
    td_state = TD_NONE;                                                                                                \
  }

// Tap-dance key definitions
T9(2, KC_A, KC_B, KC_C, KC_NO, KC_2);
T9(3, KC_D, KC_E, KC_F, KC_NO, KC_3);
T9(4, KC_G, KC_H, KC_I, KC_NO, KC_4);
T9(5, KC_J, KC_K, KC_L, KC_NO, KC_5);
T9(6, KC_M, KC_N, KC_O, KC_NO, KC_6);
T9(7, KC_P, KC_Q, KC_R, KC_S, KC_7);
T9(8, KC_T, KC_U, KC_V, KC_NO, KC_8);
T9(9, KC_W, KC_X, KC_Y, KC_Z, KC_9);

tap_dance_action_t tap_dance_actions[] = {
    [TD_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, symbol_finished, td_reset),
    [TD_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_2_finished, td_2_reset),
    [TD_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_3_finished, td_3_reset),
    [TD_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_4_finished, td_4_reset),
    [TD_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_5_finished, td_5_reset),
    [TD_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_6_finished, td_6_reset),
    [TD_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_7_finished, td_7_reset),
    [TD_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_8_finished, td_8_reset),
    [TD_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_9_finished, td_9_reset),
    [TD_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, td_reset),
};
