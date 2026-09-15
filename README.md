# BabyFoodCooler

An ESP32-based device that reads food temperature with a non-contact IR sensor and blows a fan until it's safe to serve.

![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![Framework](https://img.shields.io/badge/framework-Arduino-teal)
![Build](https://img.shields.io/badge/build-PlatformIO-orange)

## Quick Look

- **What it does:** Measures food temperature without touching it, and runs a fan automatically until the food cools to a safe temperature
- **Hardware:** ESP32 + MLX90614 IR temperature sensor + relay-controlled fan
- **Software:** Built with VSCode + PlatformIO

## Features

- Non-contact temperature reading via the MLX90614 IR sensor (I2C)
- Automatic fan control via relay once a temperature threshold is set
- Non-blocking main loop using `millis()` timing

## Hardware

| Component | Model |
|---|---|
| Microcontroller | ESP32 Board (ELEGOO ESP-WROOM-32) |
| Temperature sensor | Hailege MLX90614 non-contact IR sensor |
| Relay | ELEGOO 4-Channel 5V Relay Module |
| Fan | 5V DC cooling fan (30-40mm) |

## Wiring diagram

**MLX90614 (I2C):**

| Sensor | ESP32 |
|---|---|
| VIN | 3V3 |
| GND | GND |
| SDA | D21 |
| SCL | D22 |

**Relay (fan control):**

| Relay | ESP32 |
|---|---|
| VCC | 5V (VIN) |
| GND | GND |
| IN1 | D25 |

Fan connects through the relay's NO/COM contacts, powered from the same 5V source as the ESP32.

## Getting Started

### Prerequisites

- [PlatformIO](https://platformio.org/) (VSCode extension or CLI)
- ESP32 board, MLX90614 sensor, and relay wired per the diagram above

### Setup

1. Clone the repository
2. Build, upload, open the serial monitor:
```bash
   pio run --target upload
   pio device monitor
```
   or use the PlatformIO extension for VSCode

## Project Structure

BabyFoodCooler/
├── include/
├── src/
│ └── main.cpp # Main application logic
├── test/
├── platformio.ini # PlatformIO project configuration
├── README.md
└── .gitignore

## License

MIT
