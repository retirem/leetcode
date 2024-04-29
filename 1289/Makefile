CXX = g++

CXXFLAGS = -g -Wall --std=c++20

TARGET = program

RM = rm -rf

all: clean $(TARGET) run

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).dSYM
