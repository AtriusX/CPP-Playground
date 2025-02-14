#include "utils.hpp"
#include "errors.hpp"
#include <algorithm>

void calculator();

void exitMessage() {
    std::cout << "Exiting..." << std::endl;
}

int main() {
    std::string action;

    while (true) {
        utils::getAction(&action, "Input action (calc, exit)");

        if (action == "calc") {
            calculator();
            continue;
        }

        if (action == "exit") {
            exitMessage();
            break;
        }

        if (action != "") {
            errors::invalidActionError();
        }
    }
}

void calculator() {
    double first;
    double second;
    math_ops::Operator op;

    utils::getInput(&first, "Input your first number");
    utils::getOperator(&op);
    utils::getInput(&second, "Input your second number");

    switch (op) {
        case math_ops::Operator::ADD:
            math_ops::calc(op, first, second, math_ops::add);
            break;

        case math_ops::Operator::SUB:
            math_ops::calc(op, first, second, math_ops::sub);
            break;

        case math_ops::Operator::MUL:
            math_ops::calc(op, first, second, math_ops::mul);
            break;

        case math_ops::Operator::DIV:
            if (second == 0)
                errors::divideByZeroError();
            else
                math_ops::calc(op, first, second, math_ops::div);
            break;

        case math_ops::Operator::REM:
            if (second == 0)
                errors::divideByZeroError();
            else
                math_ops::calc(op, first, second, math_ops::rem);
            break;
    }
}
