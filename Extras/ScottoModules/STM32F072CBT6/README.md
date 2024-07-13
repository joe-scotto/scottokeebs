# ScottoModules

Two modules based on the STM32F072CBT6 to make integrated MCU PCBs simpler. They're designed to sit between 2 switches on an ortholinear or row-staggered keyboard, column-staggered will require some manual moving to get them to fit correctly.

![ScottoModules](https://github.com/user-attachments/assets/0bb5414e-1c85-4956-a7c2-a01110420ea8)
![Spacing Example](https://github.com/user-attachments/assets/a2a5501b-8f39-423c-aa4b-ebb2dca22174)

# Bill of Materials (BOM)

| Quantity | Part                        | LCSC                                                                               |
| -------- | --------------------------- | ---------------------------------------------------------------------------------- |
| 1        | STM32F072CBT6 (LQFP-48_7x7) | [C81720](https://jlcpcb.com/partdetail/Stmicroelectronics-STM32F072CBT6/C81720)    |
| 1        | XC6206 (SOT-23-3L)          | [C5446](https://jlcpcb.com/partdetail/TorexSemicon-XC6206P332MRG/C5446)            |
| 1        | USBLC6-2SC6 (SOT-23-6)      | [C2827654](https://jlcpcb.com/partdetail/TechPublic-USBLC62SC6/C2827654)           |
| 1        | TL3342                      | [C115351](https://jlcpcb.com/partdetail/Alpsalpine-SKQGABE010/C115351)             |
| 1        | USB_C_HRO_TYPE-C-31-M-12    | [C165948](https://jlcpcb.com/partdetail/Korean_HropartsElec-TYPE_C_31_M12/C165948) |
| 2        | 5.1k Resistor (0402)        | [C25905](https://jlcpcb.com/partdetail/26648-0402WGF5101TCE/C25905)                |
| 1        | 10k Resistor (0402)         | [C25744](https://jlcpcb.com/partdetail/26487-0402WGF1002TCE/C25744)                |
| 1        | 500mA Fuse (0603)           | [C210357](https://jlcpcb.com/partdetail/Bourns-MF_FSMF050X2/C210357)               |
| 3        | 1uF Capacitor (0402)        | [C52923](https://jlcpcb.com/partdetail/53938-CL05A105KA5NQNC/C52923)               |
| 1        | 10nF Capacitor (0402)       | [C15195](https://jlcpcb.com/partdetail/15869-CL05B103KB5NNNC/C15195)               |
| 2        | 4.7uF Capacitor (0402)      | [C23733](https://jlcpcb.com/partdetail/24469-CL05A475MP5NRNC/C23733)               |
| 5        | 100nF Capacitor (0402)      | [C307331](https://jlcpcb.com/partdetail/291005-CL05B104KB54PNC/C307331)            |

# Usage

1. The project is setup as a Kicad template, first open Kicad and select "New Project from Template..." from the file menu.
   ![New Project from Template...](https://github.com/joe-scotto/scottokeebs/assets/8194147/383bd477-ea00-497e-b474-fcde3cfbbf68)

2. Next click the folder icon and navigate to where you saved the `ScottoModules/STM32F072CBT6` folder and open it.
   ![Open folder](https://github.com/joe-scotto/scottokeebs/assets/8194147/5fca81d0-368b-4750-aca6-404c040dafac)
   ![Folder location](https://github.com/joe-scotto/scottokeebs/assets/8194147/e66a78c7-6ee5-496f-b147-3ba9a0db56f5)

3. Select `ScottoModules (STM32)` and click `OK`.
   ![Create template](https://github.com/joe-scotto/scottokeebs/assets/8194147/33a7cf74-bec3-4a9f-a3d7-1a1abb79739a)

4. Name your project and save it somewhere.
   ![Name and Save](https://github.com/joe-scotto/scottokeebs/assets/8194147/72c649a4-fe12-4581-af50-ddb49dd9555b)

5. You're now ready to start using ScottoModules!

# Kicad Template Folder

Alternatively, you can save `ScottoModules/STM32F072CBT6` to your Kicad templates folder and not have to manually load it each time.

-   **Mac** - /Users/YOUR_USERNAME/Documents/KiCad/8.0/template/
-   **Windows** - C:\Users\YOUR_USERNAME\Documents\KiCad\8.0\template\
