# AudioMoth-Project

A minimal project on which all AudioMoth firmware can be built.

This is a fork of the [original project](https://github.com/OpenAcousticDevices/AudioMoth-Project).This fork is set up so that it's easier to build, without having to install the Simplicity Studio IDE.

### Usage

When run, this implementation will flash both LEDs and handle USB interactions to enable communication with the [AudioMoth Time App](https://github.com/OpenAcousticDevices/AudioMoth-Time-App).

### Requirements

 - cmake - use Brew on OSX, or your favourite package manager for Linux.
 - git - use Brew on OSX, or your favourite package manager for Linux.
 - make - should be available by default, otherwise as above.
 - arm-none-eabi-gcc - The GNU ARM Embedded Toolchain (https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

### Building

1. `git clone --recurse-submodules https://github.com/david-perez/AudioMoth-Project.git` to download this repository.
2. `mkdir build-release` to create the build directory.
3. `cd build-release` to switch to the build directory.
4. `cmake -DCMAKE_BUILD_TYPE=Release ..` to configure the build.
5. `make` to execute the build.

You should get a `AudioMoth-Project.bin` with your custom firmware, which you can then [flash to the device](https://www.openacousticdevices.info/flashing).

### Credits

Ryan Kurte for his [efm32-base project](https://github.com/ryankurte/efm32-base).

### License

Copyright 2017 [Open Acoustic Devices](http://www.openacousticdevices.info/).

[MIT license](http://www.openacousticdevices.info/license).
