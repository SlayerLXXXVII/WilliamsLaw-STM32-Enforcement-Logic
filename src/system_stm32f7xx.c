#include "stm32f7xx.h"

uint32_t SystemCoreClock = 216000000;

void SystemInit(void) {
    // FPU settings
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2)); // Enable CP10 and CP11 full access
#endif

    // Reset RCC
    RCC->CR |= (uint32_t)0x00000001; // Set HSION
    RCC->CFGR = 0x00000000;
    RCC->CR &= (uint32_t)0xFEF6FFFF; // Reset HSEON, CSSON, PLLON
    RCC->PLLCFGR = 0x24003010;
    RCC->CR &= (uint32_t)0xFFFBFFFF; // Reset HSEBYP
    RCC->CIR = 0x00000000;

    // Vector Table Relocation
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM1_BASE;
#else
    SCB->VTOR = FLASH_BASE;
#endif
}

void SystemCoreClockUpdate(void) {
    // Assume static config; nothing to update
}
