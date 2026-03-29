export DIR := $(CURDIR)

#toolchain and linker script of toolchain
export COMPILER_DIR := $(DIR)/Build/toolchain/bin
export PREFIX := arm-none-eabi-

export CC := $(COMPILER_DIR)/$(PREFIX)gcc

export CPU := -mcpu=cortex-m3 -mthumb
export CFLAGS := $(CPU) \
          -std=c11 \
          -O0 \
          -Wall \
          -ffreestanding \
          -nostartfiles \
          -ffunction-sections \
          -fdata-sections \
          -g

# Linker script of project
export LINKER_SCRIPT := linker/STM32F103RCT6.ld
export LDFLAGS := $(CPU) \
           -T$(LINKER_SCRIPT) \
           -Wl,-Map=main.map \
           -Wl,--gc-sections

#building
export OUT_DIR := $(DIR)/Build/out

all:
	@$(MAKE) -C drivers

clean:
	rm -rf $(OUT_DIR)/*.o $(OUT_DIR)/*.elf
	@echo "clean successfully"
	







