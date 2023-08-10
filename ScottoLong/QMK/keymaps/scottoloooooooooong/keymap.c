/*
Copyright 2022 Joe Scotto

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
    TD_MODS
};

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_MODS) :
        case LGUI_T(KC_SPC) :
        case LT(1, KC_SPC) :
        case LT(1, KC_TAB) :
        case LT(2, KC_ENT) :
      return 200;
    default:
      return TAPPING_TERM;
  }
};

// Begin quad TD
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_HOLD,
    TD_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return TD_DOUBLE_TAP;
        } else {
            return TD_DOUBLE_HOLD;
        }
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
        return TD_TRIPLE_TAP;
        } else {
            return TD_TRIPLE_HOLD;
        }
    }   

    return TD_UNKNOWN;
}

void td_mods_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_COMMA); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(G(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(G(KC_SPC))); break;
        default: break;
    }
}

void td_mods_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}
 // Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MODS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_finished, td_mods_restart)
};

enum custom_keycodes {
    TO_NUMBER = SAFE_RANGE,
    TO_DEFAULT
};

// Combos
const uint16_t PROGMEM tab_combo[] = {KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM tab_number_combo[] = {KC_PERC, KC_CIRC, COMBO_END};
const uint16_t PROGMEM tab_code_combo[] = {KC_COLN, KC_GRV, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM enter_number_combo[] = {MO(3), KC_K, COMBO_END};
const uint16_t PROGMEM enter_code_combo[] = {KC_SCLN, KC_TILDE, COMBO_END};
const uint16_t PROGMEM number_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM number_number_combo[] = {KC_EXLM, KC_BSPC, COMBO_END};
const uint16_t PROGMEM next_window_combo[] = {KC_H, KC_BSPC, COMBO_END};
const uint16_t PROGMEM last_window_combo[] = {KC_D, KC_Q, COMBO_END};
combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(tab_number_combo, KC_TAB),
    COMBO(tab_code_combo, KC_TAB),
    COMBO(enter_combo, KC_ENT),
    COMBO(enter_number_combo, KC_ENT),
    COMBO(enter_code_combo, KC_ENT),
    COMBO(number_combo, TO_NUMBER),
    COMBO(number_number_combo, TO_DEFAULT),
    COMBO(next_window_combo, LGUI(KC_TAB)),
    COMBO(last_window_combo, LSG(KC_TAB))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TO_NUMBER :
      if (record->event.pressed) {
        layer_move(1);
      }
      return false; // Skip all further processing of this key
      break;
    case TO_DEFAULT :
        if (record->event.pressed) {
        layer_move(0);  
      }
      return false; // Skip all further processing of this key
    break;
    case LALT_T(KC_DQUO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO); // Send KC_DQUO on tap
                return false;
            }
            return true;
    break;
    default:
      return true; // Process all other keycodes normally
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x10_3(
        KC_Q,         KC_W,         KC_F,         KC_P,          KC_G, KC_J, KC_L,         KC_U,             KC_Y,           KC_BSPC,
        KC_A,         KC_R,         KC_S,         KC_T,          KC_D, KC_H, KC_N,         KC_E,             KC_I,           KC_O,
        LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V),  KC_B, KC_K, LGUI_T(KC_M), LALT_T(KC_COMMA), LCTL_T(KC_DOT), RSFT_T(KC_SLSH),
        KC_NO,                                    LT(2, KC_SPC),                                                             KC_NO
    ),
    [1] = LAYOUT_ortho_3x10_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_CAPS, KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSFT_T(KC_SLSH),
        KC_TRNS,                   KC_TRNS,                                              KC_TRNS
    ),
    [2] = LAYOUT_ortho_3x10_3(
        KC_UNDS,         KC_MINS,         KC_PLUS,         KC_EQL,          KC_COLN, KC_GRV,   KC_MRWD, KC_MPLY, KC_MFFD, KC_DEL,
        KC_LCBR,         KC_LPRN,         KC_RPRN,         KC_RCBR,         KC_PIPE, KC_ESC,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
        LSFT_T(KC_LBRC), LCTL_T(KC_QUOT), LALT_T(KC_DQUO), LGUI_T(KC_RBRC), KC_SCLN, KC_TILDE, KC_TRNS, KC_TRNS, KC_TRNS, RSFT_T(KC_BSLS),
        KC_TRNS,                                           KC_TRNS,                                                       KC_TRNS
    ),
    [3] = LAYOUT_ortho_3x10_3(
        KC_F11,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_F12, 
        KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_TRNS, KC_TRNS, TO(4), QK_BOOT, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,                 KC_TRNS,                                            KC_TRNS
    ),
    [4] = LAYOUT_ortho_3x10_3(
        KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U,     KC_Y,   KC_BSPC,
        KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E,     KC_I,   KC_O,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMMA, KC_ESC, TO(0),
        KC_NO,                  KC_SPC,                             KC_NO
    )
};
