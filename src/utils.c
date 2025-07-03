#include "utils.h"
#include <stdio.h>
#include <math.h>

// Clamp a float between min and max
float clampf(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// Map float from one range to another
float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Placeholder delay function (should use timer peripheral)
void delay_us(uint32_t microseconds) {
    volatile uint32_t count = microseconds * 10;
    while (count--) __asm__("nop");
}

// Optional UART logger (can be redirected or stubbed)
void log_status(float phi, float psi, float lambda) {
    printf("[LOG] Φ: %.3f  ψ: %.3f  λ: %.3f\n", phi, psi, lambda);
}
