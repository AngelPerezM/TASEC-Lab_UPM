# TASEC-LAB

TASEC-LAB is an experiment balloon project developed by the "Ignacio Da Riva" Institute ([IDR](http://www.idr.upm.es/index.php/es/)) in collaboration with the [STRAST](https://www.dit.upm.es/~str/) research group from the Technical University of Madrid ([UPM](https://www.upm.es/)).

The main purpose of this experiment is to deepen the study of the thermal environment in the ascent and floating phases that will be useful in the design and thermal analysis of future missions.

The TASEC-Lab experiment was successfully launch on 16th July 2021 at 07:30 AM from the León airport.

![Launch time-lapse](./Doc/Videos/Fernando_gopro_launch.MP4)

## Table of contents
1. [Technology and dependency list](##technology-and-dependency-list)
2. [](##)

## Technology and dependency list

Almost all software components of the system were written in the C and C++ programming languages. The tools and libraries used in this repository are listed below:

* [TASTE](https://taste.tools/): An open-source tool-chain developed and maintained by ESA (European Space Agency) for embedded software development.
* [pigpio](https://github.com/joan2937/pigpio): A C/C++ library for the Raspberry which allows control of the General Purpose Input Outputs (GPIO).
* [gpsd](https://gpsd.gitlab.io/gpsd/): A service daemon that monitors one or more GPSes or AIS receivers attached to a host computer through serial or USB ports. It includes a linkable C service library, a C++ wrapper class (libgps-dev package), and a Python module that can be used to encapsulate all communication with gpsd.
* [gtest](https://github.com/google/googletest): A unit testing library for the C++ programming language.
* [OpenGEODE](https://github.com/esa/opengeode): Open-source SDL editor that generates Ada code.

## Description of the experiments
In order to fulfill the objective of the project, TASEC-Lab is composed of three laboratories that contain a set of sensors and actuators.

  1. **Attitude Determination Laboratory**. Its main objective is to characterize the flight dynamics of the balloon-gondola system (inclination and orientation) during the whole mission. To do so, an Inertial Measurement Unit (IMU) and a Global Positioning System (GPS) are carried onboard.

  2. **Environmental Laboratory**. This laboratory is in charge of the characterization of the thermal environment, i.e., parameters such as wind velocity, and pressure. That is why this lab. contains two pressure sensors, one anemometer, one silicon heater and one thermistor to control the anemometer temperature.

  3. **Heat Transfer Laboratory**. This is the main experiment of TASEC-Lab and its purpose is to study the heat transfer by convection. To do so, this experiment is equipped with five digital thermometers, six thermistors and one silicon heater.

A context diagram of the system that presents the OBC-laboratories relationship, as well as the equipment used in each laboratory, is depicted in Figure 1.

![HAL_UML_Package](./Doc/Images/context_diagram_tasec-lab.png)
_Figure 1: Context diagram of TASEC-Lab_

## Functional requirements
In general, the On-board software (OBSW) of the TASEC-Lab system has to implement the following functions:

 * Payload instruments operations, i.e., control of the sensors and actuators.
 * Thermal control for the anemometer (a thermostat).
 * Implementation of the three experiments (Heat Transfer Lab, Attitude Determination Lab, and Environmental Lab).
 * On-board storage of the data acquired by the devices of the experiments.

**TBC**