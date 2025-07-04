
######################################################################
# Makefile for Harmony Cell - STM32F746ZG (No CubeMX)
######################################################################

# Target configuration
TARGET = harmony_cell
MCU = STM32F746ZG
CPU = -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard
FAMILY = STM32F7xx

# Paths
CORE = Core
DRIVERS = Drivers
CMSIS_INC = $(DRIVERS)/CMSIS/Include
DEVICE = $(DRIVERS)/CMSIS/Device/ST/STM32F7xx
INCLUDES = -I$(CORE)/Inc -I$(CMSIS_INC) -I$(DEVICE)

# Source files
SRCS = $(CORE)/Src/main.c $(CORE)/Src/harmony.c $(CORE)/Src/utils.c $(DEVICE)/system_stm32f7xx.c
OBJS = $(SRCS:.c=.o)

# Compiler tools
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
AS = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# Compiler flags
CFLAGS = $(CPU) -Wall -O2 -ffunction-sections -fdata-sections $(INCLUDES)
LDFLAGS = -Tlinker.ld -Wl,--gc-sections

# Output files
ELF = $(TARGET).elf
BIN = $(TARGET).bin

.PHONY: all clean flash

all: $(ELF) $(BIN)

$(ELF): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
	$(SIZE) $<

clean:
	rm -f $(OBJS) $(ELF) $(BIN)

flash: $(BIN)
	st-flash write $(BIN) 0x8000000
