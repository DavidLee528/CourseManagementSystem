# catalog
BIN = ./bin
SRC = ./src
INC = ./include
OBJ = ./obj

# source(*.cpp) and object(*.o)
SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %.cpp, $(OBJ)/%.o, $(notdir ${SOURCE}))

# binary
TARGET = main
BIN_TARGET = $(BIN)/$(TARGET)

# compiler
CC = g++
CFLAGS = -g -Wall -I$(INC)

${BIN_TARGET}: $(OBJECT)
	$(CC) -o $@ $(OBJECT)

$(OBJ)/%.o: ${SRC}/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean
clean: 
	find $(OBJ) -name *.o -exec rm -rf {} \; 
	rm -rf $(BIN_TARGET)
