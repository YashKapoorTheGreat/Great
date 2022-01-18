SRC   := ./Src
OBJ	  := ./Objs
BUILD := ./Build
OUT	  := $(BUILD)/Great
SRCS  := $(wildcard $(SRC)/**/*.c) $(wildcard $(SRC)/**/**/*.c) $(wildcard $(SRC)/*.c)
OBJS  := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CC	  := gcc
FLAGS := -g -I$(SRC)/include -Wall

all: $(OUT)

$(OUT) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	powershell mkdirIfNotExists "./$(@D)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUT)
