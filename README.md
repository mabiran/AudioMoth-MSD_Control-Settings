# AudioMoth-Project

A port of the original AudioMoth-Project firmware which supports USB MSD protocol interfaces.

This is a fork of the git Audiomoth-MSD(https://github.com/victorromeo/AudioMoth-MSD.git), which is also a fork of the [original project](https://github.com/OpenAcousticDevices/AudioMoth-Project).This fork is set up so that it's easier to build, without having to install the Simplicity Studio IDE.

## Usage

When run, this implementation will flash both LEDs and handle USB interactions to enable communication with the [AudioMoth Time App](https://github.com/OpenAcousticDevices/AudioMoth-Time-App).

### Actions to edit the firmware

The current audiomoth flash app use a bootloader wich is in the Audiomoth, but because the firmware Audiomoth-MSD was created before this implementation it suppress it. So if after you installed this firmware can't use the current version of the audiomoth flash app for this issue you need to install an older version the `Audiomoth Flash app V1.2`. On this version you can install all the current version it is just that your bootloader will still not be in your Audiomoth.

- To flash the AudioMoth
  - Pull pin `RST` low, to force the AudioMoth to reset
  - Pull pin `SWCLK` high, to stop the MCU clock
  - Pull pin `RST` high, to permit the MCU to resume

### Actions to start recording

The AudioMoth firmware has a different behaviour to the standard behaviour of the primary branch firmware.

It is designed to be permanently set the device in the USB position, and enclosed inside a sealed casing.

- Pull pin `SWDIO` low to force audio recording
- Pull pin `SWDIO` high to stop audio recording

### Actions to change the setting

The original Audiomoth-MSD have a default setting inside is code, but contrary to the current firmware like the V1.11.0, the Audiomoth-MSD can't edit his configuration with the configuration app. But the configuration app need to be done manually or use a script, but we decided to use a fonctionnality on the Audtiomoth 1.2.0 which wasn't in the previuce version used with Audiomoth-MSD and this is the use of the GPIO pin, with these we can pre-configure the different settings in fonction of the GPIO value. In our case we just have defined two case.

- Pull pin `b10` low for the configuration A
- Pull pin `b10` high for the configuration B

### Additionnal information about the change of the settings
The code I added are in:
  - src > main.c
      - defaultConfigSettingsA and B : line 245 to 293
      - editSettings : line 375 to 384 and call line 765
      - AudioMoth_setPinValue : libe 395
  - src > audioMoth.c
      - AudioMoth_setPinValue : line 2093 to 2097
      - AudioMoth_getPinValue : line 2098 to 2101
  - inc > audioMoth.h
      - AudioMoth_setPinValue : line 167
      - AudioMoth_getPinValue : line 168
  - inc > pinouts_EFM32WG990.h
      - GPIO_GPIOPORT : line 127
      - GPIO_PIN_PB10 : line 128
  - inc > pinouts_EFM32WG380.h
      - GPIO_GPIOPORT : line 131
      - GPIO_PIN_PB10 : line 132

The code needed to be added:
  - efm32-base > emlib > src after GPIO_PinModeGet
        /***************************************************************************//**
        * @brief
        *   Get the pin value for a pin GPIO.
        *
        * @param[in] port
        *   The GPIO port to access.
        *
        * @param[in] pin
        *   The pin number in the port.
        *
        * @return
        *   True if pin value (1) or false if (0).
        ******************************************************************************/
        uint8_t GPIO_PinValueGet(GPIO_Port_TypeDef port, unsigned int pin) {
            return (GPIO->P[port].DIN & (1 << pin)) ? 1 : 0;
        }

  - efm32-base > emlib > inc after GPIO_PinModeSet
        /***************************************************************************//**
        * @brief
        *   Get the pin value for a pin GPIO.
        *
        * @param[in] port
        *   The GPIO port to access.
        *
        * @param[in] pin
        *   The pin number in the port.
        *
        * @return
        *   True if pin value (1) or false if (0).
        ******************************************************************************/
        uint8_t GPIO_PinValueGet(GPIO_Port_TypeDef port, unsigned int pin);
    


### Requirements

- cmake - use Brew on OSX, or your favourite package manager for Linux.
  - cmake must be version 3.15 or greater
  - `sudo apt-get install cmake` will typically install an old version of the product
  - `sudo apt-get purge cmake && sudo snap install cmake --classic` will replace an existing cmake instance with a more recent version
- git - use Brew on OSX, or your favourite package manager for Linux.
- make - should be available by default, otherwise as above.
- arm-none-eabi-gcc - [The GNU ARM Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

### Building

1. `git clone --recurse-submodules https://github.com/PreClomard/AudioMoth-MSD_Control-Settings.git` to download this repository.
2. `mkdir build-release` to create the build directory.
3. `cd build-release` to switch to the build directory.
4. `cmake -DCMAKE_BUILD_TYPE=Release ..` to configure the build.  Use `snap run cmake -DCMAKE_BUILD_TYPE=Release ..` if using a snap installed version.
5. `make` to execute the build.

You should get a `AudioMoth-Project.bin` with your custom firmware, which you can then [flash to the device](https://www.openacousticdevices.info/flashing).

## Debug

Requirement for environment variable ARM_NONE_EABI pointing to current ARM toolchain installation, i.e. in .bashrc

## Credits

Victortomeo for [Audiomoth-MSD] (https://github.com/victorromeo/AudioMoth-MSD.git)
David Perez for [AudioMoth CMake port](https://github.com/david-perez/AudioMoth-Project)
Ryan Kurte for his [efm32-base project](https://github.com/ryankurte/efm32-base).

## License

Copyright 2017 [Open Acoustic Devices](http://www.openacousticdevices.info/).

[MIT license](http://www.openacousticdevices.info/license).
