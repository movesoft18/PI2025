#include <iostream>
using namespace std;

// ax + b = 0
void LinearEquation(
    double a, // Коэф. а
    double b,  // Коэф. b
    int& rootsCount,    // Кол-во найденных корней
                        // 0 - корней нет
                        // 1 - если 1 корень
                        // 2 - бесконечное мн. корней
    double& root        // Это сам корень, если он есть
)
{
    if (a != 0)
    { // Имеем 1 корень
        rootsCount = 1;
        root = -b / a;
        return;
    }
    if (b == 0)
    {   // Имеем беск. множ. решений.
        rootsCount = 2;
        return;
    }
    rootsCount = 0;
}

int main()
{
    setlocale(LC_ALL, "");
    double a, b;
    cout << "Введите 2 коэффициента уравнения ax+b=0: ";
    cin >> a >> b;
    int rootsCount = 0;
    double x = 0;
    LinearEquation(a, b, rootsCount, x);
    switch (rootsCount)
    {
    case 0: 
        cout << "Корней нет\n";
        break;
    case 1:
        cout << "x = " << x << endl;
        break;
    case 2:
        cout << "x - любое число";
        break;
    }
}
