######################################
# target
######################################
TARGET = Blink_$(BOARD)


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build_$(BOARD)

######################################
# source
######################################
# C sources
C_SOURCES =  \
src/main.c \
src/HAL.c \
at32f4xx/at32f4xx_it.c \
at32f4xx/system_at32f4xx.c \
../Firmware/AT32/AT32F4xx_StdPeriph_Driver/src/at32f4xx_rcc.c \
../Firmware/AT32/AT32F4xx_StdPeriph_Driver/src/at32f4xx_gpio.c \
../Firmware/AT32/AT32F4xx_StdPeriph_Driver/src/at32f4xx_gpio_ex.c \
../Firmware/AT32/AT32F4xx_StdPeriph_Driver/src/misc.c \

# ASM sources
ASM_SOURCES =  \
at32f4xx/startup_at32f421c8t7.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
# NONE for Cortex-M0/M0+/M3
FPU =

# float-abi
FLOAT-ABI =

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS =

# C defines
C_DEFS =  \
-D USE_STDPERIPH_DRIVER \
-D AT32F421C8T7 \
$(BOARD_DEFS)


# AS includes
AS_INCLUDES =

# C includes
C_INCLUDES =  \
-Isrc \
-Iat32f4xx \
-I../Firmware/AT32/AT32F4xx_StdPeriph_Driver/inc \
-I../Firmware/AT32/CMSIS/CM4/CoreSupport \
-I../Firmware/AT32/CMSIS/CM4/DeviceSupport \

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fno-common -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -Wpedantic -Wextra -fno-common -fdata-sections -ffunction-sections -std=c99 $(BOARD_FLAGS)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = at32f4xx/AT32F421x8_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

.PHONY : all

# default action: build all
all: Blink

Blink:
	$(MAKE) BOARD=BluePill DEBUG=0 OPT=-Os elf hex bin

#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

ELF_TARGET = $(BUILD_DIR)/$(TARGET).elf
BIN_TARGET = $(BUILD_DIR)/$(TARGET).bin
HEX_TARGET = $(BUILD_DIR)/$(TARGET).hex

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

bin: $(BIN_TARGET)

elf: $(ELF_TARGET)

hex: $(HEX_TARGET)

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)*

clean_obj:
	-rm -f $(BUILD_DIR)*/*.o $(BUILD_DIR)*/*.d $(BUILD_DIR)*/*.lst

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
