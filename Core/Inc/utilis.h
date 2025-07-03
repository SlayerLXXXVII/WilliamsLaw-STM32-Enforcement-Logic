#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdbool.h>

void init_logger(void);
void log_state(float phi, float psi, float phi_dot, float lambda_val, bool collapsed);
float compute_phi_dot(float *buffer, uint16_t size);

#endif // UTILS_H
