#include "utils.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

void init_logger(void)
{
    // Optional UART init here
}

void log_state(float phi, float psi, float phi_dot, float lambda_val, bool collapsed)
{
    char msg[128];
    snprintf(msg, sizeof(msg), "Phi:%.4f,Psi:%.4f,dPhi:%.4f,Lambda:%.4f,C:%d\r\n",
             phi, psi, phi_dot, lambda_val, collapsed);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}

float compute_phi_dot(float *buffer, uint16_t size)
{
    float sum = 0.0f;
    for (uint16_t i = 1; i < size; i++)
    {
        sum += (buffer[i] - buffer[i - 1]);
    }
    return sum / ((size - 1) * 0.0001f); // 10 kHz = 100 µs
}
