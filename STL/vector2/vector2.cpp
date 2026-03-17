#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
    //system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string town = "";
    vector<string> towns;
    towns.reserve(100); // резервируем память в ветроне на 100 городов
    do
    {
        cout << "Введите название города (или Enter для завершения): ";
        getline(cin, town);
        if (!town.empty())
            towns.push_back(town);
    } while (town != "");
    //towns.resize(2);
    cout << "Список городов(" << towns.size() << "):\n";
    for (auto& t : towns)
        cout << t << endl;
    towns.clear(); // очищаем массив
}
