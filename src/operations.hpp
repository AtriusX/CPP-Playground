#pragma once

#include <iostream>
#include <functional>

namespace math_ops {

    enum Operator : char {
        ADD = '+',
        SUB = '-',
        MUL = '*',
        DIV = '/',
        REM = '%',
    };

    double add(double a, double b);

    double sub(double a, double b);

    double mul(double a, double b);

    double div(double a, double b);

    double rem(double a, double b);

    void calc(
        const Operator& op,
        const double& first,
        const double& second,
        const std::function<double(double, double)>& func
    );
}