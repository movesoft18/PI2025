#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int a, int b)
{
    if (b == 0) 
        throw std::exception("Ошибка деления на 0");
    return a / b;
}

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        double result = divide(4, 0);
        cout << result << endl;
    }
    catch (std::exception e)
    {
        cout << e.what() << endl;
    }
}