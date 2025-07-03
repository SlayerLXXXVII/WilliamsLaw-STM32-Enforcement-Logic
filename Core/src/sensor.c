#include "sensors.h"
#include "stm32f7xx_hal.h"

extern ADC_HandleTypeDef hadc1;

void init_sensors(void)
{
    // ADC already configured by CubeMX
}

float read_phi(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t val = HAL_ADC_GetValue(&hadc1);
    return ((float)val / 4095.0f) * 3.3f;
}

float read_psi(void)
{
    return 0.5f; // stub value for psi
}
