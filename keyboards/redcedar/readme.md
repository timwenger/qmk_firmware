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

### First install WSL
```powershell
wsl --install
```

### Then clone this repo
clone it to the ~ home directory for simplicity

```bash
git clone https://github.com/timwenger/qmk_firmware.git
```

### Then install qmk
```bash
sudo apt update
sudo apt install -y git python3-pip pipx
pipx install qmk
pipx ensurepath
```

### Then install support for building your kb from within this repository
```bash
sudo apt install -y build-essential gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi
git submodule update --init --recursive
```
### Then compile using this command
```bash
qmk compile -kb redcedar -km default

# or set defaults to make the command shorter
qmk config user.keyboard=redcedar user.keymap=default
qmk compile

```

Then simply drag and drop the following file onto the explorer window of the device once it's in bootloader mode and appears as a mass storage device
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


## Pulling Upstream QMK into your fork
```bash
git remote add upstream https://github.com/qmk/qmk_firmware.git

# Align submodules with this branch first
git submodule update --init --recursive

git fetch upstream
git merge upstream/master

# Align submodules with the merged version
git submodule update --init --recursive

qmk compile

git push
```