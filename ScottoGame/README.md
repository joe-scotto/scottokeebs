# ScottoGame

A 42 key handwired ortholinear keyboard. Featuring a split spacebar and a 128x64 OLED with Bongo Cat.

![ScottoGame](https://user-images.githubusercontent.com/8194147/193435831-0216b09f-f500-457c-bb8a-a558330e786e.jpg)
![Matrix](https://user-images.githubusercontent.com/8194147/193435827-86c512b3-368f-4385-937a-316ecfe61c94.jpg)
![Controller](https://user-images.githubusercontent.com/8194147/193435829-58c55a69-d7db-4ae8-ad00-207e046fd9d4.jpg)

    


# Parts

-   1x - [USB-C Arduino Pro Micro (Atmega32U4)](https://amzn.to/3UKt0MH)
-   3x - [2u Plate Mount Stabilizer](https://amzn.to/3xUEvHz)
-   1x - [0.91" 128x64 OLED](https://amzn.to/3dLG2ZU)
-   42x - [IN4148 Diode](https://amzn.to/3DMbQZ5)
-   21x - [8mm M2 Spacer](https://amzn.to/3r1xdxO)
-   42x - [M2x6mm Screw](https://amzn.to/3r1xdxO)
-   42x - MX Switches
-   42x - Keycaps
    -   39x - 1u
    -   2x - 2u
    -   1x - 2.75u

# Pins

Top left to right. Pins refer to the number on the Pro Micro, for more info see [info.json](QMK/info.json).

-   **Rows** - A0, 15, 14, 16, 10
-   **Columns** - RX1, 4, 5, 6, 7, 8, 9, A3, A2, A1

# OLED

Simply wire the OLED pins to the I2C pins on the Pro Micro.

-   SDA -> 2
-   SCK -> 3
-   VCC -> VCC
-   GND -> GND

# Case

The controller is simply hot glued into the bottom of the case.

-   [Plate](Case/ScottoGame%20-%20Plate.stl)
-   [Case](Case/ScottoGame%20-%20Case.stl)

# Flashing

1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Make changes to the keymap if required.
3. Run `qmk flash -kb handwired/jscotto/scottogame -km default -c`.

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards/tree/main/ScottoGame">ScottoGame</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
