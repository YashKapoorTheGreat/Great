SRC   := ../../Great/Src
OBJ	  := ../../Great/BuildInt
BUILD := ../../Great/Build/Linux

OUT	  := $(BUILD)/Great

SRCS  := $(wildcard $(SRC)/**/*.c) $(wildcard $(SRC)/**/**/*.c) $(wildcard $(SRC)/**/**/**/*.c) $(wildcard $(SRC)/*.c)
OBJS  := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CC	  := gcc
FLAGS := -g -I$(SRC)/include -Wall -Werror

all: $(OUT)

$(OUT) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p "./$(@D)"
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BUILD)
	mkdir -p "$(OBJ)"
	mkdir -p "$(BUILD)"
