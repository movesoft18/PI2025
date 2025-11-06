#pragma once

namespace mylib
{
    int LinearEquation(
        double a, // Коэф. а
        double b,  // Коэф. b
        double& root        // Это сам корень, если он есть
    );

    int QuadraticEquation(double a, double b, double c,
        double& x1, double& x2);
}

