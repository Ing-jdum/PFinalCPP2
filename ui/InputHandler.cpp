#include "InputHandler.h"
#include "../utils/Validation.h"
#include <iostream>
#include <limits>

std::string InputHandler::getString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return Validation::trim(input);
}

double InputHandler::getDouble(const std::string& prompt) {
    // TODO: Get a valid double from user input with validation
    // INSTRUCTIONS:
    // 1. Use a loop to keep asking until valid input
    // 2. Display the prompt
    // 3. Read a line of input using std::getline
    // 4. Use Validation::isValidDouble() to check if input is valid
    // 5. If valid, convert using std::stod() and return
    // 6. If invalid, show error message and ask again
    // 7. Handle the case where user enters non-numeric input

    // Your implementation here
    return 0.0;
}

int InputHandler::getInt(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        input = Validation::trim(input);
        
        if (Validation::isValidInt(input)) {
            try {
                return std::stoi(input);
            } catch (const std::exception&) {
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
    }
}

bool InputHandler::getYesNo(const std::string& prompt) {
    // TODO: Get yes/no input from user
    // INSTRUCTIONS:
    // 1. Use a loop to keep asking until valid input
    // 2. Display prompt with " (y/n): " suffix
    // 3. Read input and convert to lowercase using Validation::toLowerCase()
    // 4. Check if input is "y", "yes", "n", or "no"
    // 5. Return true for yes, false for no
    // 6. Show error for invalid input and ask again

    // Your implementation here
    return false;
}

void InputHandler::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void InputHandler::waitForEnter() {
    // TODO: Wait for user to press Enter
    // INSTRUCTIONS:
    // 1. Display message "Press Enter to continue..."
    // 2. Use std::cin.ignore() to wait for Enter key
    // 3. Use std::numeric_limits<std::streamsize>::max() for the count parameter

    // Your implementation here
}