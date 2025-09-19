#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    setlocale(LC_ALL, "");
    char operation;
    bool needCalculate = true;
    cout << "Введите через пробел первое число, опреацию, второе число: ";
    cin >> a >> operation >> b;
    switch (operation)
    {
    case '+':
        c = a + b;
        break;
    case '-':
        c = a - b;
        break;
    case '*':
        c = a * b;
        break;
    case '\\':
    case '/':
        c = a / b;
        break;
    case '^':
        c = pow(a, b);
        break;
    default:
        needCalculate = false;
        break;
    }
    if (needCalculate)
    {
        cout << a << " " << operation << " " 
            << b << " = " << c << endl;
    }
    else
    {
        cout << "Неизвестная операция\n";
    }
}

