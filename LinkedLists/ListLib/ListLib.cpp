#include <iostream>
#include "ListLib.h"
#include <fstream>

// печатает элемент списка в консоли O(1)
void PrintItem(ListItem* item)
{
    if (item == nullptr) return; // проверяем корректность указателя
    std::cout << "Ид товара: " << item->id << std::endl; // далее выводим данные в консоль
    std::cout << "Название: " << item->name << std::endl;
    std::cout << "Цена: " << item->price << " руб." << std::endl;
    std::cout << "Количество: " << item->count << " кг." << std::endl;
    std::cout << std::endl;
}

// печатает весь список в консоль O(n)
void PrintList(ListItem* firstItem)
{
    auto temp = firstItem; // начинаем с первого элемента
    while (temp != nullptr) // перебираем весь список
    {
        PrintItem(temp); // печатаем очередной элемент ранее созданной функцией
        temp = temp->next; // перемещаемся к следующему элементу
    }
}

// удаление списка O(n)
// указатель на первый элемент передаем по ссылке
void DeleteList(ListItem*& firstItem)
{
    auto temp = firstItem; // вспомогательный указатель, который будет указывать на удаляемый элемент
    // в то время, как firstItem мы будем продвигать вперед на следующие элемент
    while (firstItem != nullptr) // пока не достигли конца списка
    {
        firstItem = firstItem->next; // передвигаем "курсор" на следующий элемент
        delete temp;    // удаляем текущий
        temp = firstItem; // обновляем temp, так чтобы он указывал на следующий
    } // в конце цикла firstItem будет равен nullptr
}

// Функция получения указателя на последний элемент O(n)
// Если функция не изменяет указатель на первый элемент, то передаем его по значению
ListItem* GetLast(ListItem* firstItem)
{
    if (firstItem == nullptr) return nullptr; // если список пуст, то вернем пустой указатель
    auto temp = firstItem; // временной переменной присваиваем указатель на первый элемент
    while (temp->next != nullptr) // пока ее поле next не пустой указатель (если пустой, то мы достигли последнего элемента!)
    {
        // запомните это присваивание - это переход к следующему в списке элементу
        temp = temp->next;  // перемещаемся к следующему элементу списка
    }
    return temp; // возвращаем указатель на последний элемент
}

// замечание - передаваемый в функцию указатель на первый элемент списка передается по ссылке, иначе мы не сможем из функции
// обновить значение этой глобальной переменной first
// O(1)
void AddFirst(
    ListItem*& firstItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount)
{
    ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
    temp->id = productId;   // присваиваем полям элемента нужные значения
    strcpy_s(temp->name, productName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
    temp->price = productPrice; // присваиваем полям элемента нужные значения
    temp->count = productCount; // присваиваем полям элемента нужные значения
    temp->next = firstItem; // нам нужно встроить элемент в начало списка, поэтому
    // указатель next настраиваем таким образом, чтобы он указывал на элемент
    // который ранее был первым (на него указывает first)
    firstItem = temp;       // а теперь делаем, чтобы first указывал на наш созданный элемент
}

// добавление элемента в конец списка O(n)
ListItem* AddLast(
    ListItem*& firstItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount)
{
    if (firstItem == nullptr) // если список пуст, вызовем функцию добавления в начало списка
    {
        AddFirst(firstItem, productId, productName, productPrice, productCount);
        return firstItem;
    }
    ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
    temp->id = productId;   // присваиваем полям элемента нужные значения
    strcpy_s(temp->name, productName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
    temp->price = productPrice; // присваиваем полям элемента нужные значения
    temp->count = productCount; // присваиваем полям элемента нужные значения
    temp->next = nullptr; // нам нужно встроить элемент в конец списка, поэтому
    // указатель next настраиваем таким образом, чтобы он был пустым
    // который ранее был первым (на него указывает first)
    GetLast(firstItem)->next = temp;    // а теперь делаем, чтобы элемент, который до этого был последним
    // (а его мы получаем с помощью уже созданной GetLast)
    // ссылался на наш новый элемент
    return temp; // возвращаем указатель на последний элемент
}

// добавление элемента после заданного O(1)
ListItem* AddAfter(
    ListItem* prevItem,
    int productId,
    const char* productName,
    float productPrice,
    float productCount)
{
    if (prevItem == nullptr) return nullptr; // если указатель на предыдущий является пустым, то ничего не добавляем
    ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
    temp->id = productId;   // присваиваем полям элемента нужные значения
    strcpy_s(temp->name, productName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
    temp->price = productPrice; // присваиваем полям элемента нужные значения
    temp->count = productCount; // присваиваем полям элемента нужные значения
    temp->next = prevItem->next; // нам нужно встроить элемент список, поэтому
    // указатель next настраиваем таким образом, чтобы он указывал на элемент,
    // на который указывал указатель prevItem
    prevItem->next = temp;    // а теперь делаем, чтобы на наш элемент указывал prevItem
    return temp; // возвращаем указатель созданный элемент
}

// Удаление элемента по указателю item.
// параметр returnPrev определяет что функция возвращает, указатель на элемент перед удаленным или после удаленного
ListItem* Delete(
    ListItem*& firstItem,
    ListItem* item, 
    bool returnPrev)
{
    if (firstItem == nullptr) return nullptr;
    auto temp = firstItem;
    if (firstItem == item)  // если указатель на начало списка и на удаляемый элемент совпадают, то
    {                       // частный случай - удаляем первый в списке элемент
        firstItem = firstItem->next; // правим указатель на первый элемент таким образом, чтобы он указывал на следующий в списке
        delete temp; // удаляем первый элемент
        if (returnPrev) // если надо вернуть указатель на предыдущий элемент
            return nullptr; // его нет, возвращаем nullptr
        else
            return firstItem; // иначе возвращаем первый элемент
    }
    // если удаляемый элемент не первый в списке
    while (temp->next != item && temp->next != nullptr) // ищем элемент, предшествующий удаляемому
    {
        temp = temp->next; // передвижение к следующему (ПОМНИТЕ?)
    }
    // если в итоге просмотрели весь список и не нашли удаляемый элемент
    // попался некорректный указатель, возвращаем nullptr
    if (temp->next == nullptr) return nullptr;
    auto removableItem = temp->next; // иначе обозначили удаляемый элемент, он следующий по списку
    temp->next = removableItem->next;   // исправляем указатель предыдущего элемента, чтобы он указывал
    // на элемент за удаляемым
    delete removableItem;   // удаляем элемент
    if (returnPrev) // если функция должна вернуть указатель на предшествующий удаляемому элемент
        return temp;        // возвращаем его
    else
        return temp->next; // иначе возвращаем указатель на следующий за удаленным элемент
}

// поиск элемента по названию продукта O(n)
ListItem* Find(ListItem* firstItem, const char* productName)
{
    auto temp = firstItem; // начинаем с указанного элемента
    while (temp != nullptr) // перебираем весь список
    {
        if (strcmp(temp->name, productName) == 0) // если название продукта подходит
        {
            return temp; // возвращаем указатель на найденный элемент
        }
        temp = temp->next; // переходим к следующему элементу
    }
    return nullptr; // если ничего не нашли - возвращаем nullptr
}

// заменяем содержимое указанного элемента новыми данными
void ReplaceItem(ListItem* item, 
    int newProductId, 
    const char* newProductName, 
    float newProductPrice, 
    float newProductCount)
{
    if (item != nullptr) // если указатель корректен
    {
        item->id = newProductId;   // присваиваем полям элемента нужные значения
        strcpy_s(item->name, newProductName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
        item->price = newProductPrice; // присваиваем полям элемента нужные значения
        item->count = newProductCount; // присваиваем полям элемента нужные значения
    }
}

// Поиск элементов по названию продукта. Функция возвращает указатель на новый созданный
// список, в котором находятся все найденные элементы. Если ничего не найдено, возвращается nullptr
ListItem* FindAll(
    ListItem* firstItem, 
    const char* productName)
{
    auto temp = firstItem; // начинаем с указанного элемента
    ListItem* foundedElements = nullptr;
    while (temp != nullptr) // перебираем весь список
    {
        if (strcmp(temp->name, productName) == 0) // если название продукта подходит
        {
            // если нашли элемент, то добавляем его в новый список
            AddFirst(foundedElements, temp->id, temp->name, 
                temp->price, temp->count);
        }
        temp = temp->next; // переходим к следующему элементу
    }
    return foundedElements; // возвращаем указатель на новый список
}

bool SaveListToBinaryFile(ListItem* firstItem, const std::string& filename)
{
    if (firstItem == nullptr) return false;
    std::ofstream f(filename, std::ios::binary);
    if (!f) return false;
    auto temp = firstItem;
    while (temp != nullptr)
    {
        f.write((char*)temp, sizeof(ListItem));
        temp = temp->next;
    }
    bool result = f.good();
    f.close();
    return result;
}

ListItem* LoadListFromBinaryFile(const std::string& filename)
{
    std::ifstream f(filename, std::ios::binary);
    if (!f) return nullptr;
    ListItem item;
    ListItem* first = nullptr;
    while (f.read((char*)&item, sizeof(ListItem)))
    {
        AddLast(first, item.id, item.name, item.price, item.count);
    }
    f.close();
    return first;
}
