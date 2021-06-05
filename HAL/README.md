TASEC-LAB HAL
=============

This directory contains the Hardware Abstraction Layer and utils of the TASEC LAB onboard software. This layer is independent of the actual implementation, with the TASTE toolset.

Dependency list
---------------

This repository depends on these parts:

* [pigpio](https://github.com/joan2937/pigpio): A C/C++ library for the Raspberry which allows control of the General Purpose Input Outputs (GPIO).
* [gpsd](https://gpsd.gitlab.io/gpsd/): A service daemon that monitors one or more GPSes or AIS receivers attached to a host computer through serial or USB ports. It includes a linkable C service library, a C++ wrapper class (libgps-dev package), and a Python module that can be used to encapsulate all communication with gpsd.
* [gtest](https://github.com/google/googletest): A unit testing library for the C++ programming language.

Setting the environment
-----------------------
TODO

Installation
------------
TODO


For the compilation of all modules (main and others) run:
```bash
  make # or 
  make all
```

For the compilation of non-primary modules run:
```bash
make lib
```

Running the tests
-----------------
TODO

For the compilation and execution of the tests run:
```bash
make test
```

Also
----
For the execution of an specific target for the above options add TARGET=target.
E.g.:
  1) If you want to clean all modules run:
  ```bash
    make all TARGET=clean # or
    make TARGET= clean
  ```
  2) If you want to clean non-primary modules run:
  ```bash
    make lib TARGET=clean
  ```
