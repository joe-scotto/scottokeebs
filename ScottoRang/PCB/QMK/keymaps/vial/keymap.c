#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───┬───┬──────┬─────────────┐       ┌────────────┬────────────┬───┬───────────┬───────────┐
//    │     q     │ w │ f │  p   │      g      │       │     j      │     l      │ u │     y     │   bspc    │
//    ├───────────┼───┼───┼──────┼─────────────┤       ├────────────┼────────────┼───┼───────────┼───────────┤
//    │     a     │ r │ s │  t   │      d      │       │     h      │     n      │ e │     i     │     o     │
//    ├───────────┼───┼───┼──────┼─────────────┤       ├────────────┼────────────┼───┼───────────┼───────────┤
//    │ LSFT_T(z) │ x │ c │  v   │      b      │       │     k      │     m      │ , │ RGUI_T(.) │ RSFT_T(/) │
//    └───────────┴───┴───┼──────┼─────────────┤       ├────────────┼────────────┼───┴───────────┴───────────┘
//                        │ lalt │ LGUI_T(spc) │       │ LT(2, tab) │ LT(3, ent) │
//                        └──────┴─────────────┘       └────────────┴────────────┘
[0] = LAYOUT_split_3x5_2(
  KC_Q         , KC_W , KC_F , KC_P    , KC_G           ,         KC_J          , KC_L          , KC_U     , KC_Y           , KC_BSPC        ,
  KC_A         , KC_R , KC_S , KC_T    , KC_D           ,         KC_H          , KC_N          , KC_E     , KC_I           , KC_O           ,
  LSFT_T(KC_Z) , KC_X , KC_C , KC_V    , KC_B           ,         KC_K          , KC_M          , KC_COMMA , RGUI_T(KC_DOT) , RSFT_T(KC_SLSH),
                               KC_LALT , LGUI_T(KC_SPC) ,         LT(2, KC_TAB) , LT(3, KC_ENT)
),

//    ┌───┬───┬───┬──────┬─────┐       ┌─────┬─────┬───┬───┬──────┐
//    │ q │ w │ f │  p   │  g  │       │  j  │  l  │ u │ y │ bspc │
//    ├───┼───┼───┼──────┼─────┤       ├─────┼─────┼───┼───┼──────┤
//    │ a │ r │ s │  t   │  d  │       │  h  │  n  │ e │ i │  o   │
//    ├───┼───┼───┼──────┼─────┤       ├─────┼─────┼───┼───┼──────┤
//    │ z │ x │ c │  v   │  b  │       │  k  │  m  │ , │ . │  /   │
//    └───┴───┴───┼──────┼─────┤       ├─────┼─────┼───┴───┴──────┘
//                │ rctl │ spc │       │     │     │
//                └──────┴─────┘       └─────┴─────┘
[1] = LAYOUT_split_3x5_2(
  KC_Q , KC_W , KC_F , KC_P    , KC_G   ,         KC_J    , KC_L    , KC_U     , KC_Y   , KC_BSPC,
  KC_A , KC_R , KC_S , KC_T    , KC_D   ,         KC_H    , KC_N    , KC_E     , KC_I   , KC_O   ,
  KC_Z , KC_X , KC_C , KC_V    , KC_B   ,         KC_K    , KC_M    , KC_COMMA , KC_DOT , KC_SLSH,
                       KC_RCTL , KC_SPC ,         KC_TRNS , KC_TRNS
),

//    ┌───────────┬───┬───┬─────┬─────┐       ┌─────┬──────┬──────┬──────┬───────────┐
//    │     _     │ - │ + │  =  │  :  │       │  `  │ mrwd │ mply │ mffd │    del    │
//    ├───────────┼───┼───┼─────┼─────┤       ├─────┼──────┼──────┼──────┼───────────┤
//    │     {     │ ( │ ) │  }  │  |  │       │ esc │ left │  up  │ down │   rght    │
//    ├───────────┼───┼───┼─────┼─────┤       ├─────┼──────┼──────┼──────┼───────────┤
//    │ LSFT_T([) │ ' │ " │  ]  │  ;  │       │  ~  │ vold │ mute │ volu │ RSFT_T(\) │
//    └───────────┴───┴───┼─────┼─────┤       ├─────┼──────┼──────┴──────┴───────────┘
//                        │     │     │       │     │      │
//                        └─────┴─────┘       └─────┴──────┘
[2] = LAYOUT_split_3x5_2(
  KC_UNDS         , KC_MINS  , KC_PLUS , KC_EQL  , KC_COLN ,         KC_GRV   , KC_MRWD , KC_MPLY , KC_MFFD , KC_DEL         ,
  KC_LCBR         , KC_LPRN  , KC_RPRN , KC_RCBR , KC_PIPE ,         KC_ESC   , KC_LEFT , KC_UP   , KC_DOWN , KC_RGHT        ,
  LSFT_T(KC_LBRC) , KC_QUOTE , KC_DQUO , KC_RBRC , KC_SCLN ,         KC_TILDE , KC_VOLD , KC_MUTE , KC_VOLU , RSFT_T(KC_BSLS),
                                         KC_TRNS , KC_TRNS ,         KC_TRNS  , KC_TRNS
),

//    ┌──────┬─────┬────┬─────┬───────┐       ┌─────┬─────┬───┬──────┬───────────┐
//    │  !   │  @  │ #  │  $  │   %   │       │  ^  │  &  │ * │ caps │   bspc    │
//    ├──────┼─────┼────┼─────┼───────┤       ├─────┼─────┼───┼──────┼───────────┤
//    │  1   │  2  │ 3  │  4  │   5   │       │  6  │  7  │ 8 │  9   │     0     │
//    ├──────┼─────┼────┼─────┼───────┤       ├─────┼─────┼───┼──────┼───────────┤
//    │ lsft │     │ no │ no  │ MO(4) │       │ no  │ no  │ , │      │ RSFT_T(/) │
//    └──────┴─────┴────┼─────┼───────┤       ├─────┼─────┼───┴──────┴───────────┘
//                      │     │       │       │     │     │
//                      └─────┴───────┘       └─────┴─────┘
[3] = LAYOUT_split_3x5_2(
  KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,         KC_CIRC , KC_AMPR , KC_ASTR  , KC_CAPS , KC_BSPC        ,
  KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,         KC_6    , KC_7    , KC_8     , KC_9    , KC_0           ,
  KC_LSFT , KC_TRNS , KC_NO   , KC_NO   , MO(4)   ,         KC_NO   , KC_NO   , KC_COMMA , KC_TRNS , RSFT_T(KC_SLSH),
                                KC_TRNS , KC_TRNS ,         KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬────┬─────────┬─────┐       ┌─────┬─────┬────┬───────┬─────┐
//    │ no  │ no  │ no │   no    │ no  │       │ no  │ no  │ no │ TG(1) │ no  │
//    ├─────┼─────┼────┼─────────┼─────┤       ├─────┼─────┼────┼───────┼─────┤
//    │ f1  │ f2  │ f3 │   f4    │ f5  │       │ f6  │ f7  │ f8 │  f9   │ f10 │
//    ├─────┼─────┼────┼─────────┼─────┤       ├─────┼─────┼────┼───────┼─────┤
//    │ f11 │     │ no │ QK_BOOT │ no  │       │ no  │ no  │ no │       │ f12 │
//    └─────┴─────┴────┼─────────┼─────┤       ├─────┼─────┼────┴───────┴─────┘
//                     │         │     │       │     │     │
//                     └─────────┴─────┘       └─────┴─────┘
[4] = LAYOUT_split_3x5_2(
  KC_NO  , KC_NO   , KC_NO , KC_NO   , KC_NO   ,         KC_NO   , KC_NO   , KC_NO , TG(1)   , KC_NO ,
  KC_F1  , KC_F2   , KC_F3 , KC_F4   , KC_F5   ,         KC_F6   , KC_F7   , KC_F8 , KC_F9   , KC_F10,
  KC_F11 , KC_TRNS , KC_NO , QK_BOOT , KC_NO   ,         KC_NO   , KC_NO   , KC_NO , KC_TRNS , KC_F12,
                             KC_TRNS , KC_TRNS ,         KC_TRNS , KC_TRNS
)
};
// clang-format on
