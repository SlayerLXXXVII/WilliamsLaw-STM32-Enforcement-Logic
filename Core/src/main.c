#include "main.h"
#include "utils.h"
#include "control.h"
#include "sensors.h"
#include "stm32f7xx_hal.h"

#define SAMPLE_FREQ_HZ 10000
#define PHI_BUFFER_SIZE 10

TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart2;

float phi_buffer[PHI_BUFFER_SIZE];
uint16_t buffer_index = 0;

void TIM2_IRQHandler(void)
{
    if (__HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_UPDATE) != RESET)
    {
        __HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);

        float phi = read_phi();
        float psi = read_psi();
        phi_buffer[buffer_index] = phi;
        buffer_index = (buffer_index + 1) % PHI_BUFFER_SIZE;

        float phi_dot = compute_phi_dot(phi_buffer, PHI_BUFFER_SIZE);
        bool collapsed = check_collapse(phi, phi_dot);
        float lambda_val = get_lambda(phi, psi);

        if (collapsed) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
        }

        log_state(phi, psi, phi_dot, lambda_val, collapsed);
    }
}
