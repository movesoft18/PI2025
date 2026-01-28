#include <iostream>

int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
int factorial1(int n)
{
    if (n <= 1) return 1;
    return factorial1(n - 1) * n;
}

int sum(int n)
{
    if (n <= 1) return 1;
    return sum(n - 1) + n;
}
int classicSum(int n)
{
    int f = 0;
    for (int i = 1; i <= n; i++)
        f += i;
    return f;
}
int main()
{
    std::cout << factorial(5) << "\n";
    std::cout << factorial1(5) << "\n";
    std::cout << sum(10) << "\n";
    std::cout << classicSum(10) << "\n";
}

