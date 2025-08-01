/*
Copyright 2023 Joe Scotto

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
    TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI,
    TD_ESC_LCTL_LALT_WINDOWS_EMOJI
};

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI) :
        case TD(TD_ESC_LCTL_LALT_WINDOWS_EMOJI) :
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

void td_esc_lalt_lctl_spotlight_emoji_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LCTL); break;
        case TD_TRIPLE_HOLD: register_code(KC_RGUI); break;
        case TD_DOUBLE_TAP: tap_code16(RCMD(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(RCMD(KC_SPC))); break;
        default: break;
    }
}

void td_esc_lalt_lctl_spotlight_emoji_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_esc_lctl_lalt_windows_emoji_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code16(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: tap_code(KC_LGUI); break;
        case TD_TRIPLE_TAP: tap_code16(G(KC_DOT)); break;
        default: break;
    }
}

void td_esc_lctl_lalt_windows_emoji_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

 // Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_esc_lalt_lctl_spotlight_emoji_finished, td_esc_lalt_lctl_spotlight_emoji_reset),
    [TD_ESC_LCTL_LALT_WINDOWS_EMOJI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_esc_lctl_lalt_windows_emoji_finished, td_esc_lctl_lalt_windows_emoji_reset)
};
// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

// Onboard LED
#ifdef RGBLIGHT_ENABLE
    // Configure LED
    void keyboard_post_init_user(void) {
        // Initialize RGB to static black
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_BLACK);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    }

    // Change LED
    void housekeeping_task_user(void) {
        // Caps lock status
        if (host_keyboard_led_state().caps_lock) {
            rgblight_setrgb_at(4, 4, 0, 0);
        } else {
            // Layers
            switch (get_highest_layer(layer_state | default_layer_state)) {
                case 0:
                    rgblight_setrgb_at(4, 4, 4, 0);
                    break;
                case 1:
                    rgblight_setrgb_at(4, 4, 4, 0);
                    break;
                case 2:
                    rgblight_setrgb_at(4, 4, 4, 0);
                    break;
                case 3:
                    rgblight_setrgb_at(4, 4, 4, 0);
                    break;
                case 4:
                    rgblight_setrgb_at(0, 0, 4, 0);
                    break;
                case 5:
                    rgblight_setrgb_at(0, 4, 0, 0);
                    break;
                case 6:
                    rgblight_setrgb_at(0, 0, 4, 0);
                    break;
                case 7:
                    rgblight_setrgb_at(0, 0, 4, 0);
                    break;
                case 8:
                    rgblight_setrgb_at(0, 0, 4, 0);
                    break;
            }
        }
    }
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W, KC_F, KC_P, KC_G,                           KC_J,           KC_L,          KC_U,         KC_Y,   KC_BSPC,
        KC_A,         KC_R, KC_S, KC_T, KC_D,                           KC_H,           KC_N,          KC_E,         KC_I,   KC_O,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                           KC_K,           KC_M,          KC_COMMA,     KC_DOT, RSFT_T(KC_SLSH),
                                  TD(TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI), LGUI_T(KC_SPC), LT(1, KC_TAB), LT(2, KC_ENT)
    ),
    [1] = LAYOUT_split_3x5_2(
        KC_UNDS,         KC_MINS, KC_PLUS, KC_EQL,  KC_COLN, KC_GRV,   KC_MRWD, KC_MPLY, KC_MFFD, KC_DEL,
        KC_LCBR,         KC_LPRN, KC_RPRN, KC_RCBR, KC_PIPE, KC_ESC,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
        LSFT_T(KC_LBRC), KC_QUOT, KC_DQUO, KC_RBRC, KC_SCLN, KC_TILDE, KC_VOLD, KC_MUTE, KC_VOLU, RSFT_T(KC_BSLS),
                                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_CAPS, KC_BSPC,
        KC_1,    KC_2,  KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LSFT, KC_NO, KC_NO,   KC_NO,   MO(3),   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT_split_3x5_2(
        KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,            KC_NO,                 KC_NO,                     TO(5), TO(4), 
        KC_F1,  KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,            KC_F7,                 KC_F8,                     KC_F9, KC_F10,
        KC_F11, KC_NO, KC_NO, QK_BOOT, KC_TRNS, QK_HAPTIC_TOGGLE, QK_HAPTIC_BUZZ_TOGGLE, QK_HAPTIC_FEEDBACK_TOGGLE, KC_NO, KC_F12,
                              KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
    ),
    [4] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W, KC_F, KC_P, KC_G,                         KC_J,           KC_L,          KC_U,         KC_Y,   KC_BSPC,
        KC_A,         KC_R, KC_S, KC_T, KC_D,                         KC_H,           KC_N,          KC_E,         KC_I,   KC_O,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                         KC_K,           KC_M,          KC_COMMA,     KC_DOT, RSFT_T(KC_SLSH),
                                  TD(TD_ESC_LCTL_LALT_WINDOWS_EMOJI), LCTL_T(KC_SPC), LT(6, KC_TAB), LT(7, KC_ENT)
    ),
    [5] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_F, KC_P, KC_G,    KC_J,   KC_L,          KC_U,         KC_Y,   KC_BSPC,
        KC_A, KC_R, KC_S, KC_T, KC_D,    KC_H,   KC_N,          KC_E,         KC_I,   KC_O,
        KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_K,   KC_M,          KC_COMMA,     KC_DOT, KC_SLSH,
                                KC_LCTL, KC_SPC, LT(6, KC_TAB), LT(7, KC_ENT)
    ),
    [6] = LAYOUT_split_3x5_2(
        KC_UNDS,         KC_MINS, KC_PLUS, KC_EQL,  KC_COLN, KC_GRV,   KC_MRWD, KC_MPLY, KC_MFFD, KC_DEL,
        KC_LCBR,         KC_LPRN, KC_RPRN, KC_RCBR, KC_PIPE, KC_ESC,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
        LSFT_T(KC_LBRC), KC_QUOT, KC_DQUO, KC_RBRC, KC_SCLN, KC_TILDE, KC_VOLD, KC_MUTE, KC_VOLU, RSFT_T(KC_BSLS),
                                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [7] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_CAPS, KC_BSPC,
        KC_1,    KC_2,  KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LSFT, KC_NO, KC_NO,   KC_NO,   MO(8),   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [8] = LAYOUT_split_3x5_2(
        KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, TO(4), TO(5), TO(0), 
        KC_F1,  KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,
        KC_F11, KC_NO, KC_NO, QK_BOOT, KC_TRNS, KC_NO,   KC_NO, KC_NO, KC_NO, KC_F12,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
