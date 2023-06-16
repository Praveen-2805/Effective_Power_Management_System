# Effective Power Management System

The Effective Power Management System is a project that utilizes an ESP32 microcontroller, infrared (IR) sensors, and home automation capabilities to optimize energy consumption in a room. The system counts the number of people present in the room using IR sensors and automatically turns on or off home appliances based on occupancy. This helps to conserve energy by activating appliances only when the room is occupied.

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [License](#license)

## Introduction

The Effective Power Management System aims to improve energy efficiency in a room by monitoring occupancy and controlling the operation of home appliances accordingly. By using infrared sensors to detect the presence of individuals, the system accurately counts the number of people inside the room. Based on this occupancy information, it automatically turns on or off the home appliances, ensuring that power is consumed only when necessary.

## Features

- Accurate counting of people inside the room using IR sensors.
- Automatic control of home appliances based on occupancy.
- Energy conservation by turning off appliances when the room is unoccupied.
- User-defined thresholds for activating and deactivating appliances.
- Integration with the ESP32 microcontroller for processing sensor data and controlling appliances.

## Hardware Requirements

To build the Effective Power Management System, you will need the following components:

- ESP32 development board (e.g., ESP32 NodeMCU)
- Infrared (IR) sensors (e.g., PIR sensors)
- Home appliances (e.g., lights, fans, air conditioners)
- Relay modules (if required for controlling high-power appliances)
- Power supply
- Breadboard or perfboard
- Jumper wires

## Software Requirements

The following software tools are required for setting up the project:

- Arduino IDE (Integrated Development Environment)

## Installation

1. Connect the components according to the circuit diagram provided.
2. Install the Arduino IDE by following the official instructions for your operating system.
3. Clone or download the project code from the repository.
   - If using Git, run the following command:
     ```
     git clone <repository-url>
     ```
   - Alternatively, download the code as a ZIP file and extract it to a local directory.

## Usage

1. Open the Arduino IDE and navigate to the project folder.
2. Open the `Power_Management_System.ino` file.
3. Set up the Wi-Fi credentials and modify any other necessary settings in the code.
4. Verify and upload the sketch to the ESP32 board.
5. Connect the IR sensors to the appropriate pins on the ESP32 board.
6. Connect the relay modules (if required) to control the home appliances.
7. Power on the system and observe the behavior of the appliances based on occupancy.
8. The IR sensors will detect the presence of people and trigger the activation or deactivation of the appliances accordingly.

## Contributing

Contributions to this project are welcome! If you find any issues or have ideas for improvements, please submit an issue or a pull request in the project's repository.

## License

The Effective Power Management System is licensed under the [MIT License](https://opensource.org/licenses/MIT). Please refer to the `LICENSE` file for more information.
