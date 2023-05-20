# Scotto34

A 34 ortholinear board that uses choc switches and mounts the controller on top.

![Scotto34](https://user-images.githubusercontent.com/8194147/205760764-cce990f6-0c81-4971-ae52-ec44b2bc3c33.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/205760822-a2ac1d7a-acd1-4d8f-9ba0-10589e7b94e5.jpg)

# Parts

-   1x - [Raspberry Pi Pico (RP2040)](https://amzn.to/3WIrdJ5)
-   34x - [1N4148 Diode](https://amzn.to/3DMbQZ5)
-   2x - [6mm M2 Spacer](https://amzn.to/3r1xdxO)
-   4x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   1x - [Pin-Socket Headers](https://amzn.to/3F40AX9)
-   34x - Choc Switches
-   34x - Choc Keycaps
    -   30x - 1u
    -   2x - 1.5u
    -   1x - 7u

# Pins

Top left to right. Pins refer to the number on the RP2040, for more info see [info.json](QMK/info.json).

-   **Rows** - GP0, GP4, GP9, GP14
-   **Columns** - GP3, GP2, GP7, GP8, GP13, GP16, GP17, GP18, GP19, GP20

# Case

The controller is mounted by using pin-socket headers.

-   [Case](Case/Scotto34%20-%20Case.stl)
-   [Bottom/Template](Case/Scotto34%20-%Bottom.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/Scotto34 -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/scottokeebs/tree/main/Scotto34">Scotto34</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
