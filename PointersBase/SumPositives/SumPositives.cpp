#include <iostream>
using namespace std;
int sumPositive(int a1, int a2, int a3, int a4, int a5,
    int a6, int a7, int a8, int a9, int a10)
{
    int sum = 0;
    if (a1 > 0) sum += a1;
    if (a2 > 0) sum += a2;
    if (a3 > 0) sum += a3;
    if (a4 > 0) sum += a4;
    if (a5 > 0) sum += a5;
    if (a6 > 0) sum += a6;
    if (a7 > 0) sum += a7;
    if (a8 > 0) sum += a8;
    if (a9 > 0) sum += a9;
    if (a10 > 0) sum += a10;
    return sum;
}

int sumPositive1(int a1, int a2, int a3, int a4, int a5,
    int a6, int a7, int a8, int a9, int a10)
{
    int sum = 0;
    int* values[10] {&a1, &a2, &a3, &a4,
        &a5, &a6, &a7, &a8, &a9, &a10 };
    for (int i = 0; i < 10; i++)
        if (*values[i] > 0)
            sum += *values[i];
    return sum;
}

int main()
{
    std::cout << sumPositive(1,-1,-1,-1,-1,-1,1,-1,1,-1) << endl;
    std::cout << sumPositive1(1, -1, -1, -1, -1, -1, 1, -1, 1, -1) << endl;

}

