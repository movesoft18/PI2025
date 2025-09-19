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
    int i = 1;
    while (i <= n && f * i <= 1000)
    {
        f *= i++; // f = f * i++;
    }
    cout << i-1 << "! = " << f << endl;
}

/*
    while (true)
    {
        // бесконечный
    }
    
    while (false)
    {
    }
*/