#include <iostream>
using namespace std;
void Calculate()
{
    double a, b, c;
    cout << "Введите коэффициент a, b, с через пробел:";
    cin >> a >> b >> c;
    if (cin.good())
    {
        double d = b * b - 4 * a * c;
        cout << "d = " << d << endl;
    }
    else
    {
        cout << "Ошибка входных данных.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");
    Calculate();
}