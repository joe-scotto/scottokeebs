#include "custom_keys.c"
#include "mod_lock.c"
#include QMK_KEYBOARD_H

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
  NUMBER_TAB,
  NUMBER_F11,
  NUMBER_F4,
  NUMBER_F5,
  NUMBER_F6,
  NUMBER_F12,
  NUMBER_F10,
  NUMBER_F1,
  NUMBER_F2,
  NUMBER_F3,
  SPECIAL_BASE_ESC,
  SPECIAL_NUMBER_ESC,
  SPECIAL_SYMBOL_ESC,
  SPECIAL_BASE_HOME,
  SPECIAL_NUMBER_HOME,
  SPECIAL_SYMBOL_HOME,
  SPECIAL_BASE_END,
  SPECIAL_NUMBER_END,
  SPECIAL_SYMBOL_END,
  SPECIAL_BASE_PAUSE,
  SPECIAL_NUMBER_PAUSE,
  SPECIAL_SYMBOL_PAUSE,
  SPECIAL_BASE_PAGE_UP,
  SPECIAL_NUMBER_PAGE_UP,
  SPECIAL_SYMBOL_PAGE_UP,
  SPECIAL_BASE_INSERT,
  SPECIAL_NUMBER_INSERT,
  SPECIAL_SYMBOL_INSERT,
  SPECIAL_BASE_CTRL,
  SPECIAL_NUMBER_CTRL,
  SPECIAL_SYMBOL_CTRL,
  SPECIAL_BASE_ALT,
  SPECIAL_NUMBER_ALT,
  SPECIAL_SYMBOL_ALT,
  SPECIAL_BASE_UP,
  SPECIAL_NUMBER_UP,
  SPECIAL_SYMBOL_UP,
  SPECIAL_BASE_PAGE_DOWN,
  SPECIAL_NUMBER_PAGE_DOWN,
  SPECIAL_SYMBOL_PAGE_DOWN,
  SPECIAL_BASE_DELETE,
  SPECIAL_NUMBER_DELETE,
  SPECIAL_SYMBOL_DELETE,
  SPECIAL_BASE_BACKSPACE,
  SPECIAL_NUMBER_BACKSPACE,
  SPECIAL_SYMBOL_BACKSPACE,
  SPECIAL_BASE_RIGHT,
  SPECIAL_NUMBER_RIGHT,
  SPECIAL_SYMBOL_RIGHT,
  SPECIAL_BASE_DOWN,
  SPECIAL_NUMBER_DOWN,
  SPECIAL_SYMBOL_DOWN,
  SPECIAL_BASE_LEFT,
  SPECIAL_NUMBER_LEFT,
  SPECIAL_SYMBOL_LEFT,
  SPECIAL_BASE_RESET,
  SPECIAL_NUMBER_RESET,
  SPECIAL_SYMBOL_RESET,
  SPECIAL_BASE_OS_TOGGLE,
  SPECIAL_NUMBER_OS_TOGGLE,
  SPECIAL_SYMBOL_OS_TOGGLE,
  SPECIAL_BASE_CAPS,
  SPECIAL_NUMBER_CAPS,
  SPECIAL_SYMBOL_CAPS,
  SYMBOL_TAB,
  SYMBOL_PLUS,
  SYMBOL_EQUAL,
  SYMBOL_DOLLAR,
  SYMBOL_HASH,
  SYMBOL_SLASH,
  SYMBOL_PERCENT,
  SYMBOL_PIPE,
  SYMBOL_TILDE,
  SYMBOL_CARET,
  SYMBOL_GRAVE,
  SYMBOL_RIGHT_ANGLE_BRACKET,
  SYMBOl_RIGHT_PAREN,
  SYMBOL_RIGHT_BRACKET,
  SYMBOL_RIGHT_CURLY_BRACE,
  SYMBOL_COMMA,
  BASE_BOOTLOADER,
  NUMBER_BOOTLOADER,
  SYMBOL_BOOTLOADER,
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
const uint16_t PROGMEM number_f7[] = {KC_SPC, KC_7, COMBO_END};
const uint16_t PROGMEM number_f8[] = {KC_SPC, KC_8, COMBO_END};
const uint16_t PROGMEM number_f9[] = {KC_SPC, KC_9, COMBO_END};
const uint16_t PROGMEM number_tab[] = {KC_SPC, KC_KP_MINUS, COMBO_END};
const uint16_t PROGMEM number_f11[] = {KC_SPC, KC_KP_SLASH, COMBO_END};
const uint16_t PROGMEM number_f4[] = {KC_SPC, KC_4, COMBO_END};
const uint16_t PROGMEM number_f5[] = {KC_SPC, KC_5, COMBO_END};
const uint16_t PROGMEM number_f6[] = {KC_SPC, KC_6, COMBO_END};
const uint16_t PROGMEM number_f12[] = {KC_SPC, KC_KP_PLUS, COMBO_END};
const uint16_t PROGMEM number_f10[] = {KC_SPC, KC_0, COMBO_END};
const uint16_t PROGMEM number_f1[] = {KC_SPC, KC_1, COMBO_END};
const uint16_t PROGMEM number_f2[] = {KC_SPC, KC_2, COMBO_END};
const uint16_t PROGMEM number_f3[] = {KC_SPC, KC_3, COMBO_END};

// Orange
const uint16_t PROGMEM special_base_esc[] = {TO(1), KC_F, COMBO_END};
const uint16_t PROGMEM special_number_esc[] = {TO(0), KC_KP_ASTERISK, COMBO_END};
const uint16_t PROGMEM special_symbol_esc[] = {TO(1), KC_QUESTION, COMBO_END};
const uint16_t PROGMEM special_base_home[] = {TO(1), KC_A, COMBO_END};
const uint16_t PROGMEM special_number_home[] = {TO(0), KC_7, COMBO_END};
const uint16_t PROGMEM special_symbol_home[] = {TO(1), KC_AMPERSAND, COMBO_END};
const uint16_t PROGMEM special_base_end[] = {TO(1), KC_R, COMBO_END};
const uint16_t PROGMEM special_number_end[] = {TO(0), KC_8, COMBO_END};
const uint16_t PROGMEM special_symbol_end[] = {TO(1), KC_ASTERISK, COMBO_END};
const uint16_t PROGMEM special_base_pause[] = {TO(1), KC_W, COMBO_END};
const uint16_t PROGMEM special_number_pause[] = {TO(0), KC_9, COMBO_END};
const uint16_t PROGMEM special_symbol_pause[] = {TO(1), KC_COLON, COMBO_END};
const uint16_t PROGMEM special_base_page_up[] = {TO(1), KC_P, COMBO_END};
const uint16_t PROGMEM special_number_page_up[] = {TO(0), KC_KP_MINUS, COMBO_END};
const uint16_t PROGMEM special_symbol_page_up[] = {TO(1), KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM special_base_insert[] = {TO(1), KC_O, COMBO_END};
const uint16_t PROGMEM special_number_insert[] = {TO(0), KC_KP_SLASH, COMBO_END};
const uint16_t PROGMEM special_symbol_insert[] = {TO(1), KC_SLASH, COMBO_END};
const uint16_t PROGMEM special_base_ctrl[] = {TO(1), KC_E, COMBO_END};
const uint16_t PROGMEM special_number_ctrl[] = {TO(0), KC_4, COMBO_END};
const uint16_t PROGMEM special_symbol_ctrl[] = {TO(1), KC_EXCLAIM, COMBO_END};
const uint16_t PROGMEM special_base_alt[] = {TO(1), KC_H, COMBO_END};
const uint16_t PROGMEM special_number_alt[] = {TO(0), KC_5, COMBO_END};
const uint16_t PROGMEM special_symbol_alt[] = {TO(1), KC_MINUS, COMBO_END};
const uint16_t PROGMEM special_base_up[] = {TO(1), KC_T, COMBO_END};
const uint16_t PROGMEM special_number_up[] = {TO(0), KC_6, COMBO_END};
const uint16_t PROGMEM special_symbol_up[] = {TO(1), KC_AT, COMBO_END};
const uint16_t PROGMEM special_base_page_down[] = {TO(1), KC_D, COMBO_END};
const uint16_t PROGMEM special_number_page_down[] = {TO(0), KC_KP_PLUS, COMBO_END};
const uint16_t PROGMEM special_symbol_page_down[] = {TO(1), KC_UNDERSCORE, COMBO_END};
const uint16_t PROGMEM special_base_delete[] = {TO(1), KC_U, COMBO_END};
const uint16_t PROGMEM special_number_delete[] = {TO(0), KC_0, COMBO_END};
const uint16_t PROGMEM special_symbol_delete[] = {TO(1), KC_DOUBLE_QUOTE, COMBO_END};
const uint16_t PROGMEM special_base_backspace[] = {TO(1), KC_I, COMBO_END};
const uint16_t PROGMEM special_number_backspace[] = {TO(0), KC_1, COMBO_END};
const uint16_t PROGMEM special_symbol_backspace[] = {TO(1), KC_LEFT_ANGLE_BRACKET, COMBO_END};
const uint16_t PROGMEM special_base_right[] = {TO(1), KC_Y, COMBO_END};
const uint16_t PROGMEM special_number_right[] = {TO(0), KC_EQUAL, COMBO_END};
const uint16_t PROGMEM special_symbol_right[] = {TO(1), KC_LEFT_CURLY_BRACE, COMBO_END};
const uint16_t PROGMEM special_base_down[] = {TO(1), KC_S, COMBO_END};
const uint16_t PROGMEM special_number_down[] = {TO(0), KC_3, COMBO_END};
const uint16_t PROGMEM special_symbol_down[] = {TO(1), KC_LEFT_BRACKET, COMBO_END};
const uint16_t PROGMEM special_base_left[] = {TO(1), KC_N, COMBO_END};
const uint16_t PROGMEM special_number_left[] = {TO(0), KC_2, COMBO_END};
const uint16_t PROGMEM special_symbol_left[] = {TO(1), KC_LEFT_PAREN, COMBO_END};
const uint16_t PROGMEM special_base_reset[] = {TO(1), TO(2), COMBO_END};
const uint16_t PROGMEM special_number_reset[] = {TO(0), TO(2), COMBO_END};
const uint16_t PROGMEM special_symbol_reset[] = {TO(1), TO(0), COMBO_END};
const uint16_t PROGMEM special_base_os_toggle[] = {KC_ENTER, TO(1), COMBO_END};
const uint16_t PROGMEM special_number_os_toggle[] = {KC_ENTER, TO(0), COMBO_END};
const uint16_t PROGMEM special_symbol_os_toggle[] = {KC_ENTER, TO(1), COMBO_END};
const uint16_t PROGMEM special_base_caps[] = {TO(1), TD(SFT_LOCK), COMBO_END};
const uint16_t PROGMEM special_number_caps[] = {TO(0), TD(SFT_LOCK), COMBO_END};
const uint16_t PROGMEM special_symbol_caps[] = {TO(1), TD(SFT_LOCK), COMBO_END};

// Symbol
const uint16_t PROGMEM symbol_tab[] = {KC_SPC, KC_QUESTION, COMBO_END};
const uint16_t PROGMEM symbol_plus[] = {KC_SPC, KC_AMPERSAND, COMBO_END};
const uint16_t PROGMEM symbol_equal[] = {KC_SPC, KC_ASTERISK, COMBO_END};
const uint16_t PROGMEM symbol_dollar[] = {KC_SPC, KC_COLON, COMBO_END};
const uint16_t PROGMEM symbol_hash[] = {KC_SPC, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM symbol_slash[] = {KC_SPC, KC_SLASH, COMBO_END};
const uint16_t PROGMEM symbol_percent[] = {KC_SPC, KC_EXCLAIM, COMBO_END};
const uint16_t PROGMEM symbol_pipe[] = {KC_SPC, KC_MINUS, COMBO_END};
const uint16_t PROGMEM symbol_tilde[] = {KC_SPC, KC_AT, COMBO_END};
const uint16_t PROGMEM symbol_caret[] = {KC_SPC, KC_UNDERSCORE, COMBO_END};
const uint16_t PROGMEM symbol_grave[] = {KC_SPC, KC_DOUBLE_QUOTE, COMBO_END};
const uint16_t PROGMEM symbol_right_angle_bracket[] = {KC_SPC, KC_LEFT_ANGLE_BRACKET, COMBO_END};
const uint16_t PROGMEM symbol_right_paren[] = {KC_SPC, KC_LEFT_PAREN, COMBO_END};
const uint16_t PROGMEM symbol_right_bracket[] = {KC_SPC, KC_LEFT_BRACKET, COMBO_END};
const uint16_t PROGMEM symbol_right_curly_brace[] = {KC_SPC, KC_LEFT_CURLY_BRACE, COMBO_END};
const uint16_t PROGMEM symbol_comma[] = {KC_SPC, TO(0), COMBO_END};

// Bootloader
const uint16_t PROGMEM base_bootloader[] = {TD(SFT_LOCK), TO(2), KC_SPC, COMBO_END};
const uint16_t PROGMEM number_bootloader[] = {TD(SFT_LOCK), TO(2), KC_SPC, COMBO_END};
const uint16_t PROGMEM symbol_bootloader[] = {TD(SFT_LOCK), TO(0), KC_SPC, COMBO_END};

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
    [GREEN_CMD] = COMBO(green_cmd, OSM(MOD_RGUI)),
    [GREEN_APP] = COMBO(green_app, KC_APP),
    [GREEN_K] = COMBO(green_k, KC_K),
    [GREEN_G] = COMBO(green_g, KC_G),
    [GREEN_X] = COMBO(green_x, KC_X),
    [GREEN_COMMA] = COMBO(green_comma, KC_COMMA),
    [GREEN_PERIOD] = COMBO(green_period, KC_DOT),
    [NUMBER_F7] = COMBO(number_f7, KC_F7),
    [NUMBER_F8] = COMBO(number_f8, KC_F8),
    [NUMBER_F9] = COMBO(number_f9, KC_F9),
    [NUMBER_TAB] = COMBO(number_tab, KC_TAB),
    [NUMBER_F11] = COMBO(number_f11, KC_F11),
    [NUMBER_F4] = COMBO(number_f4, KC_F4),
    [NUMBER_F5] = COMBO(number_f5, KC_F5),
    [NUMBER_F6] = COMBO(number_f6, KC_F6),
    [NUMBER_F12] = COMBO(number_f12, KC_F12),
    [NUMBER_F10] = COMBO(number_f10, KC_F10),
    [NUMBER_F1] = COMBO(number_f1, KC_F1),
    [NUMBER_F2] = COMBO(number_f2, KC_F2),
    [NUMBER_F3] = COMBO(number_f3, KC_F3),
    [SPECIAL_BASE_ESC] = COMBO(special_base_esc, KC_ESC),
    [SPECIAL_NUMBER_ESC] = COMBO(special_number_esc, KC_ESC),
    [SPECIAL_SYMBOL_ESC] = COMBO(special_symbol_esc, KC_ESC),
    [SPECIAL_BASE_HOME] = COMBO(special_base_home, KC_HOME),
    [SPECIAL_NUMBER_HOME] = COMBO(special_number_home, KC_HOME),
    [SPECIAL_SYMBOL_HOME] = COMBO(special_symbol_home, KC_HOME),
    [SPECIAL_BASE_END] = COMBO(special_base_end, KC_END),
    [SPECIAL_NUMBER_END] = COMBO(special_number_end, KC_END),
    [SPECIAL_SYMBOL_END] = COMBO(special_symbol_end, KC_END),
    [SPECIAL_BASE_PAUSE] = COMBO(special_base_pause, KC_PAUSE),
    [SPECIAL_NUMBER_PAUSE] = COMBO(special_number_pause, KC_PAUSE),
    [SPECIAL_SYMBOL_PAUSE] = COMBO(special_symbol_pause, KC_PAUSE),
    [SPECIAL_BASE_PAGE_UP] = COMBO(special_base_page_up, KC_PAGE_UP),
    [SPECIAL_NUMBER_PAGE_UP] = COMBO(special_number_page_up, KC_PAGE_UP),
    [SPECIAL_SYMBOL_PAGE_UP] = COMBO(special_symbol_page_up, KC_PAGE_UP),
    [SPECIAL_BASE_INSERT] = COMBO(special_base_insert, KC_INSERT),
    [SPECIAL_NUMBER_INSERT] = COMBO(special_number_insert, KC_INSERT),
    [SPECIAL_SYMBOL_INSERT] = COMBO(special_symbol_insert, KC_INSERT),
    [SPECIAL_BASE_CTRL] = COMBO(special_base_ctrl, TD(CTRL_LOCK)),
    [SPECIAL_NUMBER_CTRL] = COMBO(special_number_ctrl, TD(CTRL_LOCK)),
    [SPECIAL_SYMBOL_CTRL] = COMBO(special_symbol_ctrl, TD(CTRL_LOCK)),
    [SPECIAL_BASE_ALT] = COMBO(special_base_alt, TD(ALT_LOCK)),
    [SPECIAL_NUMBER_ALT] = COMBO(special_number_alt, TD(ALT_LOCK)),
    [SPECIAL_SYMBOL_ALT] = COMBO(special_symbol_alt, TD(ALT_LOCK)),
    [SPECIAL_BASE_UP] = COMBO(special_base_up, KC_UP),
    [SPECIAL_NUMBER_UP] = COMBO(special_number_up, KC_UP),
    [SPECIAL_SYMBOL_UP] = COMBO(special_symbol_up, KC_UP),
    [SPECIAL_BASE_PAGE_DOWN] = COMBO(special_base_page_down, KC_PAGE_DOWN),
    [SPECIAL_NUMBER_PAGE_DOWN] = COMBO(special_number_page_down, KC_PAGE_DOWN),
    [SPECIAL_SYMBOL_PAGE_DOWN] = COMBO(special_symbol_page_down, KC_PAGE_DOWN),
    [SPECIAL_BASE_DELETE] = COMBO(special_base_delete, KC_DELETE),
    [SPECIAL_NUMBER_DELETE] = COMBO(special_number_delete, KC_DELETE),
    [SPECIAL_SYMBOL_DELETE] = COMBO(special_symbol_delete, KC_DELETE),
    [SPECIAL_BASE_BACKSPACE] = COMBO(special_base_backspace, KC_BSPC),
    [SPECIAL_NUMBER_BACKSPACE] = COMBO(special_number_backspace, KC_BSPC),
    [SPECIAL_SYMBOL_BACKSPACE] = COMBO(special_symbol_backspace, KC_BSPC),
    [SPECIAL_BASE_RIGHT] = COMBO(special_base_right, KC_RIGHT),
    [SPECIAL_NUMBER_RIGHT] = COMBO(special_number_right, KC_RIGHT),
    [SPECIAL_SYMBOL_RIGHT] = COMBO(special_symbol_right, KC_RIGHT),
    [SPECIAL_BASE_DOWN] = COMBO(special_base_down, KC_DOWN),
    [SPECIAL_NUMBER_DOWN] = COMBO(special_number_down, KC_DOWN),
    [SPECIAL_SYMBOL_DOWN] = COMBO(special_symbol_down, KC_DOWN),
    [SPECIAL_BASE_LEFT] = COMBO(special_base_left, KC_LEFT),
    [SPECIAL_NUMBER_LEFT] = COMBO(special_number_left, KC_LEFT),
    [SPECIAL_SYMBOL_LEFT] = COMBO(special_symbol_left, KC_LEFT),
    [SPECIAL_BASE_RESET] = COMBO(special_base_reset, QK_REBOOT),
    [SPECIAL_NUMBER_RESET] = COMBO(special_number_reset, QK_REBOOT),
    [SPECIAL_SYMBOL_RESET] = COMBO(special_symbol_reset, QK_REBOOT),
    [SPECIAL_BASE_OS_TOGGLE] = COMBO(special_base_os_toggle, QK_MAGIC_TOGGLE_CTL_GUI),
    [SPECIAL_NUMBER_OS_TOGGLE] = COMBO(special_number_os_toggle, QK_MAGIC_TOGGLE_CTL_GUI),
    [SPECIAL_SYMBOL_OS_TOGGLE] = COMBO(special_symbol_os_toggle, QK_MAGIC_TOGGLE_CTL_GUI),
    [SPECIAL_BASE_CAPS] = COMBO(special_base_caps, KC_CAPS),
    [SPECIAL_NUMBER_CAPS] = COMBO(special_number_caps, KC_CAPS),
    [SPECIAL_SYMBOL_CAPS] = COMBO(special_symbol_caps, KC_CAPS),
    [SYMBOL_TAB] = COMBO(symbol_tab, KC_TAB),
    [SYMBOL_PLUS] = COMBO(symbol_plus, KC_PLUS),
    [SYMBOL_EQUAL] = COMBO(symbol_equal, KC_EQUAL),
    [SYMBOL_DOLLAR] = COMBO(symbol_dollar, KC_DOLLAR),
    [SYMBOL_HASH] = COMBO(symbol_hash, KC_HASH),
    [SYMBOL_SLASH] = COMBO(symbol_slash, KC_BACKSLASH),
    [SYMBOL_PERCENT] = COMBO(symbol_percent, KC_PERCENT),
    [SYMBOL_PIPE] = COMBO(symbol_pipe, KC_PIPE),
    [SYMBOL_TILDE] = COMBO(symbol_tilde, KC_TILDE),
    [SYMBOL_CARET] = COMBO(symbol_caret, KC_CARET),
    [SYMBOL_GRAVE] = COMBO(symbol_grave, KC_GRAVE),
    [SYMBOL_RIGHT_ANGLE_BRACKET] = COMBO(symbol_right_angle_bracket, KC_RIGHT_ANGLE_BRACKET),
    [SYMBOl_RIGHT_PAREN] = COMBO(symbol_right_paren, KC_RIGHT_PAREN),
    [SYMBOL_RIGHT_BRACKET] = COMBO(symbol_right_bracket, KC_RIGHT_BRACKET),
    [SYMBOL_RIGHT_CURLY_BRACE] = COMBO(symbol_right_curly_brace, KC_RIGHT_CURLY_BRACE),
    [SYMBOL_COMMA] = COMBO(symbol_comma, KC_COMMA),
    [BASE_BOOTLOADER] = COMBO(base_bootloader, QK_BOOTLOADER),
    [NUMBER_BOOTLOADER] = COMBO(number_bootloader, QK_BOOTLOADER),
    [SYMBOL_BOOTLOADER] = COMBO(symbol_bootloader, QK_BOOTLOADER),
};
