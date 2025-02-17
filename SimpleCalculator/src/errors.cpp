#include "errors.hpp"
#include "utils.hpp"

#include <limits>

void errors::divideByZeroError() {
    std::cout << "Cannot divide by 0!" << std::endl;
}

void errors::invalidOperationError() {
    std::cout << "Invalid operation, try again." << std::endl;
}

void errors::badInput() {
    std::cout << "Bad input, retry!" << std::endl;
    utils::flushCinBuffer();
}

void errors::invalidActionError() {
    std::cout << "Invalid action, try again." << std::endl;
}