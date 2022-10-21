# Keyboards

All of my custom keyboards, keymaps, and case files are stored here.

# Contents

-   [main](https://github.com/joe-scotto/keyboards) - Case files and firmware for keyboards designed by me.
    -   [Scotto9](https://github.com/joe-scotto/keyboards/tree/main/Scotto9) - A 9 key handwired macropad.
    -   [Scotto36](https://github.com/joe-scotto/keyboards/tree/main/Scotto36) - A 36 key handwired ortholinear ergo keyboard.
    -   [Scotto40](https://github.com/joe-scotto/keyboards/tree/main/Scotto40) - A 37, 38, or 40 key handwired ortholinear keyboard.
    -   [ScottoSlant](https://github.com/joe-scotto/keyboards/tree/main/ScottoSlant) - A 37key ~0.25u row staggered handwired keyboard.
    -   [ScottoCMD](https://github.com/joe-scotto/keyboards/tree/main/ScottoCMD) - A 40 key handwired ortholinear keyboard with non-ortho bottom row.
    -   [ScottoGame](https://github.com/joe-scotto/keyboards/tree/main/ScottoGame) - A 42 key handwired ortholinear keyboard with game and action buttons.  
    -   [ScottoAlp](https://github.com/joe-scotto/keyboards/tree/main/ScottoAlp) - A 35 key ortholinear keyboard that supports MX and Alp switches.
    -   [ScottoStarter](https://github.com/joe-scotto/keyboards/tree/main/ScottoAlp) - A 52 key ortholinear keyboard.
    -   [ScottoFly](https://github.com/joe-scotto/keyboards/tree/main/ScottoFly) - A 36 key column staggered ergonomic keyboard.
    -   [ScottoInvader](https://github.com/joe-scotto/keyboards/tree/main/ScottoInvader) - A 36 key column staggered ortholinear keyboard.
    
-   [other](https://github.com/joe-scotto/keyboards/tree/other) - Case files designed by me for keyboards not designed by me. Also includes keymaps.
    -   [Iris](https://github.com/joe-scotto/keyboards/tree/other/Iris) - Tenting middle layer and keymap.
    -   [CRKBD](https://github.com/joe-scotto/keyboards/tree/other/CRKBD) - Case files along with both [QMK](https://github.com/qmk/qmk_firmware) and [ZMK](https://github.com/zmkfirmware/zmk) keymaps.
    -   [Ortho48](https://github.com/joe-scotto/keyboards/tree/other/Ortho48) - Case and keymap.
    -   [UT47.2](https://github.com/joe-scotto/keyboards/tree/other/UT47.2) - Keymap.
    -   [Planck V6](https://github.com/joe-scotto/keyboards/tree/other/Planck%20V6) - Keymap.
    -   [BM43](https://github.com/joe-scotto/keyboards/tree/other/BM43) - Keymap
    -   [BM40](https://github.com/joe-scotto/keyboards/tree/other/BM40) - Keymap.
    
- [abandoned](https://github.com/joe-scotto/keyboards/tree/abandoned) - Boards that I gave up on for any reason.
    - [ScottoCross](https://github.com/joe-scotto/keyboards/tree/abandoned/ScottoCross) - A 4x12 ortholinear board with a 7u spacebar. I got as far as printing it and then deciding that it wouldn't be very usable for me.

# FAQ

-   Can I sell any of these keyboards?
    -   <ins>**No, absolutely not**</ins>. I release these for free so people can build them, not sell them. Refer to the license below or on each keyboard for specifics.
    
-   Do you sell any of these keyboards?
    - Yes. The project will always remain free but to support it and myself, I do offer cases, builds, and kits over at [scottokeebs.com](http://scottokeebs.com)
    
-   Why do you use so many standoffs and screws in your builds?
    -   Since my boards use 3D printed plates, this gives them much better stability. It also helps improve stabilizer performance for keys that require them.
    
-   How exactly do I build a handwired keyboard?
    -   I made a [video](https://www.youtube.com/watch?v=hjml-K-pV4E) explaining everything you need to know.
    
-   Why is `qmk compile` not working?
    -   This most likely means the board hasn't been merged into the [qmk_firmware](https://github.com/qmk/qmk_firmware) repo yet. If this is the case, you can simply copy the `QMK` folder into `qmk_firmware/keyboards/handwired/jscotto` and rename it to the respective keyboard.
    
- Can I have just the `.hex` firmware file?
    - Yes, in each keyboards `Firmware` directory there is a file called `default.hex` with my personal map for that board, typically in Colemak. There also might be variants of that keymap. You can use this with [QMK Toolbox](https://github.com/qmk/qmk_toolbox) if you don't want to compile the firmware yourself or run into issues.   

# License

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/joe-scotto/keyboards.git">Keyboards</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/joe-scotto">Joe Scotto</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0
