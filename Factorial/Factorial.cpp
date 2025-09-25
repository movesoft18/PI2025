#include <iostream>
using namespace std;

long long factorial (int n)
{
    unsigned long long f = 1;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

void exchange(int &v1, int &v2)
{
    int t = v1;
    v1 = v2;
    v2 = t;
}


int sum(const int a, const int b)
{
    if (a > b)
        exchange(a, b);
    int s = 0;
    for (int i = a; i <= b; i++)
        s += i;
    return s;
}


int main()
{
    setlocale(LC_ALL, "");
    for (int i = 0; i <= 15; i++)
        cout << i <<"! = " << factorial(i) << endl;

    for (int i = 1; i <= 15; i++)
        cout << "Сумма чисел от 1 до "<< i 
        << " = " << sum(1, i) << endl;
    int a = 56;
    int b = 100;
    int c = sum(b, a);
    cout << c << endl;
}