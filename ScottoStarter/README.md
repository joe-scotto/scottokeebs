# ScottoStarter (WIP)

A 52 key ortholinear keyboard that is designed to help transition you into smaller layouts.

<!--
![ScottoStarter](https://user-images.githubusercontent.com/8194147/193435831-0216b09f-f500-457c-bb8a-a558330e786e.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/193435827-86c512b3-368f-4385-937a-316ecfe61c94.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/193435829-58c55a69-d7db-4ae8-ad00-207e046fd9d4.jpg) -->

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
-   1x - [3u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   41x - [IN4148 Diode](https://amzn.to/3DMbQZ5)
-   18x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   36x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   52x - MX Switches
-   52x - Keycaps
    -   44x - 1u
    -   7x - 1.5u
    -   1x - 3u

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](QMK/info.json).

-   **Rows** - 15, 14, 16, 10
-   **Columns** - 4, 5, 6, 7, 8, 9, A3, A2, A1, A0

# Case

The controller is simply hot glued into the bottom of the case. You may have to disable skirts and brims depending on the build volume of your printer.

-   [Plate](Case/ScottoStarter%20-%20Plate.stl)
-   [Case](Case/ScottoStarter%20-%20Case.stl)

# Stabilizer

The ScottoStarter uses a 3u spacebar, this isn't a unique size but you will have to source a 3u stabilizer wire or make one yourself. To make your own, simply take a piece of 14g wire and bend it at each stabilizer mounting point, then use it as normal.

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottostarter -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoStarter">ScottoStarter</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
