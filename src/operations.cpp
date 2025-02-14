#include "operations.hpp"

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
    return (long) a % (long) b;
}

void math_ops::calc(
    const Operator& op,
    const double& first,
    const double& second,
    std::function<double(double, double)> func
) {
    double result = func(first, second);
    std::cout << first << ' ' << op << ' ' << second << " = " << result << std::endl;
}
