/* linker.ld — Linker script for STM32F746ZG */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 320K
}

SECTIONS
{
  .text : {
    KEEP(*(.isr_vector))
    *(.text*)
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
  } > FLASH

  .ARM.extab : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > FLASH
  .ARM.exidx : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } > FLASH

  .data : AT(ADDR(.text) + SIZEOF(.text)) {
    *(.data*)
    *(.ramfunc*)
  } > RAM

  .bss : {
    *(.bss*)
    *(COMMON)
  } > RAM

  .heap (COPY): { *(.heap*) } > RAM
  .stack (COPY): { *(.stack*) } > RAM
}
