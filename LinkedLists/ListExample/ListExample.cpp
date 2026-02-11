#include <iostream>
#include "ListLib.h"
using namespace std;

ListItem* first = nullptr;

int main()
{
    setlocale(LC_ALL, "");
    AddFirst(first, 1, "Яблоки", 93.99, 100); // добавляем в начало первый элемент Яблоки
    AddFirst(first, 3, "Бананы", 72, 90);   // добавляем в начало второй элемент Бананы, бананы стают первыми, Яблоки вторыми
    auto oranges = AddLast(first, 4, "Апельсины", 89.99, 50.7); // добавляем в конец Апельсины, oranges - указатель на апельсины
    auto mandarine = AddLast(first, 5, "Мандарины", 189.99, 147);// добавляем в конец Мандарины
    auto kiwi = AddAfter(oranges, 2, "Киви", 129.99, 17); // вставить после апельсинов
    auto persimmon = AddAfter(kiwi, 6, "Хурма", 159.99, 27); // вставить после киви
    auto i2 = Delete(first, kiwi); // удаляем киви
    auto bananas2 = AddLast(first, 9, "Бананы", 160, 43);
    PrintList(first);

    auto m = Find(first, "Бананы");
    if (m == nullptr) cout << "Такой товар не найден!" << endl;
    while (m != nullptr)
    {
        PrintItem(m);
        m = Find(m->next, "Бананы");
    }
    m = Find(first, "Хурма");
    if (m != nullptr)
    {
        cout << "---------------\n";
        PrintItem(m);
        ReplaceItem(m, m->id, m->name, m->price * 2, m->count);
        PrintItem(m);
    }
    auto bananas = FindAll(first, "Бананы");
    if (bananas != nullptr)
    {
        cout << "Найдено:\n";
        PrintList(bananas);
        DeleteList(bananas);
    }
    else 
        cout << "Бананы не найдены:\n";
    if (SaveListToBinaryFile(first, "goods.bin"))
        cout << "Список успешно сохранен\n";
    else
        cout << "Ошибка сохраниения списка\n";
    DeleteList(first);
    first = LoadListFromBinaryFile("goods.bin");
    PrintList(first);
}

