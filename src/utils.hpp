#pragma once

#include <string>
#include <iostream>

#include "operations.hpp"
#include "errors.hpp"

namespace utils {

    void flushCinBuffer();

    template <typename T>
    void getInput(T* data, const std::string& message) {
        while (true) {
            std::cout << message << ": ";
            std::cin >> *data;
            utils::flushCinBuffer();

            if (!std::cin.fail()) {
                break;
            }

            errors::badInput();
        }
    }

    void getOperator(math_ops::Operator* op);

    void lowercase(std::string& data);
}
