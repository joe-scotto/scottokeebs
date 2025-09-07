/*
Copyright 2028 Joe Scotto

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
#include "tapdance.c"

// Custom tapping term for multi function keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI):
    case TD(TD_ESC_LCTL_LALT_WINDOWS_EMOJI):
    case TD(TD_MODS_X):
    case TD(TD_MODS_DOT):
    case TD(TD_MODS_QUOT):
    case TD(TD_MODS_VOLU):
    case TD(LSFT_T(KC_Z)):
    case LGUI_T(KC_SPC):
    case LT(1, KC_SPC):
    case LT(1, KC_TAB):
    case LT(2, KC_ENT):
      return 200;
    default:
      return TAPPING_TERM;
  }
};

// Onboard LED
#ifdef RGBLIGHT_ENABLE
// Configure LED
void keyboard_post_init_user(void) {
  // Initialize RGB to static black
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_BLACK);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

// Change LED
void housekeeping_task_user(void) {
  // Caps lock status
  if (host_keyboard_led_state().caps_lock) {
    rgblight_setrgb_at(4, 4, 0, 0);
  } else {
    // Layers
    switch (get_highest_layer(layer_state | default_layer_state)) {
      case 0:
        rgblight_setrgb_at(4, 4, 4, 0);
        break;
      case 1:
        rgblight_setrgb_at(4, 4, 4, 0);
        break;
      case 2:
        rgblight_setrgb_at(4, 4, 4, 0);
        break;
      case 3:
        rgblight_setrgb_at(4, 4, 4, 0);
        break;
      case 4:
        rgblight_setrgb_at(0, 0, 4, 0);
        break;
      case 5:
        rgblight_setrgb_at(0, 4, 0, 0);
        break;
      case 6:
        rgblight_setrgb_at(0, 0, 4, 0);
        break;
      case 7:
        rgblight_setrgb_at(0, 0, 4, 0);
        break;
      case 8:
        rgblight_setrgb_at(0, 0, 4, 0);
        break;
    }
  }
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────┬───────────────┬───┬──────────────────────────────────────┬─────────────┐   ┌────────────┬────────────┬───┬─────────────────┬───────────┐
//    │     q     │       w       │ f │                  p                   │      g      │   │     j      │     l      │ u │        y        │   bspc    │
//    ├───────────┼───────────────┼───┼──────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┼─────────────────┼───────────┤
//    │     a     │       r       │ s │                  t                   │      d      │   │     h      │     n      │ e │        i        │     o     │
//    ├───────────┼───────────────┼───┼──────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┼─────────────────┼───────────┤
//    │ LSFT_T(z) │ TD(TD_MODS_X) │ c │                  v                   │      b      │   │     k      │     m      │ , │ TD(TD_MODS_DOT) │ RSFT_T(/) │
//    └───────────┴───────────────┴───┼──────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┴─────────────────┴───────────┘
//                                    │ TD(TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI) │ LGUI_T(spc) │   │ LT(1, tab) │ LT(2, ent) │
//                                    └──────────────────────────────────────┴─────────────┘   └────────────┴────────────┘
[0] = LAYOUT_split_3x5_2(
  KC_Q         , KC_W          , KC_F , KC_P                                 , KC_G           ,     KC_J          , KC_L          , KC_U     , KC_Y            , KC_BSPC        ,
  KC_A         , KC_R          , KC_S , KC_T                                 , KC_D           ,     KC_H          , KC_N          , KC_E     , KC_I            , KC_O           ,
  LSFT_T(KC_Z) , TD(TD_MODS_X) , KC_C , KC_V                                 , KC_B           ,     KC_K          , KC_M          , KC_COMMA , TD(TD_MODS_DOT) , RSFT_T(KC_SLSH),
                                        TD(TD_ESC_LALT_LCTL_SPOTLIGHT_EMOJI) , LGUI_T(KC_SPC) ,     LT(1, KC_TAB) , LT(2, KC_ENT)
),

//    ┌───────────┬──────────────────┬───┬─────┬─────┐   ┌─────┬──────┬──────┬──────────────────┬───────────┐
//    │     _     │        -         │ + │  =  │  :  │   │  `  │ mrwd │ mply │       mffd       │    del    │
//    ├───────────┼──────────────────┼───┼─────┼─────┤   ├─────┼──────┼──────┼──────────────────┼───────────┤
//    │     {     │        (         │ ) │  }  │  |  │   │ esc │ left │  up  │       down       │   rght    │
//    ├───────────┼──────────────────┼───┼─────┼─────┤   ├─────┼──────┼──────┼──────────────────┼───────────┤
//    │ LSFT_T([) │ TD(TD_MODS_QUOT) │ " │  ]  │  ;  │   │  ~  │ vold │ mute │ TD(TD_MODS_VOLU) │ RSFT_T(\) │
//    └───────────┴──────────────────┴───┼─────┼─────┤   ├─────┼──────┼──────┴──────────────────┴───────────┘
//                                       │     │     │   │     │      │
//                                       └─────┴─────┘   └─────┴──────┘
[1] = LAYOUT_split_3x5_2(
  KC_UNDS         , KC_MINS          , KC_PLUS , KC_EQL  , KC_COLN ,     KC_GRV   , KC_MRWD , KC_MPLY , KC_MFFD          , KC_DEL         ,
  KC_LCBR         , KC_LPRN          , KC_RPRN , KC_RCBR , KC_PIPE ,     KC_ESC   , KC_LEFT , KC_UP   , KC_DOWN          , KC_RGHT        ,
  LSFT_T(KC_LBRC) , TD(TD_MODS_QUOT) , KC_DQUO , KC_RBRC , KC_SCLN ,     KC_TILDE , KC_VOLD , KC_MUTE , TD(TD_MODS_VOLU) , RSFT_T(KC_BSLS),
                                                 KC_TRNS , KC_TRNS ,     KC_TRNS  , KC_TRNS
),

//    ┌──────┬─────┬────┬─────┬───────┐   ┌─────┬─────┬───┬──────┬───────────┐
//    │  !   │  @  │ #  │  $  │   %   │   │  ^  │  &  │ * │ caps │   bspc    │
//    ├──────┼─────┼────┼─────┼───────┤   ├─────┼─────┼───┼──────┼───────────┤
//    │  1   │  2  │ 3  │  4  │   5   │   │  6  │  7  │ 8 │  9   │     0     │
//    ├──────┼─────┼────┼─────┼───────┤   ├─────┼─────┼───┼──────┼───────────┤
//    │ lsft │     │ no │ no  │ MO(3) │   │ no  │ no  │ , │  .   │ RSFT_T(/) │
//    └──────┴─────┴────┼─────┼───────┤   ├─────┼─────┼───┴──────┴───────────┘
//                      │     │       │   │     │     │
//                      └─────┴───────┘   └─────┴─────┘
[2] = LAYOUT_split_3x5_2(
  KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_CAPS , KC_BSPC        ,
  KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8    , KC_9    , KC_0           ,
  KC_LSFT , KC_TRNS , KC_NO   , KC_NO   , MO(3)   ,     KC_NO   , KC_NO   , KC_COMM , KC_DOT  , RSFT_T(KC_SLSH),
                                KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌─────┬────┬────┬─────────┬─────┐   ┌──────────────────┬───────────────────────┬───────────────────────────┬───────┬───────┐
//    │ no  │ no │ no │   no    │ no  │   │        no        │          no           │            no             │ TO(5) │ TO(4) │
//    ├─────┼────┼────┼─────────┼─────┤   ├──────────────────┼───────────────────────┼───────────────────────────┼───────┼───────┤
//    │ f1  │ f2 │ f3 │   f4    │ f5  │   │        f6        │          f7           │            f8             │  f9   │  f10  │
//    ├─────┼────┼────┼─────────┼─────┤   ├──────────────────┼───────────────────────┼───────────────────────────┼───────┼───────┤
//    │ f11 │ no │ no │ QK_BOOT │     │   │ QK_HAPTIC_TOGGLE │ QK_HAPTIC_BUZZ_TOGGLE │ QK_HAPTIC_FEEDBACK_TOGGLE │  no   │  f12  │
//    └─────┴────┴────┼─────────┼─────┤   ├──────────────────┼───────────────────────┼───────────────────────────┴───────┴───────┘
//                    │         │     │   │                  │                       │
//                    └─────────┴─────┘   └──────────────────┴───────────────────────┘
[3] = LAYOUT_split_3x5_2(
  KC_NO  , KC_NO , KC_NO , KC_NO   , KC_NO   ,     KC_NO            , KC_NO                 , KC_NO                     , TO(5) , TO(4) ,
  KC_F1  , KC_F2 , KC_F3 , KC_F4   , KC_F5   ,     KC_F6            , KC_F7                 , KC_F8                     , KC_F9 , KC_F10,
  KC_F11 , KC_NO , KC_NO , QK_BOOT , KC_TRNS ,     QK_HAPTIC_TOGGLE , QK_HAPTIC_BUZZ_TOGGLE , QK_HAPTIC_FEEDBACK_TOGGLE , KC_NO , KC_F12,
                           KC_TRNS , KC_TRNS ,     KC_TRNS          , KC_TRNS
),

//    ┌───────────┬───┬───┬────────────────────────────────────┬─────────────┐   ┌────────────┬────────────┬───┬───┬───────────┐
//    │     q     │ w │ f │                 p                  │      g      │   │     j      │     l      │ u │ y │   bspc    │
//    ├───────────┼───┼───┼────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┼───┼───────────┤
//    │     a     │ r │ s │                 t                  │      d      │   │     h      │     n      │ e │ i │     o     │
//    ├───────────┼───┼───┼────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┼───┼───────────┤
//    │ LSFT_T(z) │ x │ c │                 v                  │      b      │   │     k      │     m      │ , │ . │ RSFT_T(/) │
//    └───────────┴───┴───┼────────────────────────────────────┼─────────────┤   ├────────────┼────────────┼───┴───┴───────────┘
//                        │ TD(TD_ESC_LCTL_LALT_WINDOWS_EMOJI) │ LCTL_T(spc) │   │ LT(6, tab) │ LT(7, ent) │
//                        └────────────────────────────────────┴─────────────┘   └────────────┴────────────┘
[4] = LAYOUT_split_3x5_2(
  KC_Q         , KC_W , KC_F , KC_P                               , KC_G           ,     KC_J          , KC_L          , KC_U     , KC_Y   , KC_BSPC        ,
  KC_A         , KC_R , KC_S , KC_T                               , KC_D           ,     KC_H          , KC_N          , KC_E     , KC_I   , KC_O           ,
  LSFT_T(KC_Z) , KC_X , KC_C , KC_V                               , KC_B           ,     KC_K          , KC_M          , KC_COMMA , KC_DOT , RSFT_T(KC_SLSH),
                               TD(TD_ESC_LCTL_LALT_WINDOWS_EMOJI) , LCTL_T(KC_SPC) ,     LT(6, KC_TAB) , LT(7, KC_ENT)
),

//    ┌───┬───┬───┬──────┬─────┐   ┌────────────┬────────────┬───┬───┬──────┐
//    │ q │ w │ f │  p   │  g  │   │     j      │     l      │ u │ y │ bspc │
//    ├───┼───┼───┼──────┼─────┤   ├────────────┼────────────┼───┼───┼──────┤
//    │ a │ r │ s │  t   │  d  │   │     h      │     n      │ e │ i │  o   │
//    ├───┼───┼───┼──────┼─────┤   ├────────────┼────────────┼───┼───┼──────┤
//    │ z │ x │ c │  v   │  b  │   │     k      │     m      │ , │ . │  /   │
//    └───┴───┴───┼──────┼─────┤   ├────────────┼────────────┼───┴───┴──────┘
//                │ lctl │ spc │   │ LT(6, tab) │ LT(7, ent) │
//                └──────┴─────┘   └────────────┴────────────┘
[5] = LAYOUT_split_3x5_2(
  KC_Q , KC_W , KC_F , KC_P    , KC_G   ,     KC_J          , KC_L          , KC_U     , KC_Y   , KC_BSPC,
  KC_A , KC_R , KC_S , KC_T    , KC_D   ,     KC_H          , KC_N          , KC_E     , KC_I   , KC_O   ,
  KC_Z , KC_X , KC_C , KC_V    , KC_B   ,     KC_K          , KC_M          , KC_COMMA , KC_DOT , KC_SLSH,
                       KC_LCTL , KC_SPC ,     LT(6, KC_TAB) , LT(7, KC_ENT)
),

//    ┌───────────┬───┬───┬─────┬─────┐   ┌─────┬──────┬──────┬──────┬───────────┐
//    │     _     │ - │ + │  =  │  :  │   │  `  │ mrwd │ mply │ mffd │    del    │
//    ├───────────┼───┼───┼─────┼─────┤   ├─────┼──────┼──────┼──────┼───────────┤
//    │     {     │ ( │ ) │  }  │  |  │   │ esc │ left │  up  │ down │   rght    │
//    ├───────────┼───┼───┼─────┼─────┤   ├─────┼──────┼──────┼──────┼───────────┤
//    │ LSFT_T([) │ ' │ " │  ]  │  ;  │   │  ~  │ vold │ mute │ volu │ RSFT_T(\) │
//    └───────────┴───┴───┼─────┼─────┤   ├─────┼──────┼──────┴──────┴───────────┘
//                        │     │     │   │     │      │
//                        └─────┴─────┘   └─────┴──────┘
[6] = LAYOUT_split_3x5_2(
  KC_UNDS         , KC_MINS , KC_PLUS , KC_EQL  , KC_COLN ,     KC_GRV   , KC_MRWD , KC_MPLY , KC_MFFD , KC_DEL         ,
  KC_LCBR         , KC_LPRN , KC_RPRN , KC_RCBR , KC_PIPE ,     KC_ESC   , KC_LEFT , KC_UP   , KC_DOWN , KC_RGHT        ,
  LSFT_T(KC_LBRC) , KC_QUOT , KC_DQUO , KC_RBRC , KC_SCLN ,     KC_TILDE , KC_VOLD , KC_MUTE , KC_VOLU , RSFT_T(KC_BSLS),
                                        KC_TRNS , KC_TRNS ,     KC_TRNS  , KC_TRNS
),

//    ┌──────┬────┬────┬─────┬───────┐   ┌─────┬─────┬───┬──────┬───────────┐
//    │  !   │ @  │ #  │  $  │   %   │   │  ^  │  &  │ * │ caps │   bspc    │
//    ├──────┼────┼────┼─────┼───────┤   ├─────┼─────┼───┼──────┼───────────┤
//    │  1   │ 2  │ 3  │  4  │   5   │   │  6  │  7  │ 8 │  9   │     0     │
//    ├──────┼────┼────┼─────┼───────┤   ├─────┼─────┼───┼──────┼───────────┤
//    │ lsft │ no │ no │ no  │ MO(8) │   │ no  │ no  │ , │  .   │ RSFT_T(/) │
//    └──────┴────┴────┼─────┼───────┤   ├─────┼─────┼───┴──────┴───────────┘
//                     │     │       │   │     │     │
//                     └─────┴───────┘   └─────┴─────┘
[7] = LAYOUT_split_3x5_2(
  KC_EXLM , KC_AT , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_CAPS , KC_BSPC        ,
  KC_1    , KC_2  , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8    , KC_9    , KC_0           ,
  KC_LSFT , KC_NO , KC_NO   , KC_NO   , MO(8)   ,     KC_NO   , KC_NO   , KC_COMM , KC_DOT  , RSFT_T(KC_SLSH),
                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌─────┬────┬────┬─────────┬─────┐   ┌─────┬─────┬───────┬───────┬───────┐
//    │ no  │ no │ no │   no    │ no  │   │ no  │ no  │ TO(4) │ TO(5) │ TO(0) │
//    ├─────┼────┼────┼─────────┼─────┤   ├─────┼─────┼───────┼───────┼───────┤
//    │ f1  │ f2 │ f3 │   f4    │ f5  │   │ f6  │ f7  │  f8   │  f9   │  f10  │
//    ├─────┼────┼────┼─────────┼─────┤   ├─────┼─────┼───────┼───────┼───────┤
//    │ f11 │ no │ no │ QK_BOOT │     │   │ no  │ no  │  no   │  no   │  f12  │
//    └─────┴────┴────┼─────────┼─────┤   ├─────┼─────┼───────┴───────┴───────┘
//                    │         │     │   │     │     │
//                    └─────────┴─────┘   └─────┴─────┘
[8] = LAYOUT_split_3x5_2(
  KC_NO  , KC_NO , KC_NO , KC_NO   , KC_NO   ,     KC_NO   , KC_NO   , TO(4) , TO(5) , TO(0) ,
  KC_F1  , KC_F2 , KC_F3 , KC_F4   , KC_F5   ,     KC_F6   , KC_F7   , KC_F8 , KC_F9 , KC_F10,
  KC_F11 , KC_NO , KC_NO , QK_BOOT , KC_TRNS ,     KC_NO   , KC_NO   , KC_NO , KC_NO , KC_F12,
                           KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
)
};
// clang-format on
