CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = matrix

all: $(TARGET)

$(TARGET): Matrix.cpp
	$(CXX) $(CXXFLAGS) Matrix.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
