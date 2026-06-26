#include "combos.c"
#include "keys.c"
#include "keys.h"
#include "tapdance.c"
#include "rgb.c"
#include QMK_KEYBOARD_H

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_MULTI):
    case TD(TD_MODS_X):
    case TD(TD_MODS_QUOT):
    case LGUI_T(KC_SPC):
    case LT(1, KC_TAB):
    case LT(2, KC_ENT):
      return 200;
    default:
      return TAPPING_TERM;
  }
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───────────┬───────────────┬──────┬──────────────┬─────────────┐       ┌────────────┬────────────┬──────┬───────────┬───────────┬──────┐
//    │ tab  │     q     │       w       │  f   │      p       │      g      │       │     j      │     l      │  u   │     y     │   bspc    │ bACK │
//    ├──────┼───────────┼───────────────┼──────┼──────────────┼─────────────┤       ├────────────┼────────────┼──────┼───────────┼───────────┼──────┤
//    │ caps │     a     │       r       │  s   │      t       │      d      │       │     h      │     n      │  e   │     i     │     o     │ ent  │
//    ├──────┼───────────┼───────────────┼──────┼──────────────┼─────────────┤       ├────────────┼────────────┼──────┼───────────┼───────────┼──────┤
//    │ rsft │ RSFT_T(z) │ TD(TD_MODS_X) │  c   │      v       │      b      │       │     k      │     m      │  ,   │ RGUI_T(.) │ RSFT_T(/) │ rsft │
//    ├──────┼───────────┼───────────────┼──────┼──────────────┼─────────────┤       ├────────────┼────────────┼──────┼───────────┼───────────┼──────┤
//    │ esc  │   rgui    │     ralt      │ rctl │ TD(TD_MULTI) │ LGUI_T(spc) │       │ LT(1, tab) │ LT(2, ent) │ left │    up     │   down    │ rght │
//    └──────┴───────────┴───────────────┴──────┴──────────────┴─────────────┘       └────────────┴────────────┴──────┴───────────┴───────────┴──────┘
[0] = LAYOUT_ortho_4x12(
  KC_TAB  , KC_Q         , KC_W          , KC_F    , KC_P         , KC_G           ,         KC_J          , KC_L          , KC_U     , KC_Y           , KC_BSPC         , KC_BACK ,
  KC_CAPS , KC_A         , KC_R          , KC_S    , KC_T         , KC_D           ,         KC_H          , KC_N          , KC_E     , KC_I           , KC_O            , KC_ENTER,
  KC_RSFT , RSFT_T(KC_Z) , TD(TD_MODS_X) , KC_C    , KC_V         , KC_B           ,         KC_K          , KC_M          , KC_COMMA , RGUI_T(KC_DOT) , RSFT_T(KC_SLSH) , KC_RSFT ,
  KC_ESC  , KC_RGUI      , KC_RALT       , KC_RCTL , TD(TD_MULTI) , LGUI_T(KC_SPC) ,         LT(1, KC_TAB) , LT(2, KC_ENT) , KC_LEFT  , KC_UP          , KC_DOWN         , KC_RIGHT
),

//    ┌─────┬───────────┬──────────────────┬─────┬─────┬─────┐       ┌─────┬──────┬──────┬──────────────┬───────────┬─────┐
//    │     │     _     │        -         │  +  │  =  │  :  │       │  `  │ mrwd │ mply │     mffd     │    del    │     │
//    ├─────┼───────────┼──────────────────┼─────┼─────┼─────┤       ├─────┼──────┼──────┼──────────────┼───────────┼─────┤
//    │     │     {     │        (         │  )  │  }  │  |  │       │ esc │ left │  up  │     down     │   rght    │     │
//    ├─────┼───────────┼──────────────────┼─────┼─────┼─────┤       ├─────┼──────┼──────┼──────────────┼───────────┼─────┤
//    │     │ RSFT_T([) │ TD(TD_MODS_QUOT) │  "  │  ]  │  ;  │       │  ~  │ vold │ mute │ RGUI_T(volu) │ RSFT_T(\) │     │
//    ├─────┼───────────┼──────────────────┼─────┼─────┼─────┤       ├─────┼──────┼──────┼──────────────┼───────────┼─────┤
//    │     │           │                  │     │     │     │       │     │      │      │              │           │     │
//    └─────┴───────────┴──────────────────┴─────┴─────┴─────┘       └─────┴──────┴──────┴──────────────┴───────────┴─────┘
[1] = LAYOUT_ortho_4x12(
  KC_TRNS , KC_UNDS         , KC_MINS          , KC_PLUS , KC_EQL  , KC_COLN ,         KC_GRV   , KC_MRWD , KC_MPLY , KC_MFFD         , KC_DEL          , KC_TRNS,
  KC_TRNS , KC_LCBR         , KC_LPRN          , KC_RPRN , KC_RCBR , KC_PIPE ,         KC_ESC   , KC_LEFT , KC_UP   , KC_DOWN         , KC_RGHT         , KC_TRNS,
  KC_TRNS , RSFT_T(KC_LBRC) , TD(TD_MODS_QUOT) , KC_DQUO , KC_RBRC , KC_SCLN ,         KC_TILDE , KC_VOLD , KC_MUTE , RGUI_T(KC_VOLU) , RSFT_T(KC_BSLS) , KC_TRNS,
  KC_TRNS , KC_TRNS         , KC_TRNS          , KC_TRNS , KC_TRNS , KC_TRNS ,         KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS         , KC_TRNS         , KC_TRNS
),

//    ┌─────┬──────┬─────┬───────┬─────┬───────┐       ┌─────┬─────┬─────┬──────┬───────────┬─────┐
//    │     │  !   │  @  │   #   │  $  │   %   │       │  ^  │  &  │  *  │ caps │   bACK    │     │
//    ├─────┼──────┼─────┼───────┼─────┼───────┤       ├─────┼─────┼─────┼──────┼───────────┼─────┤
//    │     │  1   │  2  │   3   │  4  │   5   │       │  6  │  7  │  8  │  9   │     0     │     │
//    ├─────┼──────┼─────┼───────┼─────┼───────┤       ├─────┼─────┼─────┼──────┼───────────┼─────┤
//    │     │ rsft │ no  │ MO(4) │ no  │ MO(3) │       │ no  │ no  │  ,  │  .   │ RSFT_T(/) │     │
//    ├─────┼──────┼─────┼───────┼─────┼───────┤       ├─────┼─────┼─────┼──────┼───────────┼─────┤
//    │     │      │     │       │     │       │       │     │     │     │      │           │     │
//    └─────┴──────┴─────┴───────┴─────┴───────┘       └─────┴─────┴─────┴──────┴───────────┴─────┘
[2] = LAYOUT_ortho_4x12(
  KC_TRNS , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,         KC_CIRC , KC_AMPR , KC_ASTR  , KC_CAPS , KC_BACK         , KC_TRNS,
  KC_TRNS , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,         KC_6    , KC_7    , KC_8     , KC_9    , KC_0            , KC_TRNS,
  KC_TRNS , KC_RSFT , KC_NO   , MO(4)   , KC_NO   , MO(3)   ,         KC_NO   , KC_NO   , KC_COMMA , KC_DOT  , RSFT_T(KC_SLSH) , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,         KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS         , KC_TRNS
),

//    ┌─────┬─────────────┬────────────┬─────┬───────────┬─────┐       ┌─────┬─────┬─────┬─────────────┬─────────────┬─────┐
//    │     │ LAYOUT_SWAP │ MODE_CHECK │ no  │    no     │ no  │       │ no  │ no  │ no  │ GAME_TOGGLE │  OS_TOGGLE  │     │
//    ├─────┼─────────────┼────────────┼─────┼───────────┼─────┤       ├─────┼─────┼─────┼─────────────┼─────────────┼─────┤
//    │     │     f1      │     f2     │ f3  │    f4     │ f5  │       │ f6  │ f7  │ f8  │     f9      │     f10     │     │
//    ├─────┼─────────────┼────────────┼─────┼───────────┼─────┤       ├─────┼─────┼─────┼─────────────┼─────────────┼─────┤
//    │     │ RSFT_T(f11) │     no     │ no  │ HARD_BOOT │ no  │       │ no  │ no  │ no  │     no      │ RSFT_T(f12) │     │
//    ├─────┼─────────────┼────────────┼─────┼───────────┼─────┤       ├─────┼─────┼─────┼─────────────┼─────────────┼─────┤
//    │     │             │            │     │           │     │       │     │     │     │             │             │     │
//    └─────┴─────────────┴────────────┴─────┴───────────┴─────┘       └─────┴─────┴─────┴─────────────┴─────────────┴─────┘
[3] = LAYOUT_ortho_4x12(
  KC_TRNS , LAYOUT_SWAP    , MODE_CHECK , KC_NO   , KC_NO     , KC_NO   ,         KC_NO   , KC_NO   , KC_NO   , GAME_TOGGLE , OS_TOGGLE      , KC_TRNS,
  KC_TRNS , KC_F1          , KC_F2      , KC_F3   , KC_F4     , KC_F5   ,         KC_F6   , KC_F7   , KC_F8   , KC_F9       , KC_F10         , KC_TRNS,
  KC_TRNS , RSFT_T(KC_F11) , KC_NO      , KC_NO   , HARD_BOOT , KC_NO   ,         KC_NO   , KC_NO   , KC_NO   , KC_NO       , RSFT_T(KC_F12) , KC_TRNS,
  KC_TRNS , KC_TRNS        , KC_TRNS    , KC_TRNS , KC_TRNS   , KC_TRNS ,         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS     , KC_TRNS        , KC_TRNS
),

//    ┌─────┬───────────┬─────┬─────┬─────┬─────┐       ┌─────────┬────────────┬─────────┬─────────┬────────────┬─────┐
//    │     │    no     │ no  │ no  │ no  │ no  │       │   no    │ RGUI(left) │   no    │   no    │ RGUI(rght) │     │
//    ├─────┼───────────┼─────┼─────┼─────┼─────┤       ├─────────┼────────────┼─────────┼─────────┼────────────┼─────┤
//    │     │     a     │ no  │ no  │ no  │ no  │       │   esc   │  MS_LEFT   │  MS_UP  │ MS_DOWN │  MS_RGHT   │     │
//    ├─────┼───────────┼─────┼─────┼─────┼─────┤       ├─────────┼────────────┼─────────┼─────────┼────────────┼─────┤
//    │     │ RSFT_T(z) │  x  │  c  │  v  │  b  │       │   no    │  MS_WHLL   │ MS_WHLU │ MS_WHLD │  MS_WHLR   │     │
//    ├─────┼───────────┼─────┼─────┼─────┼─────┤       ├─────────┼────────────┼─────────┼─────────┼────────────┼─────┤
//    │     │           │     │     │     │     │       │ MS_BTN1 │  MS_BTN2   │         │         │            │     │
//    └─────┴───────────┴─────┴─────┴─────┴─────┘       └─────────┴────────────┴─────────┴─────────┴────────────┴─────┘
[4] = LAYOUT_ortho_4x12(
  KC_TRNS , KC_NO        , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,         KC_NO   , RGUI(KC_LEFT) , KC_NO   , KC_NO   , RGUI(KC_RIGHT) , KC_TRNS,
  KC_TRNS , KC_A         , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,         KC_ESC  , MS_LEFT       , MS_UP   , MS_DOWN , MS_RGHT        , KC_TRNS,
  KC_TRNS , RSFT_T(KC_Z) , KC_X    , KC_C    , KC_V    , KC_B    ,         KC_NO   , MS_WHLL       , MS_WHLU , MS_WHLD , MS_WHLR        , KC_TRNS,
  KC_TRNS , KC_TRNS      , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,         MS_BTN1 , MS_BTN2       , KC_TRNS , KC_TRNS , KC_TRNS        , KC_TRNS
)
};
// clang-format on
