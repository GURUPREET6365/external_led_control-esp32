# ESP32 LED Blink — My First ESP-IDF Project

This is my **first ESP32 project**, created while learning the fundamentals of ESP32 development with **ESP-IDF**.

I built this project mainly to understand how the ESP32 works at a basic level, how GPIOs are controlled, how ESP-IDF projects are structured, and how a program is built and flashed onto the board.

Rather than following a complete tutorial, I built this project by learning from the **ESP-IDF documentation and AI-assisted explanations**.

## What I Learned

Through this project, I learned:

* How an ESP-IDF project is structured
* How to create an ESP-IDF project
* How GPIOs work on the ESP32
* How to configure a GPIO as an output
* How to set a GPIO **HIGH** or **LOW**
* How to write an ESP-IDF application using **C++**
* How C++ code can use ESP-IDF's C APIs
* How CMake tells ESP-IDF which source files to compile
* How to build an ESP-IDF project
* How firmware is generated as `.bin` files
* How to flash firmware onto an ESP32 through a serial port

## Project

The project controls an LED connected to **GPIO 18**.

The basic idea is:

```text
C++ Program
     ↓
ESP-IDF GPIO API
     ↓
GPIO 18
     ↓
HIGH / LOW
     ↓
LED ON / OFF
```

The program configures GPIO 18 as an output and changes its digital state between HIGH and LOW.

## Hardware

* ESP32 development board
* LED
* Resistor
* Jumper wires
* USB cable

> If your ESP32 development board has an onboard LED connected to GPIO 18, an external LED may not be necessary.

## Code

The main program is written in **C++**.

```cpp
#include "driver/gpio.h"

constexpr gpio_num_t LED_GPIO = GPIO_NUM_18;

extern "C" void app_main()
{
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
```

### How it works

`gpio_set_direction()` configures GPIO 18 as an output.

```cpp
gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
```

Then `gpio_set_level()` changes the digital state of the GPIO:

```cpp
gpio_set_level(LED_GPIO, 1);
```

sets the GPIO **HIGH**.

```cpp
gpio_set_level(LED_GPIO, 0);
```

sets the GPIO **LOW**.

The program waits for one second between each state change, producing the blinking effect.

## Project Setup

Create a new ESP-IDF project:

```bash
idf.py create-project
```

After creating the project, the source file can be changed from `.c` to `.cpp` if you want to write the application in C++.

For example:

```text
main/
├── CMakeLists.txt
└── main.cpp
```

Make sure the `main/CMakeLists.txt` references the correct source file.

For example:

```cmake
idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS ".")
```

This tells the build system which source file should be compiled.

## Building the Project

To build the project:

```bash
idf.py build
```

ESP-IDF compiles the source code and generates the firmware and other build artifacts inside the `build/` directory.

The generated `.bin` files are the firmware images that can be flashed to the ESP32.

## Flashing the ESP32

Connect the ESP32 to the computer through USB.

Then run:

```bash
idf.py flash
```

If you know the serial port used by the ESP32, you can specify it:

```bash
idf.py flash -p PORT
```

For example, on Windows:

```bash
idf.py flash -p COM3
```

ESP-IDF communicates with the ESP32 through the serial interface and places the generated firmware onto the board.

Many ESP32 development boards also support **automatic bootloader entry** through the USB-to-serial interface using the board's RTS/DTR control signals, so you normally don't have to manually hold the BOOT button.

## Monitor Serial Output

After flashing, you can monitor the ESP32's serial output using:

```bash
idf.py monitor
```

Or build, flash, and monitor in one command:

```bash
idf.py build flash monitor
```

## What I Want to Learn Next

This project is the starting point for understanding ESP32 development.

Next, I want to move beyond a simple LED and learn how to control and communicate with different hardware, including:

* GPIO input
* Buttons and switches
* PWM
* ADC
* UART
* I2C
* SPI
* Sensors
* Motors and servos
* Wi-Fi
* Bluetooth
* MQTT
* Interrupts
* FreeRTOS
* More complex embedded systems

## Goal

The goal of this repository is not just to make an LED blink.

It is my starting point for understanding **how microcontrollers actually work and how software interacts with hardware**.

I plan to use what I learn here to build progressively more complex ESP32 and embedded-system projects.
