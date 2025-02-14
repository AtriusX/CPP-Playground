#pragma once

#include <string>
#include <iostream>

#include "operations.hpp"
#include "errors.hpp"

namespace utils {

    template <typename T>
    void getInput(T* data, std::string message) {
        while (true) {
            std::cout << message << ": ";
            std::cin >> *data;

            if (!std::cin.fail()) {
                break;
            }

            errors::badInput();
        }
    }

    void getOperator(math_ops::Operator* op);

    void lowercase(std::string& data);
    
    void getAction(std::string* data, std::string message);
}
