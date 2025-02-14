#include "utils.hpp"
#include "errors.hpp"

#include <limits>
#include <ranges>
#include <algorithm>

void utils::flushCinBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void utils::getOperator(math_ops::Operator* op) {
    std::string opChar;

    while (true) {
        utils::getInput(&opChar, "Input operator (+, -, *, /, %)");

        if (opChar.length() != 1) {
            errors::invalidOperationError();
            continue;
        }

        switch (auto& c = opChar[0]) {
            case math_ops::Operator::ADD:
            case math_ops::Operator::SUB:
            case math_ops::Operator::MUL:
            case math_ops::Operator::DIV:
            case math_ops::Operator::REM:
                *op = (math_ops::Operator) c;
                return;
            default:
                errors::invalidOperationError();
        }
    }
}

void utils::lowercase(std::string& data) {
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}

void utils::getAction(std::string* data, std::string message) {
    std::cout << message << ": ";
    std::getline(std::cin, *data);
    utils::lowercase(*data);
}