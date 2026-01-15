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

# Write formatted array to frames.c and overwrite on subsequent runs
with open("frames.c", "w") as f:
    f.write(
        "const uint8_t PROGMEM frames[{}][{}] = {{\n".format(
            len(frames), len(frames[0])
        )
    )

    for f_idx, frame in enumerate(frames):
        f.write("  {")
        f.write(", ".join(frame))
        f.write("}}, // frame {}\n".format(f_idx + 1))

    f.write("};\n")

print("Export complete: frames.c with {} frames.".format(len(frames)))
