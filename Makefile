# Makefile for STM32F746ZG - Harmony Cell Project

TARGET = harmony_cell
CPU = cortex-m7
FAMILY = STM32F7
DEVICE = STM32F746xx

# Toolchain
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# Flags
CFLAGS = -mcpu=$(CPU) -mthumb -Wall -O2 -std=gnu11
CFLAGS += -D$(DEVICE) -DUSE_HAL_DRIVER
LDFLAGS = -Tldscripts/STM32F746ZGTx.ld -nostartfiles
ASFLAGS = -mcpu=$(CPU) -mthumb
OBJS = src/startup_stm32f746xx.o \
       src/system_stm32f7xx.o \
       src/main.o \
       src/harmony.o \
       src/utils.o

INCLUDES = -Iinc

all: $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(SIZE) $<

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin
