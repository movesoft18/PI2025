
#include <iostream>
using namespace std;

int sum(int a, int b, int c = 0, int d = 0, int e = 0)
{
    return a + b + c + d + e;
}

double sum(double a, double b)
{
    return a + b;
}


double sum(int a, double b)
{
    return a + b;
}

double sum(double a, int b)
{
    return a + b;
}

long long sum(long long a, long long b)
{
    return a + b;
}

float sum(float a, float b)
{
    return a + b;
}

int main()
{
    cout << sum(10, 20) << "\n";
    cout << sum(10, 20, 30 , 40) << "\n";
    cout << sum(10789423432LL, 20789542893LL) << "\n";
    cout << sum(10.55, 2094.467) << "\n";
    cout << sum(10.55f, 2094.467f) << "\n";
}

