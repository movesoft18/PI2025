
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    // здесь код, который присваивает значение переменной size (например с консоли)
    // 1. выделяем память под массив в куче
    int* a = new int[size];
    // 2. Работаем с массивом, в соответствии с вашими задачами.
    // В примере - заполняем его с консоли, считаем сумму элементов
    for (int i = 0; i < size; i++)
        cin >> a[i];
    // выводим массив на экран
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << endl;
    // находим сумму
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i];
    cout << sum << endl;
    // 3. когда массив больше не нужен, удаляем массив
    delete[] a;
    a = nullptr; //  Не забываем присвоить указателю nullptr
}

