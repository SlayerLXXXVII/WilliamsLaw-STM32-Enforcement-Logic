# Firmware for Harmony Cell v2

This folder contains STM32 firmware implementing the Williams Law collapse enforcement logic.

## Files
- `main.c`              — Main loop
- `lambda_control.*`    — Control law for λ(Φ, ψ)
- `sensor_interface.*`  — Φ-sensor ADC sampling
- `actuator_driver.*`   — Piezo actuator control
- `config.h`            — Thresholds and constants

## Build Instructions
1. Open in STM32CubeIDE or PlatformIO.
2. Adjust `config.h` for your hardware.
3. Build and flash to STM32F7.
4. Monitor UART at 115200 baud for log output.
