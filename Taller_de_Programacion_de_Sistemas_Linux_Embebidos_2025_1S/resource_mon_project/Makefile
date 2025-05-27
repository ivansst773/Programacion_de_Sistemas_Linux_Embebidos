# ===========================
# Variables
# ===========================
CC = gcc
CFLAGS = -Wall -Wextra -I./src
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

SRC_FILES = $(SRC_DIR)/cpuinfo_manip.c \
             $(SRC_DIR)/meminfo_manip.c \
             $(SRC_DIR)/tui.c \
             $(SRC_DIR)/resource_mon.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TEST_SRC_FILES = $(TEST_DIR)/cpuinfo_test.c \
                  $(TEST_DIR)/meminfo_test.c \
                  $(TEST_DIR)/tui_test.c

TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRC_FILES))

# ===========================
# Targets principales
# ===========================
all: resource_mon tests

resource_mon: $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/resource_mon $(OBJ_FILES)

tests: $(OBJ_FILES) $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/cpuinfo_test $(OBJ_DIR)/cpuinfo_manip.o $(OBJ_DIR)/tui.o $(OBJ_DIR)/cpuinfo_test.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/meminfo_test $(OBJ_DIR)/meminfo_manip.o $(OBJ_DIR)/meminfo_test.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/tui_test $(OBJ_DIR)/tui.o $(OBJ_DIR)/tui_test.o

# ===========================
# Reglas de compilación
# ===========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===========================
# Limpieza
# ===========================
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
