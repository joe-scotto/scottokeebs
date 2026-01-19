# OLED Video

Used to convert a video for display on a QMK OLED.

This should work on pretty much any QMK keyboard but I highly recommend using a controller with a decent amount of flash memory such as an RP2040.

# Instructions

1. Generate your frames using [extract_frames.py](extract_frames.py)
   - They will output to the `frames` directory.
2. Upload those to [Image2CPP](https://javl.github.io/image2cpp/)
   1. Choose your dithering mode if you want to play with the look.
   2. Code output format should be set to `Plain bytes`.
   3. Output should be set to `Draw mode: Vertical - 1 bit per pixel`
   4. Click `Generate code` and paste the output to `frames.txt`.
3. Generate your `frames.c` using [create_frames_array.py](create_frames_array.py).
   1. Copy `frames.c` and `oled.c` to your QMK keymap.
   2. Import `oled.c` into your `keymap.c`.
   3. Compile and flash.
4. You should now see a video playing on your OLED!

# extract_frames.py

This is the script used to generate the video frames you will use to convert.

> python extract_frames.py "video.mp4"

| Argument   | Type    | Default    | Description                                      |
| ---------- | ------- | ---------- | ------------------------------------------------ |
| `input`    | `str`   | _required_ | Path to the input video file.                    |
| `--fps`    | `float` | `15`       | Playback frames per second.                      |
| `--width`  | `int`   | `128`      | Width of the output frames in pixels.            |
| `--height` | `int`   | `64`       | Height of the output frames in pixels.           |
| `--frames` | `int`   | `120`      | Number of frames to extract from the video.      |
| `--format` | `str`   | `monow`    | Output pixel format: `monow`, `gray`, or `rgb24` |
| `--speed`  | `float` | `1.0`      | Playback speed of the video.                     |
