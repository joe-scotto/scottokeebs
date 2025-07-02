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
#include "tapdance.c"
#include "combos.c"

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_LGUI_ESC_SPOTLIGHT_EMOJI) :
        case TD(TD_MODS_X) :
        case TD(TD_MODS_DOT) :
        case TD(TD_MODS_QUOT) :
        case TD(TD_MODS_MUTE) :
        case TD(TD_MODS_COMMA) :
        case TD(TD_MODS_VOLD) :
        case LGUI_T(KC_SPC) :
        case LT(1, KC_SPC) :
        case LT(1, KC_TAB) :
        case LT(2, KC_ENT) :
      return 200;
    default:
      return TAPPING_TERM;
  }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x10_3(
        KC_Q,         KC_W,                            KC_F, KC_P,  KC_G,          KC_J, KC_L, KC_U,              KC_Y,            KC_BSPC,
        KC_A,         KC_R,                            KC_S, KC_T,  KC_D,          KC_H, KC_N, KC_E,              KC_I,            KC_O,
        LSFT_T(KC_Z), TD(TD_MODS_X),                   KC_C, KC_V,  KC_B,          KC_K, KC_M, TD(TD_MODS_COMMA), TD(TD_MODS_DOT), RSFT_T(KC_SLSH),
                      TD(TD_LGUI_ESC_SPOTLIGHT_EMOJI),              LT(2, KC_SPC),                                LT(1, KC_TAB)
    ),
    [1] = LAYOUT_ortho_3x10_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_CAPS, KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSFT_T(KC_SLSH),
                 KC_TRNS,                   KC_TRNS,                            KC_TRNS
    ),
    [2] = LAYOUT_ortho_3x10_3(
        KC_UNDS,         KC_MINS,          KC_PLUS, KC_EQL,  KC_COLN, KC_GRV,   KC_MRWD, KC_MPLY,          KC_MFFD, KC_DEL,
        KC_LCBR,         KC_LPRN,          KC_RPRN, KC_RCBR, KC_PIPE, KC_ESC,   KC_LEFT, KC_UP,            KC_DOWN, KC_RGHT,
        LSFT_T(KC_LBRC), TD(TD_MODS_QUOT), KC_DQUO, KC_RBRC, KC_SCLN, KC_TILDE, TD(TD_MODS_VOLD), TD(TD_MODS_MUTE), KC_VOLU, RSFT_T(KC_BSLS),
                         KC_TRNS,                            KC_TRNS,                                               KC_TRNS
    ),
    [3] = LAYOUT_ortho_3x10_3(
        KC_F11,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_F12, 
        KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_TRNS, KC_TRNS, TO(4), QK_BOOT, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS,                 KC_TRNS,                          KC_TRNS
    )
};
