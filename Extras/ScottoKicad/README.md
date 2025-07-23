# ScottoKicad

A collection of footprints, symbols, and 3D models for building mechanical keyboards with Kicad.
To download just this directory, you can use [DownGit](https://downgit.evecalm.com/#/home?url=https://github.com/joe-scotto/scottokeebs/tree/main/Extras/ScottoKicad).

```diff
- I highly recommend using Kicad 8 as Kicad 9 breaks many things shown in my tutorial!
- Please read all installation instructions carefully!
```
# Installation

1. Add a `SCOTTOKEEBS_KICAD` path to match where the `ScottoKicad` folder is located.
   ![Preferences -> Configure Paths](https://github.com/joe-scotto/scottokeebs/assets/8194147/5163f9db-0dfa-4ae7-ba4a-295114c5c051)
   ![Configure Paths](https://github.com/joe-scotto/scottokeebs/assets/8194147/28e6b534-e96d-4a14-9fd1-886b87db1c7b)

2. Add the symbol library.
   ![Preferences -> Manage Symbol Libraries](https://github.com/joe-scotto/scottokeebs/assets/8194147/d76cbe33-e155-46d1-98df-d8cd789688e6)
   ![Symbol Libraries](https://github.com/joe-scotto/scottokeebs/assets/8194147/e165293a-2aba-4269-a040-300297fd4089)

3. Add the footprint libraries.
   ![Preferences -> Manage Footprint Libraries](https://github.com/joe-scotto/scottokeebs/assets/8194147/f4105958-389d-4a0a-96d6-8b4eb98136e7)
   ![Footprint Libraries](https://github.com/joe-scotto/scottokeebs/assets/8194147/68367a4b-eca6-4440-8bf4-b6bf8ef522fa)      

4. Ensure hotkeys match tutorial.
   ![Settings](https://github.com/user-attachments/assets/f1a60960-1f94-4a19-bebf-56c879f6c1ca)
   ![Import hotkeys](https://github.com/user-attachments/assets/28e20294-f04c-4c9c-839b-9fe0041b37df)
   ![CleanShot 2025-06-30 at 11 00 42@2x](https://github.com/user-attachments/assets/6a8d607f-21dd-4ee1-996e-339324213b35)
   
5. Match Scotto Configuration (Optional).
   ![Settings](https://github.com/user-attachments/assets/f1a60960-1f94-4a19-bebf-56c879f6c1ca)
   ![Reveal](https://github.com/user-attachments/assets/87338725-3b15-4937-a50c-82d00e35da3f)
   ![Preferences](https://github.com/user-attachments/assets/d9eadf5c-ece8-41c3-9d04-bc2e3a77d2b4)
   ![Theme](https://github.com/user-attachments/assets/e94a621d-5d37-4712-b99f-b7f880ecb142)

6. That's it, you should now have everything you need!

# Common grid sizes

-   18x17mm (Choc)
    -   1.00u - X: 18, Y:17
    -   0.50u - X: 9, Y: 8.5
    -   0.25u - X: 4.5, Y: 4.25
-   19.05x19.05 (MX/Alps)
    -   1.00u - X: 19.05, Y: 19.05
    -   0.50u - X: 9.525, Y: 9.525
    -   0.25u X: 4.7625, Y: 4.7625

# Common Shortcuts

-   **Add (A)** - Add a footprint or symbol.
-   **Set Origin Point (S)** - Set where everything else will move in relation to.
-   **Move with Reference (])** - Move a footprint with a reference point.
-   **Track Tool (X)** - Place traces
-   **Add Via (V)** - Place a via to run a trace between PCB layers.
-   **Flip (F)** - Switch footprint between back and front of the PCB.

# Resources

Please refer to each library in order to understand the license it uses, most are Creative Commons CC-BY-SA 4.0.

-   [Keyswitch Library](https://github.com/kiswitch/kiswitch/tree/main) - 3D models and footprints for switches, stabilizers, and sockets.
-   [Raspberry Pi Pico](https://github.com/ncarandini/KiCad-RP-Pico) - 3D model, footprint, and symbol.
-   [Arduino Pro Micro](https://github.com/g200kg/kicad-lib-arduino) - Footprint and symbol.
-   [Marbastlib](https://github.com/ebastler/marbastlib) - Symbols.
-   [Kleeb](https://github.com/crides/kleeb) - 3D models, symbols, and footprints.
-   [Keebio](https://github.com/keebio/Keebio-Parts.pretty) - 3D models, footprints, and symbols.
-   [Adafruit](https://github.com/adafruit/Adafruit_CAD_Parts/tree/main?tab=MIT-1-ov-file#readme) - 3D models

# Credits

Feel free to reach out to me on Discord if you want to help get a component into the library.

-   nice!nano - Base dimensions and placement by @Knotherface, can be found on GitHub as [Leopere](https://github.com/Leopere).
