// DynamicLinearArrayTemplate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

template <typename T>
T* AllocateArray(int arraySize)
{
    return new T[arraySize];
}

template <typename T>
void PrintArray(T* m, int size)//  функция печати массива. В функцию передается указатель на массив
{
    for (int i = 0; i < size; i++)
        cout << m[i] << ' ';
    cout << endl;
}
int main()
{
    int size;
    cin >> size;
    // ...
    double* a = AllocateArray<double>(size);

    // работа с массивом
    PrintArray(a, size);
    delete[] a;
    a = nullptr; //  Не забываем присвоить указателю nullptr
}