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
#include "combos.c"

enum layers {
  BASE,
  NUMBER,
  SYMBOL
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
[BASE] = LAYOUT_ortho_4x5(
           KC_F  , KC_A , KC_R , KC_W , KC_P                   ,
           KC_O  , KC_E , KC_H , KC_T , KC_D                   ,
           KC_U  , KC_I , KC_N , KC_S , KC_Y                   ,
  KC_SPC , TO(1) ,       TO(2)        , KC_ENTER , TD(SFT_LOCK)
),

//          ┌───────┬───┬───┬───┬──────┐
//          │   -   │ 7 │ 8 │ 9 │ kp_- │
//          ├───────┼───┼───┼───┼──────┤
//          │   /   │ 4 │ 5 │ 6 │  +   │
//          ├───────┼───┼───┼───┼──────┤
//          │   0   │ 1 │ 2 │ 3 │  =   │
//    ┌─────┼───────┼───┴───┴───┼──────┼─────┐
//    │ spc │ TO(0) │   TO(2)   │      │     │
//    └─────┴───────┴───────────┴──────┴─────┘
[NUMBER] = LAYOUT_ortho_4x5(
           KC_MINUS , KC_7 , KC_8 , KC_9 , KC_KP_MINUS          ,
           KC_SLASH , KC_4 , KC_5 , KC_6 , KC_PLUS              ,
           KC_0     , KC_1 , KC_2 , KC_3 , KC_EQUAL             ,
  KC_SPC , TO(0)    ,       TO(2)        , KC_TRNS     , KC_TRNS
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
[SYMBOL] = LAYOUT_ortho_4x5(
           KC_QUESTION     , KC_AMPERSAND          , KC_ASTERISK   , KC_COLON        , KC_SEMICOLON                 ,
           KC_SLASH        , KC_EXCLAIM            , KC_MINUS      , KC_AT           , KC_UNDERSCORE                ,
           KC_DOUBLE_QUOTE , KC_LEFT_ANGLE_BRACKET , KC_LEFT_PAREN , KC_LEFT_BRACKET , KC_LEFT_CURLY_BRACE          ,
  KC_SPC , TO(1)           ,                          TO(0)                          , KC_TRNS             , KC_TRNS
)
};
// clang-format on
