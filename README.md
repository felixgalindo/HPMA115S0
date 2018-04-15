# HPMA115S0
Library for Honeywell's Particle Sensor (HPMA115S0-XXX)

This fork provides some debugging functionality (printing more information to the Serial Monitor). Additional minor changes were added.

## Instructions
* Place this repository in Documents\Arduino (or your default library location).
* Include this library: `#include <hpma115S0.h>`
* **OR** place `hpma115S0.h` and `hpma115S0.cpp` in same folder as your Arduino sketch and include using `#include "hpma115S0.h"`
* The debugging can be turned off by commenting out the line in src/hpma115s0.g
`// #define DEBUG`

An additional example with a hardware serial for the Arduino Mega will be provided.
