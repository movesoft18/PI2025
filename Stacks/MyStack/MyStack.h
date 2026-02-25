#pragma once

template <typename T>
struct StackItem // собственно сам элемент стека
{
    T value; 
    StackItem* next;  // указатель на следующий элемент в списке
};

template <typename T>
bool IsEmpty(StackItem<T>* stack) // функция проверяет пуст ли стек
{
    return stack == nullptr;
}

template <typename T>
void Push(StackItem<T>*& stack, const T& value) // Добавление точки в стек (аналог функции AddFirst линейного списка)
{
    StackItem<T>* item = new StackItem<T>{ value, stack }; // этой строчкой можно заменить следующие 2
    item->next = stack; //корректируем указатель на следующий элемент
    stack = item; // теперь вершина стека указывает на добавленный элемент
}

template <typename T>
T Pop(StackItem<T>*& stack) // извлекает элемент из стека и возвращает его значение
{
    T result; // здесь будет результат
    StackItem<T>* temp; // временная переменная
    result = stack->value; //записываем возвращаемые данные
    temp = stack;   // запоминаем элемент на вершине стека
    stack = temp->next; // перемещаем вершину стека на следующий за извлекаемым элемент
    delete temp;    // освобождаем память, занятую элементом на вершине
    return result; // возвращаем результат
}

