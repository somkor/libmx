# Variables
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I$(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_NAME = libmx.a
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
		ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

uninstall:
		rm -rf $(OBJ_DIR) $(LIB_NAME)

clean:
		rm -rf $(OBJ_DIR)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
