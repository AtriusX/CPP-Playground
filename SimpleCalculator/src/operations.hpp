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
        EXP = '^',
    };

    double add(double a, double b);

    double sub(double a, double b);

    double mul(double a, double b);

    double div(double a, double b);

    double rem(double a, double b);

    double exp(double a, double b);

    template <typename F>
    void calc(
        const Operator& op,
        const double& first,
        const double& second,
        F&& func
    ) {
        double result = func(first, second);
        std::cout << first << ' ' << op << ' ' << second << " = " << result << std::endl;
    }
}