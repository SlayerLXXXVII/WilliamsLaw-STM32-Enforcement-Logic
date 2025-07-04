#include "utils.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart3;

void init_logger(void) {
    // UART already configured by CubeMX
}

void log_state(float phi, float psi, float phi_dot, float lambda_val, bool collapsed) {
    char buf[128];
    int len = snprintf(buf, sizeof(buf),
        "Φ=%.3f, ψ=%.3f, dΦ=%.3f, λ=%.3f, C=%d\r\n",
        phi, psi, phi_dot, lambda_val, collapsed);
    HAL_UART_Transmit(&huart3, (uint8_t*)buf, len, HAL_MAX_DELAY);
}

float compute_phi_dot(const float *buffer, uint8_t size) {
    float sum = 0.0f;
    for (uint8_t i = 1; i < size; ++i) {
        sum += (buffer[i] - buffer[i-1]);
    }
    // 10 kHz sampling => Δt = 0.0001 s
    return sum / ((size - 1) * 0.0001f);
}
