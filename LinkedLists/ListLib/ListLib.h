#pragma once

struct ListItem
{
    int id; // идентификатор товара
    char name[30];  // название
    float price; // цена за единицу
    float count; // количество
    ListItem* next; // указатель на следующий элемент
};

// печатает элемент списка в консоли O(1)
void PrintItem(ListItem* item);

// печатает весь список в консоль O(n)
void PrintList(ListItem* firstItem);

// удаление списка O(n)
// указатель на первый элемент передаем по ссылке
void DeleteList(ListItem*& firstItem);

// Функция получения указателя на последний элемент O(n)
// Если функция не изменяет указатель на первый элемент, то передаем его по значению
ListItem* GetLast(ListItem* firstItem);

// добавление элемента в конец списка O(n)
ListItem* AddLast(
    ListItem*& firstItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount);

// добавление элемента после заданного O(1)
ListItem* AddAfter(
    ListItem* prevItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount);

// замечание - передаваемый в функцию указатель на первый элемент списка передается по ссылке, иначе мы не сможем из функции
// обновить значение этой глобальной переменной first
// O(1)
void AddFirst(
    ListItem*& firstItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount);

// Удаление элемента по указателю item.
// параметр returnPrev определяет что функция возвращает, указатель на элемент перед удаленным или после удаленного
ListItem* Delete(ListItem*& firstItem, ListItem* item, bool returnPrev = true);

// поиск элемента по названию продукта O(n)
ListItem* Find(ListItem* firstItem, const char* productName);

// заменяем содержимое указанного элемента новыми данными O(1)
void ReplaceItem(ListItem* item, int newProductId, const char* newProductName, float newProductPrice, float newProductCount);

// Поиск элементов по названию продукта. Функция возвращает указатель на новый созданный
// список, в котором находятся все найденные элементы. Если ничего не найдено, возвращается nullptr
ListItem* FindAll(ListItem* firstItem, const char* productName);

bool SaveListToBinaryFile(ListItem* firstItem, const std::string& filename);

ListItem* LoadListFromBinaryFile(const std::string& filename);

bool SaveListToTextFile(ListItem* firstItem, const std::string& filename);

ListItem* LoadListFromTextFile(const std::string& filename);
