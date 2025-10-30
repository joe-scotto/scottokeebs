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
//          │ kp_*  │ 7 │ 8 │ 9 │ kp_- │
//          ├───────┼───┼───┼───┼──────┤
//          │ kp_/  │ 4 │ 5 │ 6 │ kp_+ │
//          ├───────┼───┼───┼───┼──────┤
//          │   0   │ 1 │ 2 │ 3 │  =   │
//    ┌─────┼───────┼───┴───┴───┼──────┼──────────────┐
//    │ spc │ TO(0) │   TO(2)   │ ent  │ TD(SFT_LOCK) │
//    └─────┴───────┴───────────┴──────┴──────────────┘
[NUMBER] = LAYOUT_ortho_4x5(
           KC_KP_ASTERISK , KC_7 , KC_8 , KC_9 , KC_KP_MINUS               ,
           KC_KP_SLASH    , KC_4 , KC_5 , KC_6 , KC_KP_PLUS                ,
           KC_0           , KC_1 , KC_2 , KC_3 , KC_EQUAL                  ,
  KC_SPC , TO(0)          ,       TO(2)        , KC_ENTER    , TD(SFT_LOCK)
),

//          ┌───────┬───┬───┬───┬───────────┐
//          │   ?   │ & │ * │ : │ sEMICOLON │
//          ├───────┼───┼───┼───┼───────────┤
//          │   /   │ ! │ - │ @ │     _     │
//          ├───────┼───┼───┼───┼───────────┤
//          │   "   │ < │ ( │ [ │     {     │
//    ┌─────┼───────┼───┴───┴───┼───────────┼──────────────┐
//    │ spc │ TO(1) │   TO(0)   │    ent    │ TD(SFT_LOCK) │
//    └─────┴───────┴───────────┴───────────┴──────────────┘
[SYMBOL] = LAYOUT_ortho_4x5(
           KC_QUESTION     , KC_AMPERSAND          , KC_ASTERISK   , KC_COLON        , KC_SEMICOLON                      ,
           KC_SLASH        , KC_EXCLAIM            , KC_MINUS      , KC_AT           , KC_UNDERSCORE                     ,
           KC_DOUBLE_QUOTE , KC_LEFT_ANGLE_BRACKET , KC_LEFT_PAREN , KC_LEFT_BRACKET , KC_LEFT_CURLY_BRACE               ,
  KC_SPC , TO(1)           ,                          TO(0)                          , KC_ENTER            , TD(SFT_LOCK)
)
};
// clang-format on
