# Scotto36
A 36 key handwired ortholinear ergo keyboard. Featuring

![IMG_3553](https://user-images.githubusercontent.com/8194147/191559764-12b65543-1ca8-4dc2-a64d-7f86911f9ffd.jpg)
![IMG_3550](https://user-images.githubusercontent.com/8194147/191559971-9f1b0120-8619-4255-9f1e-28dc2444472d.jpg)
![IMG_3551](https://user-images.githubusercontent.com/8194147/191560489-4e630d53-32f9-4454-8af2-f948c1dc0cc4.jpg)

# Parts
- 1x - [Arduino Pro Micro (Atmega32U4)](https://amzn.to/3LwgAUq)
- 1x - [0.91" 128x32 OLED](https://amzn.to/3faLsxX)
- 36x - [IN4148 Diode](https://amzn.to/3DMbQZ5)
- 36x - MX Switches

# Pins
Top left to right.
- **Rows** - 15, 14, 16, 10
- **Columns** - 4, 5, 6, 7, 8, 9, A3, A2, A1, A0

# Case
The controller is simply hot glued into the bottom of the case.
- [**Plate**](Scotto36/Case/Plate.stl)
- [**Case**](Scotto36/Case/Case.stl)

# Flashing
1. [Install QMK locally](https://github.com/qmk/qmk_firmware)
2. Copy the contents of [QMK](Scotto36/QMK) to `keyboards/scotto36`.
3. Make changes to the keymap you see fit.
4. Run `qmk compile -kb scotto36 -km default -c` or whatever your keymap name was.
5. Flash the controller.

# License
