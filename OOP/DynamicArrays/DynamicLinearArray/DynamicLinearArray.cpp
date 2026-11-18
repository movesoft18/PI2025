// DynamicLinearArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int* AllocateIntArray(int arraySize)
{
    return new int[arraySize];
}
void PrintArray(int* m, int size)//  функция печати массива. В функцию передается указатель на массив
{
    for (int i = 0; i < size; i++)
        cout << m[i] << ' ';
    cout << endl;
}
int main()
{
    int size;
    cin >> size;
    int* a = AllocateIntArray(size);
    // работа с массивом
    delete[] a;
    a = nullptr; //  Не забываем присвоить указателю nullptr
}