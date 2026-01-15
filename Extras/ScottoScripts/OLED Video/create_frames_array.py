import re

# Read your exported hex file
with open("frames.txt", "r") as f:
    data = f.read()

frames = []
current_frame = []
fps = None  # will store the FPS extracted from the first frame comment

for line in data.splitlines():
    line = line.strip()

    # Skip empty lines
    if not line:
        continue

    # If line is a frame comment, start a new frame
    match = re.match(r"// '(\d+)fps_", line)
    if match:
        # Extract FPS from the first frame comment
        if fps is None:
            fps = int(match.group(1))

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

# Calculate FRAME_DELAY in ms
if fps:
    frame_delay = int(round(1000 / fps))  # milliseconds per frame
else:
    frame_delay = 67  # default to ~15 fps if no fps found

# ----------------------------
# Write frames.c
# ----------------------------
with open("frames.c", "w") as f:
    f.write(f"const uint8_t PROGMEM frames[{num_frames}][{frame_size}] = {{\n")
    for f_idx, frame in enumerate(frames):
        f.write("  {")
        f.write(", ".join(frame))
        f.write(f"}}, // frame {f_idx + 1}\n")
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
#define FRAME_DELAY {frame_delay}  // ms per frame, ~{fps} fps

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

print(
    f"Export complete: oled.c with NUM_FRAMES = {num_frames} and FRAME_DELAY = {frame_delay}ms (~{fps} fps)"
)
