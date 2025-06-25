CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
CORE_SOURCES = core/LoanCalculator.cpp core/CreditAnalyzer.cpp
UI_SOURCES = ui/Menu.cpp ui/InputHandler.cpp
UTIL_SOURCES = utils/Validation.cpp
MAIN_SOURCE = main.cpp

# Object files
CORE_OBJECTS = $(CORE_SOURCES:.cpp=.o)
UI_OBJECTS = $(UI_SOURCES:.cpp=.o)
UTIL_OBJECTS = $(UTIL_SOURCES:.cpp=.o)
MAIN_OBJECT = $(MAIN_SOURCE:.cpp=.o)

ALL_OBJECTS = $(CORE_OBJECTS) $(UI_OBJECTS) $(UTIL_OBJECTS) $(MAIN_OBJECT)

TARGET = main

all: $(TARGET)

$(TARGET): $(ALL_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(ALL_OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

test:
	cd tests && make run

.PHONY: all clean run test