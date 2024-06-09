# DHT11 Sensor with STM32L053R8

This project demonstrates how to interface a DHT11 temperature and humidity sensor with an STM32L053R8 microcontroller. The code reads temperature and humidity data from the DHT11 sensor and outputs it via serial communication.

## Table of Contents
- [Introduction](#introduction)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

The DHT11 sensor is a popular temperature and humidity sensor used in various projects. This project uses an STM32L053R8 microcontroller to read data from the DHT11 sensor and output the readings via serial communication.

## Hardware Setup

### Components

- STM32L053R8 microcontroller
- DHT11 sensor
- 3.3kΩ pull-up resistor
- Breadboard and jumper wires
- USB to UART converter (for serial communication)

### Circuit Diagram
![Circuit Diagram](dht11_stm32.png)

### Connections

- **DHT11 Vcc** to 3.3V or 5V (depending on your DHT11 specifications)
- **DHT11 GND** to GND
- **DHT11 Data** to a GPIO pin on STM32L053R8 with a 3.3kΩ pull-up resistor to Vcc

## Software Setup

### Prerequisites

- STM32CubeIDE or any compatible IDE for STM32 development
- ARM GCC toolchain (if not using STM32CubeIDE)
- USB to UART converter drivers

### Project Structure

- `main.c`: Main program file
- `dht11.c`: DHT11 sensor interface functions
- `dht11.h`: Header file for DHT11 sensor interface
- `rcc.c`: System clock configuration
- `rcc.h`: Header file for system clock configuration

### Compiling and Flashing

1. Open the project in STM32CubeIDE or your preferred IDE.
2. Compile the project.
3. Connect the STM32L053R8 board to your computer.
4. Flash the compiled binary to the STM32L053R8 board.

### Running the Program

1. Open a serial terminal (e.g., PuTTY, Tera Term) on your computer.
2. Connect to the appropriate COM port at 115200 baud rate.
3. Reset the STM32L053R8 board to start the program.
4. Observe the temperature and humidity readings on the serial terminal.

## Usage

This project continuously reads the temperature and humidity from the DHT11 sensor and outputs the values via serial communication. The output includes raw sensor data and calculated temperature and humidity values.

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes.

