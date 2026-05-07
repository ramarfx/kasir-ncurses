CXX = g++
CXXFLAGS = -Wall -std=c++17

# Use 'find' to get all .cpp files recursively in the src/ directory
SRC = $(shell find src -name '*.cpp')

OUT = kasir

all:
	$(CXX) $(SRC) $(CXXFLAGS) -lncurses -o $(OUT)