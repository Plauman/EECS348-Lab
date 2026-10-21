CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = calculator

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run: $(TARGET)
	./$(TARGET) tests.txt

clean:
	rm -f $(TARGET)

.PHONY: all run clean
