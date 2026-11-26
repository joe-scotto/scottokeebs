#include QMK_KEYBOARD_H

enum custom_keycodes {
  MIDI_DRUM_1 = QK_KB_0,
  MIDI_DRUM_2,
  MIDI_DRUM_3,
  MIDI_DRUM_4,
  MIDI_DRUM_5,
  MIDI_DRUM_6,
  MIDI_DRUM_7,
  MIDI_DRUM_8
};

extern MidiDevice midi_device;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t note;

  switch (keycode) {
    case MIDI_DRUM_1:
      note = 40;
      break;

    case MIDI_DRUM_2:
      note = 41;
      break;

    case MIDI_DRUM_3:
      note = 42;
      break;

    case MIDI_DRUM_4:
      note = 43;
      break;

    case MIDI_DRUM_5:
      note = 36;
      break;

    case MIDI_DRUM_6:
      note = 37;
      break;

    case MIDI_DRUM_7:
      note = 38;
      break;

    case MIDI_DRUM_8:
      note = 39;
      break;

    default:
      return true;
  }

  if (record->event.pressed) {
    midi_send_noteon(&midi_device, midi_config.channel, note, 127);
  } else {
    midi_send_noteoff(&midi_device, midi_config.channel, note, 0);
  }

  return false;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬─────────┬────────────┬─────────┐       ┌─────────────┬─────────────┬─────────────┬─────────────┐        ┌─────────┬────────┬─────────┬─────────┐
//    │ RGUI(S(f9)) │   no    │    spc     │ RSFT(c) │       │ MIDI_DRUM_1 │ MIDI_DRUM_2 │ MIDI_DRUM_3 │ MIDI_DRUM_4 │        │ RGUI(u) │  del   │ RSFT(s) │ RSFT(o) │
//    ├─────────────┼─────────┼────────────┼─────────┤       ├─────────────┼─────────────┼─────────────┼─────────────┤        ├─────────┼────────┼─────────┼─────────┤
//    │   MI_OCTD   │ LGUI(z) │ LGUI(S(z)) │ MI_OCTU │       │ MIDI_DRUM_5 │ MIDI_DRUM_6 │ MIDI_DRUM_7 │ MIDI_DRUM_8 │        │  left   │   up   │  down   │  rght   │
//    └─────────────┼─────────┼────────────┼─────────┼───────┼─────────────┼─────────────┼─────────────┼─────────────┼────────┼─────────┼────────┼─────────┼─────────┤
//                  │  MI_Cs  │   MI_Ds    │         │ MI_Fs │    MI_Gs    │    MI_As    │             │   MI_Cs1    │ MI_Ds1 │         │ MI_Fs1 │ MI_Gs1  │ MI_As1  │
//    ┌─────────────┼─────────┼────────────┼─────────┼───────┼─────────────┼─────────────┼─────────────┼─────────────┼────────┼─────────┼────────┼─────────┼─────────┤
//    │    MI_C     │  MI_D   │    MI_E    │  MI_F   │ MI_G  │    MI_A     │    MI_B     │    MI_C1    │    MI_D1    │ MI_E1  │  MI_F1  │ MI_G1  │  MI_A1  │  MI_B1  │
//    └─────────────┴─────────┴────────────┴─────────┴───────┴─────────────┴─────────────┴─────────────┴─────────────┴────────┴─────────┴────────┴─────────┴─────────┘
[0] = LAYOUT(
  RGUI(S(KC_F9)) , KC_NO      , KC_SPACE      , RSFT(KC_C) ,         MIDI_DRUM_1 , MIDI_DRUM_2 , MIDI_DRUM_3 , MIDI_DRUM_4 ,          RGUI(KC_U) , KC_DEL , RSFT(KC_S) , RSFT(KC_O),
  MI_OCTD        , LGUI(KC_Z) , LGUI(S(KC_Z)) , MI_OCTU    ,         MIDI_DRUM_5 , MIDI_DRUM_6 , MIDI_DRUM_7 , MIDI_DRUM_8 ,          KC_LEFT    , KC_UP  , KC_DOWN    , KC_RIGHT  ,
                   MI_Cs      , MI_Ds         ,              MI_Fs , MI_Gs       , MI_As       ,               MI_Cs1      , MI_Ds1 ,              MI_Fs1 , MI_Gs1     , MI_As1    ,
  MI_C           , MI_D       , MI_E          , MI_F       , MI_G  , MI_A        , MI_B        , MI_C1       , MI_D1       , MI_E1  , MI_F1      , MI_G1  , MI_A1      , MI_B1
)
};
// clang-format on
