# ScottoModules

Two modules based on the STM32F072CBT6 to make integrated MCU PCBs simpler. They're designed to sit between 2 switches on an ortholinear or row-staggered keyboard, column-staggered will require some manual moving to get them to fit correctly.

![ScottoModules](https://github.com/joe-scotto/scottokeebs/assets/8194147/c64f8413-679c-4154-bca2-81b5d45da52f)
![Scotto9 Example](https://github.com/joe-scotto/scottokeebs/assets/8194147/ff219794-3ad3-4f89-b94d-071c3be15afd)

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
| 2        | 1uF Capacitor (0402)        | [C52923](https://jlcpcb.com/partdetail/53938-CL05A105KA5NQNC/C52923)               |
| 1        | 10uF Capacitor (0603)       | [C19702](https://jlcpcb.com/partdetail/20411-CL10A106KP8NNNC/C19702)               |
| 6        | 100nF Capacitor (0402)      | [C307331](https://jlcpcb.com/partdetail/291005-CL05B104KB54PNC/C307331)            |

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
