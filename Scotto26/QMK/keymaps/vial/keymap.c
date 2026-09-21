#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───┬───┬─────────────┐   ┌────┬───┬───────────┬───────────┐
//    │     q     │ w │ f │      p      │   │ l  │ u │     y     │   bspc    │
//    ├───────────┼───┼───┼─────────────┤   ├────┼───┼───────────┼───────────┤
//    │     a     │ r │ s │      t      │   │ n  │ e │     i     │     o     │
//    ├───────────┼───┼───┼─────────────┤   ├────┼───┼───────────┼───────────┤
//    │ RSFT_T(z) │ x │ c │      v      │   │ m  │ , │ RGUI_T(.) │ RSFT_T(/) │
//    └───────────┴───┴───┼─────────────┤   ├────┼───┴───────────┴───────────┘
//                        │ LGUI_T(spc) │   │ no │
//                        └─────────────┘   └────┘
[0] = LAYOUT_split_3x4_1(
  KC_Q         , KC_W , KC_F , KC_P           ,     KC_L  , KC_U     , KC_Y           , KC_BSPC        ,
  KC_A         , KC_R , KC_S , KC_T           ,     KC_N  , KC_E     , KC_I           , KC_O           ,
  RSFT_T(KC_Z) , KC_X , KC_C , KC_V           ,     KC_M  , KC_COMMA , RGUI_T(KC_DOT) , RSFT_T(KC_SLSH),
                               LGUI_T(KC_SPC) ,     KC_NO
),

//    ┌───────────┬───┬───┬─────┐   ┌──────┬──────┬──────────────┬───────────┐
//    │     _     │ - │ + │  =  │   │ mrwd │ mply │     mffd     │    del    │
//    ├───────────┼───┼───┼─────┤   ├──────┼──────┼──────────────┼───────────┤
//    │     {     │ ( │ ) │  }  │   │ left │  up  │     down     │   rght    │
//    ├───────────┼───┼───┼─────┤   ├──────┼──────┼──────────────┼───────────┤
//    │ RSFT_T([) │ ' │ " │  ]  │   │ vold │ mute │ RGUI_T(volu) │ RSFT_T(\) │
//    └───────────┴───┴───┼─────┤   ├──────┼──────┴──────────────┴───────────┘
//                        │     │   │      │
//                        └─────┘   └──────┘
[1] = LAYOUT_split_3x4_1(
  KC_UNDS         , KC_MINS , KC_PLUS , KC_EQL  ,     KC_MRWD , KC_MPLY , KC_MFFD         , KC_DEL         ,
  KC_LCBR         , KC_LPRN , KC_RPRN , KC_RCBR ,     KC_LEFT , KC_UP   , KC_DOWN         , KC_RGHT        ,
  RSFT_T(KC_LBRC) , KC_QUOT , KC_DQUO , KC_RBRC ,     KC_VOLD , KC_MUTE , RGUI_T(KC_VOLU) , RSFT_T(KC_BSLS),
                                        KC_TRNS ,     KC_TRNS
),

//    ┌──────┬────┬────┬───────┐   ┌─────┬───┬──────┬───────────┐
//    │  !   │ @  │ #  │   $   │   │  &  │ * │ caps │    del    │
//    ├──────┼────┼────┼───────┤   ├─────┼───┼──────┼───────────┤
//    │  1   │ 2  │ 3  │   4   │   │  7  │ 8 │  9   │     0     │
//    ├──────┼────┼────┼───────┤   ├─────┼───┼──────┼───────────┤
//    │ rsft │ no │ no │ MO(3) │   │ no  │ , │  .   │ RSFT_T(/) │
//    └──────┴────┴────┼───────┤   ├─────┼───┴──────┴───────────┘
//                     │       │   │     │
//                     └───────┘   └─────┘
[2] = LAYOUT_split_3x4_1(
  KC_EXLM , KC_AT , KC_HASH , KC_DLR  ,     KC_AMPR , KC_ASTR  , KC_CAPS , KC_DEL         ,
  KC_1    , KC_2  , KC_3    , KC_4    ,     KC_7    , KC_8     , KC_9    , KC_0           ,
  KC_RSFT , KC_NO , KC_NO   , MO(3)   ,     KC_NO   , KC_COMMA , KC_DOT  , RSFT_T(KC_SLSH),
                              KC_TRNS ,     KC_TRNS
),

//    ┌─────────────┬────┬─────────┬─────┐   ┌─────┬────┬────┬─────────────┐
//    │     no      │ no │   no    │ no  │   │ no  │ no │ no │     no      │
//    ├─────────────┼────┼─────────┼─────┤   ├─────┼────┼────┼─────────────┤
//    │     f1      │ f2 │   f3    │ f4  │   │ f7  │ f8 │ f9 │     f10     │
//    ├─────────────┼────┼─────────┼─────┤   ├─────┼────┼────┼─────────────┤
//    │ RSFT_T(f11) │ no │ QK_BOOT │     │   │ no  │ no │ no │ RSFT_T(f12) │
//    └─────────────┴────┴─────────┼─────┤   ├─────┼────┴────┴─────────────┘
//                                 │     │   │     │
//                                 └─────┘   └─────┘
[3] = LAYOUT_split_3x4_1(
  KC_NO          , KC_NO , KC_NO   , KC_NO   ,     KC_NO   , KC_NO , KC_NO , KC_NO         ,
  KC_F1          , KC_F2 , KC_F3   , KC_F4   ,     KC_F7   , KC_F8 , KC_F9 , KC_F10        ,
  RSFT_T(KC_F11) , KC_NO , QK_BOOT , KC_TRNS ,     KC_NO   , KC_NO , KC_NO , RSFT_T(KC_F12),
                                     KC_TRNS ,     KC_TRNS
)
};
// clang-format on
