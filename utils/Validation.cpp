#include "Validation.h"
#include <cctype>
#include <algorithm>
#include <sstream>

bool Validation::isValidDouble(const std::string& str) {
    // TODO: Check if string represents a valid double number
    // INSTRUCTIONS:
    // 1. Handle empty string - return false
    // 2. Use std::istringstream to try parsing the string as double
    // 3. Check if parsing succeeded and entire string was consumed
    // 4. Return true if valid double, false otherwise
    // HINT: Use iss >> value and check iss.eof() and !iss.fail()

    // Your implementation here
    return false;
}

bool Validation::isValidInt(const std::string& str) {
    std::string trimmed = trim(str);
    if (trimmed.empty()) {
        return false;
    }

    size_t start = 0;
    if (trimmed[0] == '+' || trimmed[0] == '-') {
        start = 1;
        if (trimmed.length() == 1) {
            return false; // Just a sign character
        }
    }

    for (size_t i = start; i < trimmed.length(); ++i) {
        if (!std::isdigit(trimmed[i])) {
            return false;
        }
    }

    return true;
}

bool Validation::isValidUnitName(const std::string& name) {
    // TODO: Check if string is a valid unit name
    // INSTRUCTIONS:
    // 1. Trim the string first using trim() function
    // 2. Check if trimmed string is empty - return false
    // 3. Check if first character is alphabetic (use std::isalpha)
    // 4. Check remaining characters are alphanumeric or space (use std::isalnum)
    // 5. Return true if all checks pass

    // Your implementation here
    return false;
}

std::string Validation::trim(const std::string& str) {
    if (str.empty()) {
        return str;
    }

    size_t start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        start++;
    }

    if (start == str.length()) {
        return ""; // All whitespace
    }

    size_t end = str.length() - 1;
    while (end > start && std::isspace(str[end])) {
        end--;
    }

    return str.substr(start, end - start + 1);
}

std::string Validation::toLowerCase(const std::string& str) {
    // TODO: Convert string to lowercase
    // INSTRUCTIONS:
    // 1. Create a copy of the input string
    // 2. Use std::transform with std::tolower to convert each character
    // 3. Return the transformed string
    // HINT: std::transform(result.begin(), result.end(), result.begin(), ::tolower)

    // Your implementation here
    return "";
}