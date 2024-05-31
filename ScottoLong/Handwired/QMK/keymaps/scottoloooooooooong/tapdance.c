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

// Tap dance declarations
enum {
    TD_MODS_X,
    TD_MODS_DOT,
    TD_MODS_QUOT,
    TD_MODS_MUTE,
    TD_MODS_COMMA,
    TD_MODS_VOLD
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
    switch(state->count) {
        case 1 :
            if (state->interrupted || !state->pressed) {
                return TD_SINGLE_TAP;
            } else {
                return TD_SINGLE_HOLD;
            }

            break;
        case 2 :
            if (state->interrupted || !state->pressed) {
                return TD_DOUBLE_TAP;
            } else {
                return TD_DOUBLE_HOLD;
            }

            break;
        case 3 :
            if (state->interrupted || !state->pressed) {
                return TD_TRIPLE_TAP;
            } else {
                return TD_TRIPLE_HOLD;
            }

            break;
        case 4 :
            if (state->interrupted || !state->pressed) {
                return TD_QUAD_TAP;
            } else {
                return TD_QUAD_HOLD;
            }

            break;
        default :
            return TD_UNKNOWN;
    }
}

void td_mods_x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_X); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(G(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(G(KC_SPC))); break;
        default: break;
    }
}

void td_mods_x_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_mods_dot_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_DOT); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(G(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(G(KC_SPC))); break;
        default: break;
    }
}

void td_mods_dot_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_mods_quot_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(G(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(G(KC_SPC))); break;
        default: break;
    }
}

void td_mods_quot_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_mods_mute_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_MUTE); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(G(KC_SPC)); break;
        case TD_TRIPLE_TAP: tap_code16(C(G(KC_SPC))); break;
        default: break;
    }
}

void td_mods_mute_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_MUTE); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_LCTL); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_mods_comma_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_COMMA); break;
        case TD_DOUBLE_TAP: tap_code(KC_ENT); break;
        case TD_TRIPLE_TAP: tap_code(KC_TAB); break;
        case TD_QUAD_TAP: tap_code(KC_ESC); break;
        default: break;
    }
}

void td_mods_comma_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_COMMA); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ENT); break;
        case TD_TRIPLE_TAP: unregister_code(KC_TAB); break;
        case TD_QUAD_TAP: unregister_code(KC_ESC); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void td_mods_vold_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_VOLD); break;
        case TD_DOUBLE_TAP: tap_code(KC_ENT); break;
        case TD_TRIPLE_TAP: tap_code(KC_TAB); break;
        case TD_QUAD_TAP: tap_code(KC_ESC); break;
        default: break;
    }
}

void td_mods_vold_restart(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_VOLD); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ENT); break;
        case TD_TRIPLE_TAP: unregister_code(KC_TAB); break;
        case TD_QUAD_TAP: unregister_code(KC_ESC); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

 // Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MODS_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_x_finished, td_mods_x_restart),
    [TD_MODS_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_dot_finished, td_mods_dot_restart),
    [TD_MODS_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_quot_finished, td_mods_quot_restart),
    [TD_MODS_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_mute_finished, td_mods_mute_restart),
    [TD_MODS_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_comma_finished, td_mods_comma_restart), 
    [TD_MODS_VOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mods_vold_finished, td_mods_vold_restart), 
};