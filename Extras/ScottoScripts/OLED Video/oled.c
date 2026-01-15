#include "frames.c"
#include "quantum.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180; // flips the display 180 degrees if offhand
}

#define NUM_FRAMES 120
#define FRAME_WIDTH 128
#define FRAME_HEIGHT 64
#define FRAME_SIZE                                                             \
  (FRAME_WIDTH * FRAME_HEIGHT / 8) // 128*64 / 8 = 1024 bytes per frame
#define FRAME_DELAY 100            // ms per frame, ~10 fps

bool oled_task_user(void) {
  static uint16_t frame_index = 0;
  static uint32_t last_update = 0;

  // Only update frame every FRAME_DELAY ms
  if (timer_elapsed32(last_update) > FRAME_DELAY) {
    last_update = timer_read32();

    // Write current frame to OLED (cast to const char* to fix signedness)
    oled_write_raw_P((const char *)frames[frame_index], FRAME_SIZE);

    // Advance to next frame, loop back to 0
    frame_index++;
    if (frame_index >= NUM_FRAMES)
      frame_index = 0;
  }

  return false; // keep other OLED content disabled
}

#endif
