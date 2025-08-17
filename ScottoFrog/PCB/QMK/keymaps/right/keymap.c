/*
Copyright 2025 Joe Scotto

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
#include "shift_lock.c"

enum combos {
  GREEN_TAB,
  GREEN_APOSTROPHE,
  GREEN_B,
  GREEN_M,
  GREEN_J,
  GREEN_Q,
  GREEN_Z,
  GREEN_L,
  GREEN_C,
  GREEN_V,
  GREEN_CMD,
  GREEN_APP,
  GREEN_K,
  GREEN_G,
  GREEN_X,
  GREEN_COMMA,
  GREEN_PERIOD,
  NUMBER_F7,
  NUMBER_F8,
  NUMBER_F9,
  NUMBER_F11,
  NUMBER_F4,
  NUMBER_F5,
  NUMBER_F6,
  NUMBER_F12,
  NUMBER_F1,
  NUMBER_F2,
  NUMBER_F3,
  NUMBER_EQUAL,
  SYMBOL_COMMA
};

// Green
const uint16_t PROGMEM green_tab[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM green_apostrophe[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM green_b[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM green_m[] = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM green_j[] = {KC_SPC, KC_P, COMBO_END};
const uint16_t PROGMEM green_q[] = {KC_SPC, KC_O, COMBO_END};
const uint16_t PROGMEM green_z[] = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM green_l[] = {KC_SPC, KC_H, COMBO_END};
const uint16_t PROGMEM green_c[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM green_v[] = {KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM green_cmd[] = {KC_SPC, KC_U, COMBO_END};
const uint16_t PROGMEM green_app[] = {KC_SPC, KC_I, COMBO_END};
const uint16_t PROGMEM green_k[] = {KC_SPC, KC_N, COMBO_END};
const uint16_t PROGMEM green_g[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM green_x[] = {KC_SPC, KC_Y, COMBO_END};
const uint16_t PROGMEM green_comma[] = {KC_SPC, TO(2), COMBO_END};
const uint16_t PROGMEM green_period[] = {KC_SPC, KC_ENTER, COMBO_END};

// Number
const uint16_t PROGMEM number_f7[] = {TO(0), KC_7, COMBO_END};
const uint16_t PROGMEM number_f8[] = {TO(0), KC_8, COMBO_END};
const uint16_t PROGMEM number_f9[] = {TO(0), KC_9, COMBO_END};
const uint16_t PROGMEM number_f11[] = {TO(0), KC_SLASH, COMBO_END};
const uint16_t PROGMEM number_f4[] = {TO(0), KC_4, COMBO_END};
const uint16_t PROGMEM number_f5[] = {TO(0), KC_5, COMBO_END};
const uint16_t PROGMEM number_f6[] = {TO(0), KC_6, COMBO_END};
const uint16_t PROGMEM number_f12[] = {TO(0), KC_PLUS, COMBO_END};
const uint16_t PROGMEM number_f1[] = {TO(0), KC_1, COMBO_END};
const uint16_t PROGMEM number_f2[] = {TO(0), KC_2, COMBO_END};
const uint16_t PROGMEM number_f3[] = {TO(0), KC_3, COMBO_END};
const uint16_t PROGMEM number_equal[] = {TO(0), KC_EQUAL, COMBO_END};

// Symbol
const uint16_t PROGMEM symbol_comma[] = {KC_SPC, TO(0), COMBO_END};

combo_t key_combos[] = {
    [GREEN_TAB] = COMBO(green_tab, KC_TAB),
    [GREEN_APOSTROPHE] = COMBO(green_apostrophe, KC_QUOTE),
    [GREEN_B] = COMBO(green_b, KC_B),
    [GREEN_M] = COMBO(green_m, KC_M),
    [GREEN_J] = COMBO(green_j, KC_J),
    [GREEN_Q] = COMBO(green_q, KC_Q),
    [GREEN_Z] = COMBO(green_z, KC_Z),
    [GREEN_L] = COMBO(green_l, KC_L),
    [GREEN_C] = COMBO(green_c, KC_C),
    [GREEN_V] = COMBO(green_v, KC_V),
    [GREEN_CMD] = COMBO(green_cmd, KC_LGUI),
    [GREEN_APP] = COMBO(green_app, KC_APP),
    [GREEN_K] = COMBO(green_k, KC_K),
    [GREEN_G] = COMBO(green_g, KC_G),
    [GREEN_X] = COMBO(green_x, KC_X),
    [GREEN_COMMA] = COMBO(green_comma, KC_COMMA),
    [GREEN_PERIOD] = COMBO(green_period, KC_DOT),
    [NUMBER_F7] = COMBO(number_f7, KC_F7),
    [NUMBER_F8] = COMBO(number_f8, KC_F8),
    [NUMBER_F9] = COMBO(number_f9, KC_F9),
    [NUMBER_F11] = COMBO(number_f11, KC_F11),
    [NUMBER_F4] = COMBO(number_f4, KC_F4),
    [NUMBER_F5] = COMBO(number_f5, KC_F5),
    [NUMBER_F6] = COMBO(number_f6, KC_F5),
    [NUMBER_F12] = COMBO(number_f12, KC_F12),
    [NUMBER_F1] = COMBO(number_f1, KC_F1),
    [NUMBER_F2] = COMBO(number_f2, KC_F2),
    [NUMBER_F3] = COMBO(number_f3, KC_F3),
    [NUMBER_EQUAL] = COMBO(number_equal, KC_EQUAL),
    [SYMBOL_COMMA] = COMBO(symbol_comma, KC_COMMA),
};

// Keymap
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//          ┌───────┬───┬───┬───┬─────┐
//          │   f   │ a │ r │ w │  p  │
//          ├───────┼───┼───┼───┼─────┤
//          │   o   │ e │ h │ t │  d  │
//          ├───────┼───┼───┼───┼─────┤
//          │   u   │ i │ n │ s │  y  │
//    ┌─────┼───────┼───┴───┴───┼─────┼──────────────┐
//    │ spc │ TO(1) │   TO(2)   │ ent │ TD(SFT_LOCK) │
//    └─────┴───────┴───────────┴─────┴──────────────┘
[0] = LAYOUT_ortho_4x5(
           KC_F  , KC_A , KC_R , KC_W , KC_P                   ,
           KC_O  , KC_E , KC_H , KC_T , KC_D                   ,
           KC_U  , KC_I , KC_N , KC_S , KC_Y                   ,
  KC_SPC , TO(1) ,       TO(2)        , KC_ENTER , TD(SFT_LOCK)
),

//          ┌───────┬───┬───┬───┬─────┐
//          │   -   │ 7 │ 8 │ 9 │ no  │
//          ├───────┼───┼───┼───┼─────┤
//          │   /   │ 4 │ 5 │ 6 │  +  │
//          ├───────┼───┼───┼───┼─────┤
//          │   0   │ 1 │ 2 │ 3 │  =  │
//    ┌─────┼───────┼───┴───┴───┼─────┼─────┐
//    │ spc │ TO(0) │   TO(2)   │     │     │
//    └─────┴───────┴───────────┴─────┴─────┘
[1] = LAYOUT_ortho_4x5(
           KC_MINUS , KC_7 , KC_8 , KC_9 , KC_NO             ,
           KC_SLASH , KC_4 , KC_5 , KC_6 , KC_PLUS           ,
           KC_0     , KC_1 , KC_2 , KC_3 , KC_EQUAL          ,
  KC_SPC , TO(0)    ,       TO(2)        , KC_TRNS  , KC_TRNS
),

//          ┌───────┬───┬───┬───┬───────────┐
//          │   ?   │ & │ * │ : │ sEMICOLON │
//          ├───────┼───┼───┼───┼───────────┤
//          │   /   │ ! │ - │ @ │     _     │
//          ├───────┼───┼───┼───┼───────────┤
//          │   "   │ < │ ( │ [ │     {     │
//    ┌─────┼───────┼───┴───┴───┼───────────┼─────┐
//    │ spc │ TO(1) │   TO(0)   │           │     │
//    └─────┴───────┴───────────┴───────────┴─────┘
[2] = LAYOUT_ortho_4x5(
           KC_QUESTION     , KC_AMPERSAND          , KC_ASTERISK   , KC_COLON        , KC_SEMICOLON                 ,
           KC_SLASH        , KC_EXCLAIM            , KC_MINUS      , KC_AT           , KC_UNDERSCORE                ,
           KC_DOUBLE_QUOTE , KC_LEFT_ANGLE_BRACKET , KC_LEFT_PAREN , KC_LEFT_BRACKET , KC_LEFT_CURLY_BRACE          ,
  KC_SPC , TO(1)           ,                          TO(0)                          , KC_TRNS             , KC_TRNS
)
};
// clang-format on
