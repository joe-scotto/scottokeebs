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

enum custom_keycodes {
    TO_NUMBER = SAFE_RANGE,
    TO_DEFAULT
};

// Combos
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab_number_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM tab_code_combo[] = {KC_UNDS, KC_MINS, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_Y, KC_BSPC, COMBO_END};
const uint16_t PROGMEM enter_number_combo[] = {KC_CAPS, KC_BSPC, COMBO_END};
const uint16_t PROGMEM enter_code_combo[] = {KC_MFFD, KC_DEL, COMBO_END};
const uint16_t PROGMEM number_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM number_number_combo[] = {KC_EXLM, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(tab_number_combo, KC_TAB),
    COMBO(tab_code_combo, KC_TAB),
    COMBO(enter_combo, KC_ENT),
    COMBO(enter_number_combo, KC_ENT),
    COMBO(enter_code_combo, KC_ENT),
    COMBO(number_combo, TO_NUMBER),
    COMBO(number_number_combo, TO_DEFAULT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO_NUMBER :
            if (record->event.pressed) {
                layer_move(1);
            }
            return false;
            break;
        case TO_DEFAULT :
            if (record->event.pressed) {
                layer_move(0);  
            }
            return false; 
            break;
        default:
            return true; 
    }
}