DRIVER_SRC := $(wildcard */*.c)
OBJ := $(patsubst %.c,$(OUT_DIR)/%.o,$(DRIVER_SRC))

all: $(OBJ)
	@echo "Build successfully"

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@
