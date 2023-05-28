# ScottoMouse

A 6 key mouse using [QMK mouse keys](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md).
![ScottoMouse](https://github.com/joe-scotto/scottokeebs/assets/8194147/87ee3222-bd11-44f8-80d0-6359eb8650a3)
![Wiring](https://github.com/joe-scotto/scottokeebs/assets/8194147/a8356794-118a-4e7a-a6a4-b04ca4b4fc16)

# Parts

-   1x - [Raspberry Pi Pico (RP2040)](https://amzn.to/3WIrdJ5)
-   6x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   6x - [M2x8mm Screw](https://amzn.to/3jjelKi)
-   6x - MX Switches
-   6x - Keycaps
    -   14x - 1u
    -   3x - 2u

# Pins

This board is direct wired meaning each key goes directly to a pin and then they all share ground, for more info see [info.json](QMK/info.json).

# Case

The controller is mounted with pin-socket headers on the top of the case. There are two options, a 0 degree and a 5 degree case. The files can be found [here](case).

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/scottokeebs/scottomouse -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/scottokeebs/tree/main/ScottoMouse">ScottoMouse</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
