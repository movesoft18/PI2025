#include <iostream>
#include <conio.h>
using namespace std;
int BinarySearch(int* array, int count, int element)
{
    int left = 0;
    int right = count - 1;
    while (left < right)
    {
        int middle = (right + left) / 2;
        if (array[middle] == element)
            return middle;
        if (element < array[middle])
            right = middle;
        else left = middle + 1;
    }
    return -1;
}
int main()
{
    int m[] = { 1,2,4,5,5,6,7,7,7,7,7,8,12,16,17,17,29 };
    int size = sizeof(m) / sizeof(int);
    int index = BinarySearch(m, size, 7);
    if (index >= 0)
        cout << "index=" << index << "\t value=" << m[index] << endl;
    else
        cout << "Element not found\n";
}