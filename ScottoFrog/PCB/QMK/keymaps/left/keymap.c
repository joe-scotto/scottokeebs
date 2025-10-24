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
//                   ┌─────┬───┬───┬───┬───────┐
//                   │  p  │ w │ r │ a │   f   │
//                   ├─────┼───┼───┼───┼───────┤
//                   │  d  │ t │ h │ e │   o   │
//                   ├─────┼───┼───┼───┼───────┤
//                   │  y  │ s │ n │ i │   u   │
//    ┌──────────────┼─────┼───┴───┴───┼───────┼─────┐
//    │ TD(SFT_LOCK) │ ent │   TO(2)   │ TO(1) │ spc │
//    └──────────────┴─────┴───────────┴───────┴─────┘
[BASE] = LAYOUT_ortho_4x5(
                 KC_P     , KC_W , KC_R , KC_A , KC_F          ,
                 KC_D     , KC_T , KC_H , KC_E , KC_O          ,
                 KC_Y     , KC_S , KC_N , KC_I , KC_U          ,
  TD(SFT_LOCK) , KC_ENTER ,       TO(2)        , TO(1) , KC_SPC
),

//                   ┌─────┬───┬───┬───┬───────┐
//                   │  -  │ 7 │ 8 │ 9 │ kp_-  │
//                   ├─────┼───┼───┼───┼───────┤
//                   │  +  │ 4 │ 5 │ 6 │   /   │
//                   ├─────┼───┼───┼───┼───────┤
//                   │  0  │ 1 │ 2 │ 3 │   =   │
//    ┌──────────────┼─────┼───┴───┴───┼───────┼─────┐
//    │ TD(SFT_LOCK) │ ent │   TO(2)   │ TO(0) │ spc │
//    └──────────────┴─────┴───────────┴───────┴─────┘
[NUMBER] = LAYOUT_ortho_4x5(
                 KC_MINUS , KC_7 , KC_8 , KC_9 , KC_KP_MINUS         ,
                 KC_PLUS  , KC_4 , KC_5 , KC_6 , KC_SLASH            ,
                 KC_0     , KC_1 , KC_2 , KC_3 , KC_EQUAL            ,
  TD(SFT_LOCK) , KC_ENTER ,       TO(2)        , TO(0)       , KC_SPC
),

//                   ┌───────────┬───┬───┬───┬───────┐
//                   │ sEMICOLON │ : │ * │ & │   ?   │
//                   ├───────────┼───┼───┼───┼───────┤
//                   │     _     │ @ │ - │ ! │   /   │
//                   ├───────────┼───┼───┼───┼───────┤
//                   │     {     │ [ │ ( │ < │   "   │
//    ┌──────────────┼───────────┼───┴───┴───┼───────┼─────┐
//    │ TD(SFT_LOCK) │    ent    │   TO(0)   │ TO(1) │ spc │
//    └──────────────┴───────────┴───────────┴───────┴─────┘
[SYMBOL] = LAYOUT_ortho_4x5(
                 KC_SEMICOLON        , KC_COLON        , KC_ASTERISK   , KC_AMPERSAND          , KC_QUESTION             ,
                 KC_UNDERSCORE       , KC_AT           , KC_MINUS      , KC_EXCLAIM            , KC_SLASH                ,
                 KC_LEFT_CURLY_BRACE , KC_LEFT_BRACKET , KC_LEFT_PAREN , KC_LEFT_ANGLE_BRACKET , KC_DOUBLE_QUOTE         ,
  TD(SFT_LOCK) , KC_ENTER            ,                          TO(0)                          , TO(1)           , KC_SPC
)
};
// clang-format on
