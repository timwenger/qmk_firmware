# Red Cedar

![Red Cedar development board](https://lh3.googleusercontent.com/pw/AP1GczOAG3cQS67Ck2gmhTVoDx-3qEDvIVRzw1Dd1UnRoB40SLz5PGs-aCePbomDM7NFegApyWxA4ezvNfCd3nNHLp2Rgb5seCRWr3ySm0-03Nt9_jdl_cvqAMCpwwa4sprnZKFMW1HqdRgfk4W4QuGpKCN38A=w2237-h1677-s-no?authuser=0)


The Red Ceard keyboard general shape was inspired by the dactyl manuform. Including game controller buttons was an inspiration from the [Dactyl TypeSafe](https://github.com/tewtham/dactyl-typesafe)

* Keyboard Maintainer: [Tim Wenger](https://github.com/timwenger)
* Hardware Supported: 3D printed case, RP2040 pro micro footprint

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Compile Command
```
qmk compile -kb redcedar/v1 -km default
```

## Bootloader

Enter the bootloader in 3 ways:
* [Bootmagic reset](https://docs.qmk.fm/features/bootmagic): Hold down the key at (0,0) in the matrix, the top left key, and plug in the keyboard
- hold down the boot button, then press the reset button  
- press the reset button twice, quickly  
