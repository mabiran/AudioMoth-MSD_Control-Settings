# AudioMoth-Project

A port of the original AudioMoth-Project firmware which supports USB MSD protocol interfaces.

This is a fork of the [original project](https://github.com/OpenAcousticDevices/AudioMoth-Project).This fork is set up so that it's easier to build, without having to install the Simplicity Studio IDE.

## Usage

When run, this implementation will flash both LEDs and handle USB interactions to enable communication with the [AudioMoth Time App](https://github.com/OpenAcousticDevices/AudioMoth-Time-App).

### Actions

The AudioMoth firmware has a different behaviour to the standard behaviour of the primary branch firmware.

It is designed to be permanently set the device in the USB position, and enclosed inside a sealed casing.

- Pull pin `SWDIO` high to force audio recording
- Pull pin `SWDIO` low, to stop audio recording
- To flash the AudioMoth
  - Pull pin `RST` low, to force the AudioMoth to reset
  - Pull pin `SWCLK` high, to stop the MCU clock
  - Pull pin `RST` high, to permit the MCU to resume

### Requirements

- cmake - use Brew on OSX, or your favourite package manager for Linux.
  - cmake must be version 3.15 or greater
  - `sudo apt-get install cmake` will typically install an old version of the product
  - `sudo apt-get purge cmake && sudo snap install cmake --classic` will replace an existing cmake instance with a more recent version
- git - use Brew on OSX, or your favourite package manager for Linux.
- make - should be available by default, otherwise as above.
- arm-none-eabi-gcc - [The GNU ARM Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

### Building

1. `git clone --recurse-submodules https://github.com/victorromeo/AudioMoth-MSD.git` to download this repository.
2. `mkdir build-release` to create the build directory.
3. `cd build-release` to switch to the build directory.
4. `cmake -DCMAKE_BUILD_TYPE=Release ..` to configure the build.  Use `snap run cmake -DCMAKE_BUILD_TYPE=Release ..` if using a snap installed version.
5. `make` to execute the build.

You should get a `AudioMoth-Project.bin` with your custom firmware, which you can then [flash to the device](https://www.openacousticdevices.info/flashing).

## Debug

Requirement for environment variable ARM_NONE_EABI pointing to current ARM toolchain installation, i.e. in .bashrc

## Credits

David Perez for [AudioMoth CMake port](https://github.com/david-perez/AudioMoth-Project)
Ryan Kurte for his [efm32-base project](https://github.com/ryankurte/efm32-base).

## License

Copyright 2017 [Open Acoustic Devices](http://www.openacousticdevices.info/).

[MIT license](http://www.openacousticdevices.info/license).
