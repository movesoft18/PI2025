#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    int age = 0;
    do
    {
        cout << "Введите ваш возраст (5-100 лет): ";
        cin >> age;
        if (age < 5 || age > 100)
            cout << "Некорректный возраст, повторите ввод!\n";
    } while (age < 5 || age > 100);
    cout << "Ваш возраст " << age << " лет." << endl;
}