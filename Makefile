# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = blackjack
SOURCES = Card.cpp Deck.cpp src/Player.cpp src/Game.cpp src/Network.cpp src/UI.cpp src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run