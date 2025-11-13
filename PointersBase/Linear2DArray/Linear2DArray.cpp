
#include <iostream>
using namespace std;

int tmp[12]{ 1, 2, 3, 4,  
             5, 6, 7, 8,
             9,10,11,12
};

int main()
{
    setlocale(LC_ALL, "");
    int cols = 4;
    int rows = 3;
    // здесь код, который присваивает значение переменной size (например с консоли)
    // 1. выделяем память под массив в куче
    int* a = new int[cols * rows];
    // 2. Работаем с массивом, в соответствии с вашими задачами.
    // В примере - заполняем его с консоли, считаем сумму элементов
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[j + i * cols];

    // выводим массив на экран
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout  << a[j + i * cols] << "\t";
        cout << endl;
    }

    cout << endl;
    // находим сумму
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += a[j + i * cols];

    cout << sum << endl;
    // 3. когда массив больше не нужен, удаляем массив
    delete[] a;
    a = nullptr; //  Не забываем присвоить указателю nullptr
}

