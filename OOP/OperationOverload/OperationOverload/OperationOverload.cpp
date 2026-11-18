#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;
class Complex
{
    double a; // действительная часть числа
    double b; // мнимая часть числа
    // a + b * i
public:
    Complex(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    double GetReal() const // добавляем функцию для доступа к скрытым членам
    {
        return a;
    }
    double GetImag() const // добавляем функцию для доступа к скрытым членам
    {
        return b;
    }
    string ToString() const // Преобразует комплексное число в строку для вывода в консоль
    {
        ostringstream osstr;
        char op = b >= 0 ? '+' : '-';
        osstr << a << op << abs(b) << "i";
        return osstr.str();

    }
    void Add(Complex c) // функция сложения 2-х комплексных чисел
    {
        a += c.a;
        b += c.b;
    }
    void Add(double c) // функция сложения комплексного числа с действительным
    {
        a += c;
    }
    void Sub(Complex c) // функция вычитания 2-х комплексных чисел
    {
        a -= c.a;
        b -= c.b;
    }
    void Sub(double c) // функция вычитания комплексного числа с действительным
    {
        a -= c;
    }

    void Mul(Complex c) // функция умножения 2-х комплексных чисел
    {
        a = a * c.a - b * c.b;
        b = (a * c.b + c.a * b);
    }
    void Mul(double c) // функция умножения комплексного числа на действительное
    {
        a *= c;
        b *= c;
    }
    void Div(Complex c) // функция деления 2-х комплексных чисел
    {
        a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
        b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
    }
    void Div(double c) // функция деления комплексного числа на действительное
    {
        this->Mul(1 / c);
    }
    
    Complex operator += (const Complex c) // перегружаем операцию сложения
    {
        this->Add(c);  // вызываем уже созданную функцию Add
        return *this; // возвращаем всегда текущий полученных объект
    }

    Complex operator += (const double c) // перегружаем операцию сложения с числом
    {
        this->Add(c);  // вызываем уже созданную функцию Add
        // в данном случае Add - это перегруженная функция, принимающая параметр double !!!

        return *this; // возвращаем всегда текущий полученных объект
    }

    Complex operator -= (const Complex c)
    {
        this->Sub(c);
        return *this; // возвращаем всегда текущий полученных объект
    }

    Complex operator *= (const Complex c)
    {
        this->Mul(c);
        return *this;
    }

    Complex operator /= (const Complex c)
    {
        this->Div(c);
        return *this;
    }
    Complex operator *= (double c)
    {
        this->Mul(c);
        return *this;
    }

    Complex operator /= (double c)
    {
        this->Div(c);
        return *this;
    }
};

Complex operator + (const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.GetReal() + c2.GetReal(),
        c1.GetImag() + c2.GetImag()
        );
}

Complex operator + (const Complex& c1, double c2)
{
    return Complex(
        c1.GetReal() + c2,
        c1.GetImag()
    );
}

Complex operator + (double c2, const Complex& c1)
{
    return Complex(
        c1.GetReal() + c2,
        c1.GetImag()
    );
}


Complex operator - (const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.GetReal() - c2.GetReal(),
        c1.GetImag() - c2.GetImag()
    );
}

Complex operator - (const Complex& c1, double c2)
{
    return Complex(
        c1.GetReal() - c2,
        c1.GetImag()
    );
}

Complex operator - (double c1, const Complex& c2)
{
    return Complex(
        c1 - c2.GetReal(),
        -c2.GetImag()
    );
}

Complex operator * (const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.GetReal() * c2.GetReal() - c1.GetImag() * c2.GetImag(),
        c1.GetReal() * c2.GetImag() + c2.GetReal() * c1.GetImag()
    );
}

Complex operator * (const Complex& c1, double c2)
{
    return Complex(
        c1.GetReal() * c2,
        c1.GetImag() * c2
    );
}

Complex operator * (double c2, const Complex& c1)
{
    return Complex(
        c1.GetReal() * c2,
        c1.GetImag() * c2
    );
}

// Операции сравнения перегружаем вне класса
bool operator == (const Complex& c1, const Complex& c2) // перегружаем операцию сравнения
{
    return (c1.GetReal() == c2.GetReal() && c1.GetImag() == c2.GetImag());
}

bool operator != (const Complex& c1, const Complex& c2) // перегружаем операцию сравнения
{
    return !(c1 == c2);
}

int main()
{
    Complex x1(2, 4); // 2+4*i определяем 3 комплексных числа
    Complex x2(3, 3); // 3+3*i
    Complex x3(-7, -1); // -7-i
    x3.Add(x1); // прибавляем к числу х3 число х1;
    cout << x3.ToString() << endl; // выводим результат на экран
    x2.Sub(x3); // вычитаем из х2 х3
    cout << x2.ToString() << endl; // выводим результат на экран
    x1.Mul(x2); // умножаем х1 на х2
    cout << x1.ToString() << endl; // выводим результат на экран
    x1.Div(x3); // делим х1 на х3
    cout << x1.ToString() << endl; // выводим результат на экран
    _getch();

    Complex res(0, 0);
    res += x1;
    res += x2;
    res -= x3;
    res *= 5.5;
    //res.Add(x1);
    //res.Add(x2);
    //res.Sub(x3);
    //res.Mul(5.5);
    res = 2 - x1 + 5 + x2 + x3;
    //res.Add(x1).Add(x2).Sub(x3).Mul(5.5);
    res = 5.5 * (x1 + x2 - x3);

    bool isEuqal = res == x1;

    double x = 3.1, y = 9.9, z = -0.8;
    double t = (x + y - z) * 5.5;
}

/*
 тип operator @ (список_параметров-операндов)
{
// тело функции
}
где @ — знак перегружаемой операции (-, +, *  и т.д.),
тип — тип возвращаемого значения.
*/