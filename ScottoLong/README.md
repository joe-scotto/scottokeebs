# ScottoLong

A 33 ortholinear board with a 7u spacebar.

![ScottoLong](https://user-images.githubusercontent.com/8194147/200442213-ce094beb-b315-4e57-ab6c-12bc357095db.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/200442207-bccc39b4-b25a-45db-a4c7-39b5b932fa9c.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/200442211-ed97ef68-0e66-49dd-abb4-cdec28e670ac.jpg)

# Parts

-   1x - [Raspberry Pi Pico (RP2040)](https://amzn.to/3WIrdJ5)
-   1x - [7u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   33x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   10x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   20x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
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

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/scottokeebs/tree/main/ScottoLong">ScottoLong</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
