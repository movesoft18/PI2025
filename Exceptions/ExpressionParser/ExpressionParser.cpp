#include <iostream>
#include "..\MyStack\MyStack.h"
#include <sstream>
using namespace std;

StackItem<double>* stack = nullptr;

double Compute(const string& str)
{
    double f, d;
    string part; // здесь будем хранить считанное число из строки или знак операции
    istringstream s(str); // используем строковый поток в памяти для удобства чтения
    // значений из строки выражения. Он позволит нам автоматически
    // выделять числа и операции
    while (s >> part) // в цикле считываем очередной элемент строки
    {
        int len = part.length(); // вычисляем длину считанного элемента
        if (len == 1) // если она = 1, то, возможно это знак операции
        {
            char e = part[0]; //берем этот символ и сравниваем с операциями
            switch (e)
            {
            case '+': // если это сложение, то извлекаем из стека 2 числа, складываем их и помещаем обратно в стек их сумму
                Push(stack,Pop(stack) + Pop(stack));
                continue;
            case '-': // если это вычитание, то извлекаем из стека 2 числа, вычитаем их и помещаем результат в стек
                Push(stack ,-Pop(stack) + Pop(stack)); // поскольку на вершине второй операнд, который нам нужно вычесть, то мы меняем
                continue;                         // его знак на противоположный и складываем со следующим элементом на стеке
            case '*':
                Push(stack,Pop(stack) * Pop(stack)); // умножение - по образу сложения, только операция другая
                continue;
            case '/':  //а деление по принципу вычитания )))
                f = Pop(stack);
                d = Pop(stack);
                Push(stack, d / f);
                continue;
            case '^':  //а деление по принципу вычитания )))
                f = Pop(stack);
                d = Pop(stack);
                Push(stack, pow(d, f));
                continue;
            case '@':  //а деление по принципу вычитания )))
                f = Pop(stack);
                Push(stack, sqrt(f));
                continue;
            }
        }
        size_t error;
        double num;
        try
        {
            num = stod(part, &error); // а если длина считанной части строки > 1, то это операнд, преобразовываем его
        }
        catch (std::invalid_argument e)
        {
            throw std::invalid_argument(
                "Синтаксическая ошибка в выражении '" + str + "' "+
                + "неверный формат числа " + part
            );
        }
        if (error < part.length())
        {
            throw std::invalid_argument(
                "Синтаксическая ошибка в выражении '" + str + "' " +
                +"неверный формат числа " + part);
        }
        // в число double
        Push(stack,num);   // и помещаем в стек
    }
    return Pop(stack); // на вершине стека в конце будет результат вычислений, возвращаем его
}

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        cout << Compute("10 20 + 3 * 2 / 1 -") << endl; // (10+20)*3/2-1 = 44
        cout << Compute("7 2 3 * -") << endl; // 7-(2*3) = 1
        cout << Compute("7 2 ^ @") << endl;
    }
    catch (std::invalid_argument e)
    {
        cout << e.what() << endl;
    }
    catch (std::logic_error e)
    {
        cout << e.what() << endl;
    }
}

