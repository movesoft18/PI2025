#include <iostream>
using namespace std;

int divide(int a, int b)
{
    if (b == 0) throw 1; // Деление на 0
    return a / b;
}

double divide(double a, double b)
{
    if (b == 0) throw 1.0; // Деление на 0
    return a / b;
}

float divide(float a, float b)
{
    if (b == 0) throw 'E';//"Деление на 0";
    return a / b;
}

int AnyThrowFunction(int a)
{
    if (a < 0) return 0;
    if (a < 10) throw 2; // Не могу читать файл
    if (a < 100) throw 3; // Не могу записать в файл
    if (a < 1000) throw 4; // Нет подключения к интернету
}

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        double result = divide(4.f, 4.f) +
            divide(2,6) + divide(2.7, 0.001);
        AnyThrowFunction(-400);
        cout << result << endl;
    }
    catch (int e)
    {
        switch (e)
        {
        case 1:
            cout << "Деление на 0\n";
            break;
        case 2:
            cout << "Не могу прочитать файл\n";
            break;
        case 3:
            cout << "Не могу записать файл\n";
            break;
        case 4:
            cout << "Нет соединения с интернетом\n";
            break;
        default:
            cout << "Иная ошибка\n";
        }
    }
    catch (double e)
    {
        cout << "Вещественное деление на 0\n";
    }
    catch (const char e[100])
    {
        cout << e << endl;
    }
    catch (...)
    {
        cout << "Сработал общий обработчик исключений\n";
    }
    cout << "Завершение программы\n";
}

