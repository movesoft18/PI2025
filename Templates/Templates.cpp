
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T sum(T a, T b)
{
    return a + b;
}

/*
template <typename T, typename V>
T sum(T a, V b)
{
    return a + b;
}
*/

int main()
{
    setlocale(LC_ALL, "");
    cout << sum<double>(10, 20.8) << "\n";
    cout << sum<int>(10, 20.8) << "\n";
    cout << sum(10789423432LL, 20789542893LL) << "\n";
    cout << sum(10.55, 2094.467) << "\n";
    cout << sum(10.55f, 2094.467f) << "\n";
    cout << sum<string>("Привет", "Мир") << endl;
}

