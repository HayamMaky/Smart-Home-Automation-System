# Smart Home Automation Using ATmega32  

## Table of Contents  
- [Project Overview](#project-overview)  
- [Features](#features)  
- [Hardware Components](#hardware-components)  
- [System Architecture](#system-architecture)  
- [Software Requirements](#software-requirements)  
- [Drivers Overview](#drivers-overview)  
- [Installation & Usage](#installation--usage)  
- [Future Enhancements](#future-enhancements)  
- [Contributors](#contributors)  

---

## Project Overview  
This project aims to develop a **Smart Home Automation System** using an **ATmega32 microcontroller**. It automates **lighting and fan speed control** based on environmental conditions, ensuring energy efficiency and enhanced home safety.  

The system includes:  
- **Automatic lighting control** using an LDR.  
- **Temperature-based fan speed adjustment** using an LM35 sensor.  
- **Fire detection and alerts** using a flame sensor.  
- **Real-time status updates** on a 16x2 LCD.  

---

## Features  
✅ **Automatic Lighting Control** – Adjusts LED brightness based on ambient light.  
✅ **Automatic Fan Speed Control** – Adjusts fan speed based on room temperature.  
✅ **Fire Detection & Alerts** – Sounds an alarm and displays a warning on fire detection.  
✅ **LCD Display** – Real-time status updates on temperature, lighting, and fan status.  

---

## Hardware Components  
| Component       | Description | Connection Pins |
|---------------|------------|---------------|
| **Microcontroller** | ATmega32 | - |
| **Light Sensor** | LDR | PA0 (ADC Channel 0) |
| **Temperature Sensor** | LM35 | PA1 (ADC Channel 1) |
| **Flame Sensor** | Fire Detection | PD2 |
| **LCD Display** | 16x2 LCD (8-bit Mode) | RS: PD0, Enable: PD1, Data: PORTC |
| **Motor Control** | H-Bridge Circuit | IN1: PB0, IN2: PB1, Enable1: PB3/OC0 |
| **LEDs** | Red, Green, Blue | PB5, PB6, PB7 |
| **Buzzer** | Alarm System | PD3 |

---

## System Architecture  
This project follows a **layered architecture** approach:  
1. **Application Layer** – Controls system logic, user interface, and decision-making.  
2. **Service Layer** – Contains drivers for ADC, GPIO, LCD, PWM, and sensors.  
3. **Hardware Abstraction Layer (HAL)** – Provides interfaces to access hardware components.  

---

## Software Requirements  
- **Programming Language:** C  
- **Development Environment:** Atmel Studio / AVR-GCC  
- **Microcontroller Frequency:** 16 MHz  
- **Communication Protocols:** ADC, GPIO, PWM  

---

## Drivers Overview  

### 1. ADC Driver (Analog-to-Digital Converter)  
- Converts analog sensor values (LDR, LM35) to digital signals.  
- **Functions:**  
  - `void ADC_init(void)` – Initializes ADC with reference voltage and prescaler.  
  - `uint16 ADC_readChannel(uint8 channel_num)` – Reads ADC value from the specified channel.  

### 2. PWM Driver (Pulse Width Modulation)  
- Controls fan speed using Timer0 in PWM mode.  
- **Functions:**  
  - `void PWM_Timer0_Start(uint8 duty_cycle)` – Starts PWM with a given duty cycle.  

### 3. LCD Driver  
- Displays system status on a 16x2 LCD screen.  
- **Functions:**  
  - `void LCD_init(void)` – Initializes LCD in 8-bit mode.  
  - `void LCD_displayString(char *str)` – Displays a string on the LCD.  

### 4. LED Driver  
- Controls LED brightness based on LDR sensor data.  
- **Functions:**  
  - `void LEDS_init(void)` – Initializes LED pins.  
  - `void LED_on(LED_ID id)`, `void LED_off(LED_ID id)` – Turns LEDs on/off.  

### 5. DC Motor Driver  
- Controls fan speed using an H-bridge circuit.  
- **Functions:**  
  - `void DcMotor_Init(void)` – Initializes motor pins.  
  - `void DcMotor_Rotate(DcMotor_State state, uint8 speed)` – Sets motor direction and speed.  

### 6. Flame Sensor & Buzzer Driver  
- Detects fire and triggers an alert.  
- **Functions:**  
  - `void FlameSensor_init(void)`, `uint8 FlameSensor_getValue(void)`  
  - `void Buzzer_on(void)`, `void Buzzer_off(void)`  

---

## Installation & Usage  
1. **Connect the components** as per the circuit schematic.  
2. **Flash the firmware** to the ATmega32 using a USB programmer.  
3. **Power up the system** and observe the automated lighting, fan control, and fire detection.  
4. **Monitor real-time data** on the LCD
