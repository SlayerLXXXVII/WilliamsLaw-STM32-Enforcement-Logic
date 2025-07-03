#include "main.h"
#include "utils.h"
#include "sensors.h"
#include "control.h"
#include "stm32f7xx_hal.h"

#define LOOP_INTERVAL_US 100  // 10 kHz loop rate
#define LOG_INTERVAL_MS 100   // Log every 100 ms

UART_HandleTypeDef huart2;
TIM_HandleTypeDef htim2;

uint32_t last_log_time = 0;
float phi = 0.0f, psi = 0.0f, lambda = 0.0f;
float phi_dot = 0.0f;

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init(&huart2);
    MX_TIM2_Init(&htim2);

    HAL_TIM_Base_Start(&htim2);
    uint32_t last_loop = HAL_GetTick();

    while (1) {
        uint32_t now = HAL_GetTick();
        if ((now - last_loop) >= LOOP_INTERVAL_US / 1000) {
            last_loop = now;

            // --- Sensor Sampling ---
            phi = read_phi_sensor();
            psi = read_psi_sensor();
            phi_dot = update_phi_rate(phi);

            // --- λ Enforcement ---
            lambda = compute_lambda(phi, psi);

            // --- Collapse Check ---
            if (check_collapse(phi, phi_dot)) {
                trigger_collapse_event(lambda);
            }

            // --- Logging (every 100ms) ---
            if ((now - last_log_time) >= LOG_INTERVAL_MS) {
                log_state(&huart2, phi, psi, phi_dot, lambda);
                last_log_time = now;
            }
        }
    }
}
