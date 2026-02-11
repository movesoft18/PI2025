#include <iostream>
using namespace std;

struct ListItem
{
    int id; // идентификатор товара
    char name[30];  // название
    float price; // цена за единицу
    float count; // количество
    ListItem* next; // указатель на следующий элемент
};

ListItem* first = nullptr;

// печатает элемент списка в консоли O(1)
void PrintItem(ListItem* item)
{
    if (item == nullptr) return; // проверяем корректность указателя
    cout << "Ид товара: " << item->id << endl; // далее выводим данные в консоль
    cout << "Название: " << item->name << endl;
    cout << "Цена: " << item->price << " руб." << endl;
    cout << "Количество: " << item->count << " кг." << endl;
    cout << endl;
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

int main()
{
    setlocale(LC_ALL, "");
    auto newItem = AddLast(first, 1, "Яблоки", 126, 235.8);
    newItem = AddAfter(newItem, 2, "Бананы", 157, 23);
    newItem = AddAfter(newItem, 3, "Апельсины", 161.99, 2.8);
    //AddLast(first, 2, "Бананы", 157, 23);
    //AddLast(first, 3, "Апельсины", 161.99, 2.8);
    //PrintItem(GetLast(first));
    PrintList(first);
    DeleteList(first);
}
