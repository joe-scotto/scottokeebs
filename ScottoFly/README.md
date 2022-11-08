# ScottoFly

A 36 key column staggered ergonomic keyboard.

![ScottoFly](https://user-images.githubusercontent.com/8194147/194949089-a323674f-a2eb-4fab-a057-6fe8e1e2bb1e.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/194949107-1d2297ff-7f8b-45ae-bd8b-bcda7d5c5bae.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/194949127-ff86b4ef-fc1b-4783-b92c-471934d80e54.jpg)

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
-   36x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   18x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   36x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   36x - MX Switches
-   36x - 1u Keycaps

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](QMK/info.json).

-   **Rows** - 15, 14, 16, 10
-   **Columns** - 3, 4, 5, 6, 7, 8, 9, A3, A2, A1

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate](Case/ScottoFly%20-%20Plate.stl)
-   [Case](Case/ScottoFly%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottofly -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoFly">ScottoFly</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
