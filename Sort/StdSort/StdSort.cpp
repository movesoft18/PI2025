#include <algorithm>
#include <iostream>

int compareIntegers(const void* a, const void* b) 
{
    int int_a = *((const int*)a);
    int int_b = *((const int*)b);

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int main()
{
    int m[]{ 4,11,7,8,4,7,9,4,-5,-34, 0, 45, 211, -65 };
    int size = sizeof(m) / sizeof(int);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
    std::cout << std::endl;
    //std::sort(m, m + 14);
    //std::stable_sort(m, m + 14);
    std::qsort(m, size, sizeof(int), compareIntegers);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
    std::cout << std::endl;
}