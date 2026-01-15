import re

# Read your exported hex file
with open("frames.txt", "r") as f:
    data = f.read()

frames = []
current_frame = []

for line in data.splitlines():
    # Skip empty lines
    if not line.strip():
        continue

    # If line is a frame comment, start a new frame
    if line.strip().startswith("// 'out_"):
        if current_frame:
            frames.append(current_frame)
            current_frame = []
        continue

    # Extract all hex numbers in the line
    hex_values = re.findall(r"0x[0-9a-fA-F]+", line)
    current_frame.extend(hex_values)

# Append last frame
if current_frame:
    frames.append(current_frame)

num_frames = len(frames)
frame_size = len(frames[0])

# ----------------------------
# Write frames.c
# ----------------------------
with open("frames.c", "w") as f:
    f.write("#include <stdint.h>\n")
    f.write("#ifdef AVR\n#include <avr/pgmspace.h>\n#else\n#define PROGMEM\n#endif\n\n")
    f.write(
        "const uint8_t PROGMEM frames[{}][{}] = {{\n".format(num_frames, frame_size)
    )

    for f_idx, frame in enumerate(frames):
        f.write("  {")
        f.write(", ".join(frame))
        f.write("}}, // frame {}\n".format(f_idx + 1))

    f.write("};\n")

print(f"Export complete: frames.c with {num_frames} frames.")

# ----------------------------
# Write oled.c
# ----------------------------
oled_c_content = f"""#include "frames.c"
#include "quantum.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {{
  return OLED_ROTATION_180; // flips the display 180 degrees if offhand
}}

#define NUM_FRAMES {num_frames}
#define FRAME_WIDTH {frame_size * 8 // 64}  // Approximation; adjust as needed
#define FRAME_HEIGHT {64}                   // Adjust if necessary
#define FRAME_SIZE (FRAME_WIDTH * FRAME_HEIGHT / 8) // bytes per frame
#define FRAME_DELAY 100  // ms per frame, ~10 fps

bool oled_task_user(void) {{
  static uint16_t frame_index = 0;
  static uint32_t last_update = 0;

  if (timer_elapsed32(last_update) > FRAME_DELAY) {{
    last_update = timer_read32();

    // Write current frame to OLED (cast to const char* to fix signedness)
    oled_write_raw_P((const char *)frames[frame_index], FRAME_SIZE);

    frame_index++;
    if (frame_index >= NUM_FRAMES)
      frame_index = 0;
  }}

  return false; // keep other OLED content disabled
}}

#endif
"""

with open("oled.c", "w") as f:
    f.write(oled_c_content)

print(f"Export complete: oled.c with NUM_FRAMES = {num_frames}")
