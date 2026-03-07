#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0 ... 4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
