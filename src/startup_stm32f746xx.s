.syntax unified
.cpu cortex-m7
.fpu fpv5-d16
.thumb

.global g_pfnVectors
.global Reset_Handler

.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word MemManage_Handler
  .word BusFault_Handler
  .word UsageFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word DebugMon_Handler
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler

/* Weak default handlers */
.section .text.Reset_Handler
Reset_Handler:
  ldr r0, =_estack
  mov sp, r0

  bl SystemInit
  bl main

LoopForever:
  b LoopForever

/* Default handlers */
NMI_Handler:         b .
HardFault_Handler:   b .
MemManage_Handler:   b .
BusFault_Handler:    b .
UsageFault_Handler:  b .
SVC_Handler:         b .
DebugMon_Handler:    b .
PendSV_Handler:      b .
SysTick_Handler:     b .

.size Reset_Handler, . - Reset_Handler
