# ScottoLong

A 33 ortholinear board with a 7u spacebar.

![ScottoLong](https://user-images.githubusercontent.com/8194147/193963094-ce0f174d-f67c-4a15-81d4-05b264ef2b11.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/193963081-003cc2b7-6bb5-4e59-991f-2d410162ba4f.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/193963087-8a99eeaa-161a-41f8-baee-2285fc7f5ec0.jpg)

# Parts

-   1x - [Raspberry Pi Pico (RP2040)](https://amzn.to/3WIrdJ5)
-   1x - [7u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   33x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   21x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   42x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   33x - MX Switches
-   33x - Keycaps
    -   30x - 1u
    -   2x - 1.5u
    -   1x - 7u

# Pins

Top left to right. Pins refer to the number on the RP2040, for more info see [info.json](QMK/info.json).

-   **Rows** - 4, 5, 6, 7
-   **Columns** - 9, 10, 11, 12, 14, 15, 16, 17, 19, 20

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate](Case/ScottoLong%20-%20Plate.stl)
-   [Case](Case/ScottoLong%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottolong -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoLong">ScottoLong</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
