TASEC-LAB
=========

TASEC-LAB is an experiment ballon project developed by the "Ignacio Da Riva" Institute (IDR) in collaboration with the STRAST research group from the Technical University of Madrid (UPM).

The main purpose of this experiment is to deepen the study of the thermal environment in the ascent and floating phases that will be useful in the design and thermal analysis of future missions.

Dependency list
---------------

This repository depends on these parts:

* [pigpio] (https://github.com/joan2937/pigpio): A C/C++ library for the Raspberry which allows control of the General Purpose Input Outputs (GPIO).
* [gpsd] (https://gpsd.gitlab.io/gpsd/): A service daemon that monitors one or more GPSes or AIS receivers attached to a host computer through serial or USB ports. It includes a linkable C service library, a C++ wrapper class, and a Python module that can be used to encapsulate all communication with gpsd.
* [gtest] (https://github.com/google/googletest): A unit testing library for the C++ programming language.

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
