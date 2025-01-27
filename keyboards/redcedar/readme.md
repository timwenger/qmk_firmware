# Red Cedar split Keyboard QMK Firmware

Follow [this link](https://github.com/timwenger/RedCedarDocs/tree/main/readme.md) for the associated build guide for this keyboard.

The idea to integrate game controller components comes from the [Dactyl TypeSafe](https://github.com/tewtham/dactyl-typesafe). The PS2 buttons are used for Control and Alt on each side, while the Nintendo Switch joysticks run the mouse and vertical + horizontal scroll. Have a look at the build guide below for how I integrated these components 👍. 


<img src="https://raw.githubusercontent.com/timwenger/RedCedarDocs/refs/heads/main/pics/RedCedarTopView.jpg" alt="Red Cedar keyboard, top view" width="700">

<img src="https://raw.githubusercontent.com/timwenger/RedCedarDocs/refs/heads/main/pics/RedCedarStackedView.jpg" alt="Red Cedar keyboard, stacked view" width="700">

## Keyboard Maintainer
[Tim Wenger](https://github.com/timwenger)

## Hardware
For full details, see [the associated build guide repo](https://github.com/timwenger/RedCedarDocs/tree/main/readme.md).

In summary though, this is a 3D printed, handwired case with a RP2040 pro micro footprint. Specifically, it uses this pinout:

<img src="https://raw.githubusercontent.com/timwenger/RedCedarDocs/refs/heads/main/pics/PinOut.png" alt="RP2040 pro micro pinout diagram" width="700">


## Compiling and flashing onto the keyboard processor
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

---

First run this command from within this repository
```
qmk compile -kb redcedar -km default
```

Then simply drag and drop the following file onto the processor once it's in bootloader mode and appears as a mass storage device
```
path\to\repo\qmk_firmware\redcedar_default.uf2
```

## How to get into bootloader mode

While debugging and you have access to the processors (2 ways):
1. while plugged into your computer via USB, hold down the boot button, then press the reset button 
2. hold down the boot button while plugging it into your computer via USB

Once it's all assembled and the QMK firmware is already running on the processors:
1. use the combos to enter boot loader mode. Check the `keyboards/redcedar/keymaps/default/combos.def` file for which keys to press simultaneously to activate bootloader mode.

## Debugging

First, you need to enable debugging in your QMK firmware build - [turn on debugging, configure what you want to show](https://github.com/qmk/qmk_firmware/blob/master/docs/faq_debug.md)

Then, using Windows, you can use this terminal program to view the debugging messages

https://www.pjrc.com/teensy/hid_listen.html