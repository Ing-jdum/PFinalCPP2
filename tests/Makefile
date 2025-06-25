
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRCDIR = ..
SOURCES = $(SRCDIR)/core/LoanCalculator.cpp $(SRCDIR)/core/CreditAnalyzer.cpp $(SRCDIR)/utils/Validation.cpp $(SRCDIR)/ui/InputHandler.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = student_tests

all: $(TARGET)

$(TARGET): StudentTests.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) StudentTests.cpp $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
