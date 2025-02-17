#include "operations.hpp"

#include <cmath>

double math_ops::add(double a, double b) {
    return a + b;
}

double math_ops::sub(double a, double b) {
    return a - b;
}

double math_ops::mul(double a, double b) {
    return a * b;
}

double math_ops::div(double a, double b) {
    return a / b;
}

double math_ops::rem(double a, double b) {
    return std::fmod(a, b); 
}

double math_ops::exp(double a, double b) {
    return std::pow(a, b);
}
