#include <cmath>
#include "mylibrary.h"


namespace mylib
{
    int LinearEquation(
        double a, // Коэф. а
        double b,  // Коэф. b
        double& root        // Это сам корень, если он есть
    )
    {
        if (a != 0)
        { // Имеем 1 корень
            root = -b / a;
            return 1;
        }
        if (b == 0)
        {   // Имеем беск. множ. решений.
            return 2;
        }
        return 0;
    }


    int QuadraticEquation(double a, double b, double c,
        double& x1, double& x2)
    {
        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    return 3;
                }
                else {
                    return 0;
                }
            }
            else {
                x1 = -c / b;
                return 1;
            }
        }
        else {

            double D = b * b - 4 * a * c;

            if (D < 0) {
                return 0;
            }
            else if (D == 0) {
                x1 = -b / (2 * a);
                return 1;
            }
            else {
                double sqrtD = sqrt(D);
                x1 = (-b + sqrtD) / (2 * a);
                x2 = (-b - sqrtD) / (2 * a);
                return 2;
            }
        }
    }
}