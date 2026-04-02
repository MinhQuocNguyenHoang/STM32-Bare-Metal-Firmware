STARTUP_SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(OUT_DIR)/%.o,$(STARTUP_SRC))

all: $(OBJ)
	@echo "Building successfully"

$(OUT_DIR)/%.o:%.c
	@mkdir -p $(dir $@)
	@echo "Compiling ...."
	$(CC) $(CFLAGS) -c $< -o $@