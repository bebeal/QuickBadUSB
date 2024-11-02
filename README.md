# Quick BadUSB Guide

No BS guide for creating BadUSB devices using:
- Raspberry Pi Pico (RP2040)
- Arduino Micro (ATmega32U4)

## Raspberry Pi Pico Guide

[Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/)

<p align="center">
<kbd><img src="https://github.com/user-attachments/assets/d8676971-b04b-4186-8236-ceb9d1dc2ff9" width="400"></kbd>
</p>

### Setup Instructions

1. Connect the Pico to your computer - it will mount as a USB drive labeled `RPI-RP2`

2. Install CircuitPython:
   - Download [CircuitPython firmware](https://circuitpython.org/board/raspberry_pi_pico/)
   - Copy the `.uf2` file to the root of `RPI-RP2`
   - The device will automatically reboot and remount as `CIRCUITPY`

3. Install required libraries:
   - Copy all files from `pico/*` in this repository to `CIRCUITPY`
   - This includes HID libraries and a DuckyScript interpreter (enables running standard DuckyScript payloads on the Pico)<br/>
   <sub>source: [dbisu/pico-ducky](https://github.com/dbisu/pico-ducky)</sub>

4. Add payload:
   - Create a file named `payload.dd` containing your DuckyScript and copy it to the root of `CIRCUITPY`
   - **Warning**: If not in setup mode the payload will run immediately
   - Sample non-malicious payloads are available in `payloads/ducky/` compatible with Windows, MacOS, and Linux

### Operating Modes

**Setup Mode**
- Prevents automatic payload execution
- Bridge Pin 1 (`GP0`) to Pin 3 (`GND`)

**Stealth Mode**
- Prevents the Pico from appearing as a USB storage device
- Bridge Pin 20 (`GP15`) to Pin 18 (`GND`)

### Multiple Payload Support

The Pico can store multiple payloads. The payload executed depends on which GPIO pins are grounded.
- Pin 6 `GP4` (default) -> `payload.dd`
- Pin 7 `GP5` -> `payload2.dd`
- Pin 14 `GP10` -> `payload3.dd`
- Pin 15 `GP11` -> `payload4.dd`

## Arduino Micro Guide

[Arduino Pro Micro](https://store.arduino.cc/products/arduino-micro)

### Setup Instructions

1. Install development environment:
   - Download and install [Arduino IDE](https://www.arduino.cc/en/software)
   - Connect the Micro and select it as the target board in IDE

2. Install HID library using either method:
   - **Option A**: Download [HID-Project](https://www.arduinolibraries.info/libraries/hid-project) and add via `Sketch -> Include Library -> Add .ZIP Library`
   - **Option B**: Use Arduino IDE's Library Manager, search for "HID-Project" and install

3. Deploy payloads:
   - Convert DuckyScript to Arduino code using [Duckuino](https://d4n5h.github.io/Duckuino/)
   - Copy the generated code to a new sketch in the IDE
   - Select `Sketch -> Upload` to flash the device
   - Sample non-malicious payloads are available in `payloads/arduino/` compatible with Windows, MacOS, and Linux

## TODO

* Add video/gif demos
* Add more payloads
* Add PicoW
* Add Pico2

<p align="center">
<kbd><img src="https://github.com/user-attachments/assets/9820879a-ce2f-4573-b6ec-7dcce871df26" width="400"></kbd>
</p>
