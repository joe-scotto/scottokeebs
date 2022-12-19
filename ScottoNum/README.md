# ScottoNum

A simple number pad compatible with QMK or ZMK firmware.

<!-- ![ScottoNum](https://user-images.githubusercontent.com/8194147/200442213-ce094beb-b315-4e57-ab6c-12bc357095db.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/200442207-bccc39b4-b25a-45db-a4c7-39b5b932fa9c.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/200442211-ed97ef68-0e66-49dd-abb4-cdec28e670ac.jpg) -->

# Parts

-   1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
    -   Can be substituted with ZMK firmware and a Nice Nano for wireless.
-   3x - [2u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   1x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   7x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   1x - [Pin-Socket Headers](https://amzn.to/3F40AX9)
-   17x - MX Switches
-   17x - Keycaps
    -   14x - 1u
    -   3x - 2u

# Pins

This board is direct wired meaning each key goes directly to a pin and then they all share ground, for more info see [info.json](QMK/info.json).

-   Pins -

# Case

The controller is mounted with pin-socket headers on the top of the case. There are two options, a 0 degree and a 5 degree case. The files can be found [here](case).

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottonum -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoNum">ScottoNum</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
