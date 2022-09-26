# ScottoSlant

A 37key ~0.25u row staggered handwired keyboard. Supports durock stabilizers for the 2u spacebar.

![ScottoSlant](https://user-images.githubusercontent.com/8194147/192114474-df9b38e6-ece1-4d7f-81fb-bbc910054847.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/192114467-da16590f-a361-483f-a435-2464a90b6f4c.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/192114473-21f31f5d-a12d-4ab3-916b-16cb84bf528c.jpg)

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
-   1x - [1u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   37x - [IN4148 Diode](https://amzn.to/3DMbQZ5)
-   14x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   28x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   37x - MX Switches

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](QMK/info.json).

-   **Rows** - 15, 14, 16, 10
-   **Columns** - 2, 3, 4, 5, 6, 7, 8, 9, A3, A2

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate](https://github.com/joe-scotto/keyboards/blob/c9ed6cedefafacc5a5acf20d7e6d08d2b24f23df/ScottoSlant/Case/ScottoSlant%20-%20Plate.stl)
-   [Case](https://github.com/joe-scotto/keyboards/blob/c9ed6cedefafacc5a5acf20d7e6d08d2b24f23df/ScottoSlant/Case/ScottoSlant%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottoslant -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoSlant">ScottoSlant</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
