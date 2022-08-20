CC = g++
CFLAGS = -c -I/usr/local/include

BUILD_DIR := ./build
SRC_DIRS := ./src
game: $(BUILD_DIR)/main.o
	$(CC) -o game -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system $(BUILD_DIR)/main.o 
$(BUILD_DIR)/main.o: $(SRC_DIRS)/main.cpp
	g++ -c -I/usr/local/include $(SRC_DIRS)/main.cpp -o $@
