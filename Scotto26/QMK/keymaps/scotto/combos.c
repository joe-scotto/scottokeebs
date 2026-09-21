#include "keys.h"
#include QMK_KEYBOARD_H

// Base layer
const uint16_t PROGMEM g_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM d_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM h_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_M, KC_COMMA, COMBO_END};

// Code layer
const uint16_t PROGMEM coln_combo[] = {KC_PLUS, KC_EQL, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_RPRN, KC_RCBR, COMBO_END};
const uint16_t PROGMEM scln_combo[] = {KC_DQUO, KC_RBRC, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_MRWD, KC_MPLY, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_LEFT, KC_UP, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_VOLD, KC_MUTE, COMBO_END};

// Number layer
const uint16_t PROGMEM perc_combo[] = {KC_HASH, KC_DLR, COMBO_END};
const uint16_t PROGMEM five_combo[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM circ_combo[] = {KC_AMPR, KC_ASTR, COMBO_END};
const uint16_t PROGMEM six_combo[] = {KC_7, KC_8, COMBO_END};

// Function layer
const uint16_t PROGMEM f5_combo[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM f6_combo[] = {KC_F7, KC_F8, COMBO_END};

// Generic combos
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_Y, KC_BSPC, COMBO_END};
const uint16_t PROGMEM space_combo[] = {KC_V, KC_B, COMBO_END};

// Create combos
combo_t key_combos[] = {
    // Base
    [G_COMBO] = COMBO(g_combo, KC_G),
    [D_COMBO] = COMBO(d_combo, KC_D),
    [B_COMBO] = COMBO(b_combo, KC_B),
    [J_COMBO] = COMBO(j_combo, KC_J),
    [H_COMBO] = COMBO(h_combo, KC_H),
    [K_COMBO] = COMBO(k_combo, KC_K),

    // Code
    [COLN_COMBO] = COMBO(coln_combo, KC_COLN),
    [PIPE_COMBO] = COMBO(pipe_combo, KC_PIPE),
    [SCLN_COMBO] = COMBO(scln_combo, KC_SCLN),
    [GRV_COMBO] = COMBO(grv_combo, KC_GRV),
    [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
    [TILDE_COMBO] = COMBO(tilde_combo, KC_TILDE),

    // Number
    [PERC_COMBO] = COMBO(perc_combo, KC_PERC),
    [FIVE_COMBO] = COMBO(five_combo, KC_5),
    [CIRC_COMBO] = COMBO(circ_combo, KC_CIRC),
    [SIX_COMBO] = COMBO(six_combo, KC_6),

    // Function
    [F5_COMBO] = COMBO(f5_combo, KC_F5),
    [F6_COMBO] = COMBO(f6_combo, KC_F6),

    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [ENTER_COMBO] = COMBO(enter_combo, KC_ENT),
    [SPACE_COMBO] = COMBO(space_combo, KC_SPC),
};
