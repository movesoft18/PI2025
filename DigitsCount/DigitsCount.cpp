#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    cout << "Программа находит количество цифр целого натурального числа\n";
    int n, nCopy;
    int digitsCount = 0;
    do
    {
        cout << "Введите натуральное число: ";
        cin >> n;
        if (n <= 0)
            cout << "Некорректное значение.\n";
    } while (n <= 0);
    nCopy = n;
    while (n > 0)
    {
        digitsCount++;
        n = n / 10; // n /= 10;
    }
    cout << "В числе " << nCopy << " " << digitsCount << " цифр\n";
}

