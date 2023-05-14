# ScottoInvader

A 36 key column staggered ortholinear keyboard.

![ScottoInvader](https://user-images.githubusercontent.com/8194147/196335152-13ac8c44-c60d-4d09-b559-eb24fc87e797.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/196335140-5004817b-bf95-4fb5-bca4-37bc3c9c9539.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/196335147-22c8b211-fd9b-49ef-a6c0-d7a9d7a960e0.jpg)

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
-   36x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   13x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   26x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   36x - MX Switches

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](QMK/info.json).

-   **Rows** - 15, 14, 16, 10
-   **Columns** - 3, 4, 5, 6, 7, 8, 9, A3, A2, A1

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate](Case/ScottoInvader%20-%20Plate.stl)
-   [Case](Case/ScottoInvader%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottoinvader -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/scottokeebs/tree/main/ScottoInvader">ScottoInvader</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
