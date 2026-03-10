# STM32 UART Communication Protocol

Embedded communication system implemented on STM32 using UART interrupt and finite state machines.  
The system simulates a simple **request–response protocol** between a terminal and the microcontroller.

The project demonstrates how embedded devices exchange data using a structured communication protocol.

---

## System Overview

Communication is established between:

- STM32 microcontroller
- Virtual terminal (Proteus simulation)

UART configuration:

- Baudrate: 9600
- Data bits: 8
- Parity: None
- Stop bits: 1

UART communication is handled using **interrupt-based reception**.

---

## Communication Protocol

The following command protocol is implemented:

| Command | Description |
|-------|-------------|
| `!RST#` | Request sensor data from STM32 |
| `!ADC=xxxx#` | STM32 response containing ADC value |
| `!OK#` | Acknowledgment from terminal |

Communication flow:

1. Terminal sends `!RST#`
2. STM32 reads sensor value (ADC)
3. STM32 sends response packet `!ADC=value#`
4. Terminal replies with `!OK#`
5. If no ACK is received within **3 seconds**, STM32 retransmits the packet

This mechanism demonstrates a simple **flow control and reliability concept**.

---

## Hardware / Simulation Setup

The system is simulated using **Proteus**.

Main components:

- STM32 microcontroller
- Virtual terminal (UART console)
- Potentiometer used as analog sensor input
- ADC channel connected to PA0
- LED indicator on PA5

The ADC value changes depending on the potentiometer position.

---

## Key Embedded Concepts

This project demonstrates several core embedded software techniques:

- UART communication using interrupts
- Command parser implementation
- Finite State Machine (FSM) design
- Simple communication protocol
- ADC sensor reading
- Packet retransmission using timeout

---

## Software Architecture

Main modules used in the project:
# STM32 UART Communication Protocol

Embedded communication system implemented on STM32 using UART interrupt and finite state machines.  
The system simulates a simple **request–response protocol** between a terminal and the microcontroller.

The project demonstrates how embedded devices exchange data using a structured communication protocol.

---

## System Overview

Communication is established between:

- STM32 microcontroller
- Virtual terminal (Proteus simulation)

UART configuration:

- Baudrate: 9600
- Data bits: 8
- Parity: None
- Stop bits: 1

UART communication is handled using **interrupt-based reception**.

---

## Communication Protocol

The following command protocol is implemented:

| Command | Description |
|-------|-------------|
| `!RST#` | Request sensor data from STM32 |
| `!ADC=xxxx#` | STM32 response containing ADC value |
| `!OK#` | Acknowledgment from terminal |

Communication flow:

1. Terminal sends `!RST#`
2. STM32 reads sensor value (ADC)
3. STM32 sends response packet `!ADC=value#`
4. Terminal replies with `!OK#`
5. If no ACK is received within **3 seconds**, STM32 retransmits the packet

This mechanism demonstrates a simple **flow control and reliability concept**.

---

## Hardware / Simulation Setup

The system is simulated using **Proteus**.

Main components:

- STM32 microcontroller
- Virtual terminal (UART console)
- Potentiometer used as analog sensor input
- ADC channel connected to PA0
- LED indicator on PA5

The ADC value changes depending on the potentiometer position.

---

## Key Embedded Concepts

This project demonstrates several core embedded software techniques:

- UART communication using interrupts
- Command parser implementation
- Finite State Machine (FSM) design
- Simple communication protocol
- ADC sensor reading
- Packet retransmission using timeout

---

## Software Architecture

Main modules used in the project:
- main.c
- command_parser_fsm.c
- uart_communication_fsm.c
- adc.c
- uart_driver.c

---

## System Behavior

1. UART interrupt receives incoming characters
2. Characters are stored in a buffer
3. Command parser extracts valid commands
4. Communication FSM handles protocol logic
5. ADC value is read and sent to terminal
6. System waits for ACK confirmation


---

## Purpose of This Project

This project was developed to practice:

- UART-based embedded communication
- protocol design between devices
- interrupt-driven embedded programming
- state machine based software architecture
