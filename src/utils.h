#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

// Basic math utils
float clampf(float value, float min, float max);
float mapf(float x, float in_min, float in_max, float out_min, float out_max);

// Timing (placeholder if HAL_Delay or SysTick not available)
void delay_us(uint32_t microseconds);

// Logging helper
void log_status(float phi, float psi, float lambda);

#endif // UTILS_H
