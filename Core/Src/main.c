#include "main.h"
#include "harmony_cell.h"
#include "sensors.h"
#include "utils.h"
#include "stm32f7xx_hal.h"

#define SAMPLE_BUFFER_SIZE  10

extern TIM_HandleTypeDef    htim2;
extern UART_HandleTypeDef   huart3;

static float phi_buf[SAMPLE_BUFFER_SIZE];
static uint8_t buf_idx = 0;

int main(void) {
    HAL_Init();
    SystemInit();
    HAL_TIM_Base_Start_IT(&htim2);   // 10 kHz timer interrupt
    init_sensors();
    init_logger();
    Harmony_Init();

    while (1) {
        // Main loop can handle lower-priority tasks if needed
        HAL_Delay(1000);
    }
}

// Called in TIM2 interrupt at 10 kHz
void TIM2_IRQHandler(void) {
    if (__HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_UPDATE)) {
        __HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);

        HarmonyPacket pkt;
        float lambda_val;
        bool collapsed;

        // 1) Read sensors
        pkt.phi = read_phi();
        pkt.psi = read_psi();

        // 2) Update buffer and compute phi_dot
        phi_buf[buf_idx] = pkt.phi;
        buf_idx = (buf_idx + 1) % SAMPLE_BUFFER_SIZE;
        pkt.phi_dot = compute_phi_dot(phi_buf, SAMPLE_BUFFER_SIZE);

        // 3) Enforcement
        collapsed = Harmony_Enforce(&pkt, &lambda_val);

        // 4) Actuate collapse trigger
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, collapsed ? GPIO_PIN_SET : GPIO_PIN_RESET);

        // 5) Optional: use lambda_val to drive piezo or other actuators
        // set_piezo(lambda_val);

        // 6) Log state
        log_state(pkt.phi, pkt.psi, pkt.phi_dot, lambda_val, collapsed);
    }
}
