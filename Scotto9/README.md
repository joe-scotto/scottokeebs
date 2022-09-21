# Scotto9

A 9 key handwired macropad.

![Scotto9](https://user-images.githubusercontent.com/8194147/191596031-e187b357-2cb6-4f6a-8439-f3e5725ca7d8.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/191596050-4bdc051a-c138-4c33-9bff-6298cafb7f94.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/191596098-71d00a8b-bf65-418b-b008-3c8d8a9c585f.jpg)

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
-   9x - [IN4148 Diode](https://amzn.to/3DMbQZ5)
-   4x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   4x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   9x - MX Switches

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](https://github.com/joe-scotto/keyboards/blob/77f19926de73788dc113664cdb20901e4c4fffaf/Scotto40/QMK/info.json).

-   **Rows** - 15, 14, 16, 10
-   **Columns** - 2, 3, 4, 5

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate (37 Key)](<https://github.com/joe-scotto/keyboards/blob/77f19926de73788dc113664cdb20901e4c4fffaf/Scotto40/Case/Scotto40%20-%20Plate%20(37).stl>)
-   [Plate (38 Key)](<https://github.com/joe-scotto/keyboards/blob/77f19926de73788dc113664cdb20901e4c4fffaf/Scotto40/Case/Scotto40%20-%20Plate%20(38).stl>)
-   [Plate (40 Key)](<https://github.com/joe-scotto/keyboards/blob/77f19926de73788dc113664cdb20901e4c4fffaf/Scotto40/Case/Scotto40%20-%20Plate%20(40).stl>)
-   [Case](https://github.com/joe-scotto/keyboards/blob/77f19926de73788dc113664cdb20901e4c4fffaf/Scotto40/Case/Scotto40%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scotto9 -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/Scotto9">Scotto9</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
