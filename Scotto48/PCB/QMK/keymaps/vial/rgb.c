#include QMK_KEYBOARD_H

#define SCALE(x) ((x * RGB_BRIGHTNESS) / 255)

void housekeeping_task_user(void) {
  uint8_t layer = get_highest_layer(layer_state | default_layer_state);
  static bool init = false;

  if (!init) {
    gpio_set_pin_output(GP25);
    gpio_write_pin_low(GP25);
    init = true;
  }

  // Caps lock LED
  gpio_write_pin(GP25, host_keyboard_led_state().caps_lock);

  // Layer colors
  switch (layer) {
    case 0:
      rgblight_setrgb(SCALE(255), SCALE(255), SCALE(255)); // White
      return;
    case 1:
      rgblight_setrgb(SCALE(255), SCALE(255), 0); // Yellow
      return;

    case 2:
      rgblight_setrgb(0, 0, SCALE(255)); // Blue
      return;

    case 3:
      rgblight_setrgb(SCALE(255), SCALE(64), 0); // Orange
      return;

    case 4:
      rgblight_setrgb(SCALE(128), 0, SCALE(255)); // Purple
      return;
  }
}
