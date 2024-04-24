CXX = g++

CXXFLAGS = -g -Wall

TARGET = program

RM = rm -rf

all: clean $(TARGET) run

$(TARGET): $(TARGET).cpp
	$(CXX) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).dSYM
