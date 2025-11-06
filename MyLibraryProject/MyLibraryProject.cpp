#include <iostream>
#include "mylibrary.h"

//using namespace std;
//using namespace mylib;
using mylib::QuadraticEquation;

int main()
{
    setlocale(LC_ALL, "");
    double x1 = 0, x2 = 0;
    switch (QuadraticEquation(1, 2, 1, x1, x2))
    {
    case 0:
        std::cout << "Нет корней\n";
        break;
    case 1:
        std::cout << "x1=" << x1 << std::endl;
        break;
    case 2:
        std::cout << "x1=" << x1 << std::endl;
        std::cout << "x2=" << x2 << std::endl;
        break;
    case 3:
        std::cout << "Бесконечное множество корней\n";
        break;
    }
}

