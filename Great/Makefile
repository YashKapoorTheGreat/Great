SRC   := ./Src
OBJ	  := ./BuildInt
BUILD := ./Build
OUT	  := $(BUILD)/Great.exe
SRCS  := $(wildcard $(SRC)/**/*.c) $(wildcard $(SRC)/**/**/*.c) $(wildcard $(SRC)/**/**/**/*.c) $(wildcard $(SRC)/*.c)
OBJS  := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CC	  := gcc
FLAGS := -g -I$(SRC)/include -Wall -Werror

all: $(OUT)

$(OUT) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	powershell mkdirIfNotExists "./$(@D)"
	$(CC) $(FLAGS) -c $< -o $@

clean:
	powershell rm -Recurse $(OBJ)
	powershell rm -Recurse $(BUILD)
	mkdir "$(OBJ)"
	mkdir "$(BUILD)"
