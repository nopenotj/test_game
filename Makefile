CXX = g++
CXXFLAGS = -g -c -I/usr/local/include -fno-omit-frame-pointer -pg
LDFLAGS = -g -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -pg

BUILD_DIR := ./build
SRC_DIRS := ./src
OBJS := tiles.o main.o character.o user_events.o logger.o
OBJS := $(OBJS:%=$(BUILD_DIR)/%)


game: $(OBJS)
	echo $(OBJS)
	$(CXX) $(OBJS) -o game $(LDFLAGS) 

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.cpp
	mkdir -p build/
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf build/ game
