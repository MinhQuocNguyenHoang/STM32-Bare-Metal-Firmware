.PHONY: all drivers app clean startup

export DIR := $(CURDIR)
export OUT_DIR := $(DIR)/Build/out
TARGET := $(OUT_DIR)/main.elf
BIN := Build/out/main.bin
ELF := Build/out/main.elf

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

export CFLAGS += -I$(DIR)/drivers/gpio \
                 -I$(DIR)/drivers/rcc \
                 -I$(DIR)/drivers/uart

export LINKER_SCRIPT := $(DIR)/linker/STM32F103RCT6.ld
export LDFLAGS := $(CPU) \
           -T$(LINKER_SCRIPT) \
           -Wl,-Map=$(OUT_DIR)/main.map \
           -Wl,--gc-sections


all: drivers app startup $(TARGET) $(BIN)
	@echo "Build successfully"

drivers:
	@$(MAKE) -C drivers

app:
	@$(MAKE) -C app

startup:
	@$(MAKE) -C startup

$(TARGET):
	@echo "Linking..."
	$(CC) $(shell find $(OUT_DIR) -name "*.o") $(LDFLAGS) -o $@

$(BIN): $(ELF)
	arm-none-eabi-objcopy -O binary $< $@

clean:
	rm -rf $(OUT_DIR)
	@echo "clean successfully"
