DRIVER_SRC := $(wildcard */*.c)
OBJ := $(patsubst %.c,$(OUT_DIR)/%.o,$(notdir($(DRIVER_SRC)))

all: $(OBJ)
	echo "Build successfully"

$(OUT_DIR)/%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@
