#include <iostream>
using namespace std;
int BinarySearch(int* array, int count, int element)
{
    int left = 0;
    int right = count - 1;
    while (left < right)
    {
        int middle = (right + left) / 2;
        if (element <= array[middle])
            right = middle;
        else left = middle + 1;
    }
    if (array[right] == element)
        return right;
    return -1;
}
int main()
{
    setlocale(LC_ALL, "");
    int m[] = { 1,2,4,5,5,6,7,7,7,7,7,8,12,16,17,17,29 };
    int size = sizeof(m) / sizeof(int);
    int index = BinarySearch(m, size, 7);
    if (index == -1)
        cout << "Элемент не найден\n";
    while (index < size && m[index] == 7)
    {
        cout << "Элемент найден под индексом " << index << endl;
        index++;
    }
}


