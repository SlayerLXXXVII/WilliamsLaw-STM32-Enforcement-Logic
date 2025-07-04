.syntax unified
.cpu cortex-m7
.fpu softvfp
.thumb

.global g_pfnVectors
.global Reset_Handler

.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word  _estack
  .word  Reset_Handler
  .word  NMI_Handler
  .word  HardFault_Handler
  .word  MemManage_Handler
  .word  BusFault_Handler
  .word  UsageFault_Handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_Handler
  .word  DebugMon_Handler
  .word  0
  .word  PendSV_Handler
  .word  SysTick_Handler

.section .text.Reset_Handler
Reset_Handler:
  ldr   r0, =_sidata
  ldr   r1, =_sdata
  ldr   r2, =_edata

1:
  cmp   r1, r2
  ittt  lt
  ldrlt r3, [r0], #4
  strlt r3, [r1], #4
  blt   1b

  ldr   r0, =_sbss
  ldr   r1, =_ebss
  movs  r2, #0

2:
  cmp   r0, r1
  it    lt
  strlt r2, [r0], #4
  blt   2b

  bl main

trap:
  b trap

NMI_Handler:        b .
HardFault_Handler:  b .
MemManage_Handler:  b .
BusFault_Handler:   b .
UsageFault_Handler: b .
SVC_Handler:        b .
DebugMon_Handler:   b .
PendSV_Handler:     b .
SysTick_Handler:    b .

.section .stack
.word 0x20050000
_estack:
