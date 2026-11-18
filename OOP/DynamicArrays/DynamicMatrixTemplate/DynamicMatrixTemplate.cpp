#include <iostream>
using namespace std;

template <typename T>
T** Create2DArray(int cols, int rows)
{
    if (rows <= 0 || cols <= 0) return nullptr; //если неверное кол-во строк и столбцов - выходим
    T** a = new T * [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
    return a;
}

template <typename T>
void Destroy2DArray(T** m, int rows)
{
    if (rows <= 0 || m == nullptr) return;
    if (m)
    {
        for (int i = 0; i < rows; i++)
            delete[] m[i];
        delete[] m;
    }
}

template <typename T>
void Print2DArray(T** m, int cols, int rows)
{
    if (rows <= 0 || cols <= 0 || m == nullptr) return; // проверка размеров матрицы на допустимые величины, а также является ли указатель на матрицу пустым
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < cols; i++)
            cout << m[j][i] << " ";
        cout << endl;
    }
}

int main()
{
    int** m1 = Create2DArray<int>(4, 5); // создаем двумерный массив 5 стр, 4 столбцов
    if (m1)
    {
        Print2DArray<int>(m1, 4, 5); // печатаем в консоль его содержимое
        Destroy2DArray<int>(m1, 5); // освобождаем
    }
}
