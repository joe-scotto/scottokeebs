#!/usr/bin/env python3
import argparse
import os
import shutil
import subprocess

# Arguments
parser = argparse.ArgumentParser(description="Extract frames from video for QMK OLED")

parser.add_argument("input", help="Path to input video file")
parser.add_argument(
    "--fps", type=float, default=15, help="Frames per second (default: 15)"
)
parser.add_argument(
    "--width", type=int, default=128, help="Output frame width (default: 128)"
)
parser.add_argument(
    "--height", type=int, default=64, help="Output frame height (default: 64)"
)
parser.add_argument(
    "--frames",
    type=int,
    default=120,
    help="Number of frames to extract (default: 120)",
)
parser.add_argument(
    "--format",
    default="gray",
    choices=["gray", "rgb24", "monow"],
    help="Output pixel format (default: gray)",
)
parser.add_argument(
    "--speed",
    type=float,
    default=1.0,
    help="Playback speed, maps to setpts (default: 1.0)",
)

args = parser.parse_args()

# Clear and recreate output directory
output_dir = "frames"
if os.path.exists(output_dir):
    shutil.rmtree(output_dir)
os.makedirs(output_dir)

# Create ffmpeg command
output_pattern = os.path.join(output_dir, "out_%03d.png")

# setpts expression: PTS = 1/speed * PTS
setpts_expr = f"setpts={1/args.speed}*PTS"

ffmpeg_cmd = [
    "ffmpeg",
    "-i",
    args.input,
    "-filter:v",
    f"{setpts_expr},fps={args.fps},scale={args.width}:{args.height},format={args.format}",
    "-frames:v",
    str(args.frames),
    output_pattern,
]

# Print command for debugging
print("Running command:\n", " ".join(ffmpeg_cmd))

# Run command
subprocess.run(ffmpeg_cmd, check=True)

print(f"Frames exported to ./{output_dir}")
