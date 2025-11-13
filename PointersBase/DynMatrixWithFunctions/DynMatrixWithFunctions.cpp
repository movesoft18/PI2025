#include <iostream>
using namespace std;

template <typename T>
T** Create2DArray(int rows, int cols)
{
    auto** arr = new T * [rows]; // выделяем память под массив указателей на строки
    for (int i = 0; i < rows; i++)
        arr[i] = new T[cols]; // выделяем память под массив для каждой строки
    return arr;
}

template <typename T>
void Print2DArray(T** arr, int rows, int cols)
{
    if (arr == nullptr || rows < 1 || cols < 1) return;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << '\t';
        cout << endl;
    }
}

template <typename T>
void Destroy2DArray(T** arr, int rows)
{
    if (arr == nullptr || rows < 1) return;
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

int main()
{
    int rows = 3;
    int cols = 4;

    // выделяем память
    auto** arr = Create2DArray<double>(rows, cols);
    // заполняем массив с консоли
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    // печать массива
    Print2DArray(arr, rows, cols);
    // удаление массива
    Destroy2DArray(arr, rows);
    arr = nullptr;
}

