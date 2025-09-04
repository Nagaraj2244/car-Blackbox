=> Overview

This project implements a Car Black Box system similar to an aircraft black box.
The system continuously records important vehicle parameters and events such as acceleration, braking, speed, and collisions.
In case of an accident, the stored data can be retrieved for analysis and investigation.

The implementation is done on the PIC18F4580 microcontroller, utilizing UART and I2C protocols for communication and data logging.

---

=> Features

Records vehicle status (ignition ON/OFF, speed, braking events)
Stores event logs in EEPROM (via UART protocol)
I2C interface for real-time monitoring and data retrieval
Simulated accident detection event
Event codes for different vehicle activities

---

=> Technologies Used

Microcontroller: PIC18F4580

Programming Language: Embedded C

Protocols: UART, I2C

Hardware Components:

EEPROM (for data storage)

Serial interface (for monitoring)

---

=> Project Structure

Car-Black-Box/
│── main.c          # Main application logic
│── uart.c          # UART communication functions
│── uart.h          # UART header file
│── i2c.c           # I2C communication functions
│── i2c.h           # I2C header file
│── eeprom.c        # EEPROM read/write functions
│── eeprom.h        # EEPROM header file

---

=> How to Run

1. Open the project in MPLAB X IDE or your preferred PIC development environment.
2. Compile the code and flash it to the PIC18F4580 microcontroller.
3. Connect the microcontroller to a PC via UART to monitor logs.
4. Simulate vehicle events (ignition ON, braking, collision) using switches/sensors.
5. Retrieve event data stored in EEPROM.

---

=> Learning Outcomes

Implementation of UART and I2C protocols in Embedded C
EEPROM interfacing for persistent data storage
Real-time logging of events in embedded systems
Practical embedded systems application for automotive safety 
