# ScottoErgo

A 36 key column staggered ortholinear ergonomic keyboard with exposed controller, aviator connector for USB, 10° of tilt, and 20° of angle.

![ScottoErgo](https://user-images.githubusercontent.com/8194147/232518351-b5ac219d-7e16-4211-bd1e-607e7e461a7e.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/232518358-b969c22b-45b7-4116-aa94-af1d87c005e2.jpg)
![Switches](https://user-images.githubusercontent.com/8194147/232518365-c7aed67d-2d2a-45d4-a906-33132c036207.jpg)

# Parts

-   1x - [Raspberry Pi Pico](https://amzn.to/3UqGaij)
-   36x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   9x - [M2x4mm Screw](https://amzn.to/41ghDPs)
-   9x - [M2x3mm Heat Set Inserts](https://amzn.to/3Km2RPS)
-   1x - [0.06" Plexiglass](https://amzn.to/3UEyZ6h)
-   36x - MX Switches
-   36x - 1u Keycaps

# Pins

Top left to right. Pins refer to the number on the RP2040, for more info see [info.json](QMK/info.json).

-   **Rows** - GP12, GP13, GP14, GP15
-   **Columns** - "GP0, GP1, GP2, GP3, GP4, GP22, GP21, GP20, GP19, GP18

# Case

The controller is socketed on top and then covered using the [Template](Case/ScottoErgo%20-%20Plate.stl) to cut a piece of plexiglass.

-   [Plate](Case/ScottoErgo%20-%20Plate.stl)
-   [Case](Case/ScottoErgo%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/ScottoErgo -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoErgo">ScottoErgo</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
