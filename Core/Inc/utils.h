#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdbool.h>

// Initialize UART logger (uses huart3)
void init_logger(void);

// Log system state: prints via UART
void log_state(float phi, float psi, float phi_dot, float lambda_val, bool collapsed);

// Compute phi_dot from circular buffer at known 10 kHz rate
float compute_phi_dot(const float *buffer, uint8_t size);

#endif // UTILS_H
