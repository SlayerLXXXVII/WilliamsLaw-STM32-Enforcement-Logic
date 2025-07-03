#include "sensor_interface.h"
#include "config.h"

// Platform-specific includes here (HAL, LL, etc.)

void sensor_init(void) {
    // Initialize ADC peripheral at PHI_SAMPLE_RATE_HZ
}

float read_phi(void) {
    // Trigger ADC conversion, wait, and return calibrated value
    return 0.0f; // placeholder
}
