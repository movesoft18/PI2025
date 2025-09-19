// For.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    unsigned long long f = 1;
    int n;
    cout << "Введите n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f *= i; // f = f * i;
    }
    cout << n << "! = " << f << endl;
}

/*
    for(;;)
    {
        // бесконечный цикл
    }

    for(; i <= n;)
    {
        // цикл с предусловием
    }
*/