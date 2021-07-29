# TASEC-LAB HAL

This directory contains the Hardware Abstraction Layer (HAL) and utilities of the TASEC LAB onboard software. This layer is independent of the actual implementation (i.e., does not depend on the TASTE tool-set).

## Dependency list

This repository depends on these parts:

* [pigpio](https://github.com/joan2937/pigpio): A C/C++ library for the Raspberry which allows control of the General Purpose Input Outputs (GPIO).
* [gpsd](https://gpsd.gitlab.io/gpsd/): A service daemon that monitors one or more GPSes or AIS receivers attached to a host computer through serial or USB ports. It includes a linkable C service library, a C++ wrapper class (libgps-dev package), and a Python module that can be used to encapsulate all communication with gpsd.
* [gtest](https://github.com/google/googletest): A unit testing library for the C++ programming language.

## Project structure
The following tree shows some directories and files from HAL:
```
.
├── BusHandlers        # Software component
│   ├── build          # Object and dependency files
│   ├── include        # Header files
│   ├── lib            # Static library generated from build
│   ├── source         # Source code
│   └── Makefile
├── EquipementHandlers # Software component
│   ├── build
│   ├── include
│   ├── lib
│   ├── source
│   └── Makefile
├── Utils              # Software component
│   ├── build
│   ├── include
│   ├── lib
│   ├── source
│   └── Makefile
├── Tests              # Tests for BusHandlers, EquipementHandlers, and Utils
├── include            # Contains links to the include dir. of the components
├── lib                # Contains links to the lib dir. of the components
└── ...
```

The HAL is composed of the following three components:

* **BusHandlers**: The purpose of this component is to provide a set of operations that facilitate and abstract the access to the IIC and SPI hardware buses of the OBC (On-Board Computer).
* **EquipmentHandlers**: This component contains the devices of the TASEC-Lab system and provides a set of services so that other components can request data from the sensors or command the actuators.
* **Utils**: The Util(itie)s component provides a series of functions used by the BusHabndlers and EquipmentHanlders components such as logging of data, debug prints, etc.

In addition to these three layers, the Operating System and device drivers conform a layer that sits at the bottom of the architecture and offers its services to all the HAL components. It interacts with the hardware connected to the OBC through its device drivers, which are accessible to user-space thanks to additional programming libraries such as *i2c-dev*, *spidev*, *pigpio*, etc.

The following UML package diagram depicts the (dependency) relationship between the packages of the HAL, i.e.: the three components mentioned above, the Tests directory, and the third party libraries.

<img src="../Doc/Images/HAL_UML_Package.png" width="800px">

_Figure 1: UML Package diagram of the HAL_

## Installation

In order to install the HAL you need to download the whole TASEC-Lab repository executing (*$* represents the prompt):
```bash
$ git clone --depth=1 https://gitlab.com/AngelPerezM/TASEC-Lab_UPM.git
```

Optionally, you can download only this directory in a compressed format. Note that if you are not installing the HAL in the RPi, the [root file system](../RPI_rootfs_v3) used by the cross compiler is located in the parent directory.

For the compilation of the HAL components run:
```bash
$ make -j $(nproc) # or make all -j $(nproc)
```
After that, the lib directory will be created and will contain soft links to the static libraries (\*.a) of each component.

## Running the tests

For the compilation and execution of the *unit* tests run:
```bash
$ make test -j $(nproc)
```
