#include <iostream>
#include "..\MyStack\MyStack.h"
using namespace std;

StackItem<char>* stack = nullptr;

// функция проверяет правильность расстановки скобок () и [] в выражении str
// возвращает true, если в выражении скобки расставлены корректно и false в противном случае

void ClearStack(StackItem<char>* stack)
{
    while (!IsEmpty(stack)) Pop(stack);
}

bool IsCorrectString(const string& str)
{
    for (int i = 0; i < str.length(); i++) //посимвольно пробегаем по всей строке
    {
        char e = str[i]; // помещаем в е очередной символ из строки
        switch (e) // и проверяем его
        {
        case '[': //если это открывающая скобка
        case '(':
        case '{':
            Push(stack, e); // то помещаем ее символ в стек
            break;

        case ']': // если это открывающая квадратная скобка
            if (IsEmpty(stack)) // проверяем пуст ли стек, и если стек пуст, значит данная скобка лишняя
                return false; // ей не соответствует ни одна открывающая, возвращаем false
            if (Pop(stack) != '[')  // если в стеке есть символы, извлекаем его и сравниваем с открывающей скобкой
            {
                ClearStack(stack); // чистим стек перед окончанием (если он не пустой)
                return false; // если символ другой, то нарушен порядок следования круглых и квадратных скобок
            }
            break;

        case ')':    // те же действия. что и выше, но уже с круглыми скобками
            if (IsEmpty(stack))
                return false;
            if (Pop(stack) != '(')
            {
                ClearStack(stack); // чистим стек перед окончанием (если он не пустой)
                return false;
            }
            break;
        case '}':    // те же действия. что и выше, но уже с круглыми скобками
            if (IsEmpty(stack))
                return false;
            if (Pop(stack) != '{')
            {
                ClearStack(stack); // чистим стек перед окончанием (если он не пустой)
                return false;
            }
            break;
        }
    }
    bool result = IsEmpty(stack); // если строка закончилась, а стек не пуст, значить открывающих скобок больше, ошибка
    while (!IsEmpty(stack)) Pop(stack); // чистим стек перед окончанием (если он не пустой)
    return result;
}
int main()
{
    cout << IsCorrectString("2*(6x+1)-[(4-6)*(3+x)]{^2} -(((3-z)-z)*x)") << endl; // правильное выражение
    cout << IsCorrectString("2*(6x+1))-[(4-6)*(3+x)]^2 -(((3-z)-z)*x)") << endl; // неправильное лишняя ) скобка
    cout << IsCorrectString("2*(6x+1)-[(4-6)*(3+x)]^2 -(((3-z)-z)*x]") << endl; // неправильное нарушен порядок скобок, последняя должна быть ), а по факту ]
    cout << IsCorrectString("2*(6x+1)-[(4-6)*(3+x)]^2 -[((3-z)-z)*x)") << endl;  //неправильное нарушен порядок скобок, последняя должна быть ], а по факту )
    cin.get();
}

