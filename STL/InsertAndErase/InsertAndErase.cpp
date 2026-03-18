#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> v2{ -10, -20, -30, -40 };
    v1.push_back(11); //{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11};
    v1.insert(v1.begin(), -1); // {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11};
    v1.insert(v1.begin() + 4, 100); // вставка числа в позицию 4
    v1.insert(v1.begin() + 4, { 200,300,400 }); // вставка группы чисел в пизицию 4
    for (auto e : v1) cout << e << ' ';
    cout << endl;
    v1.insert(v1.begin(), v2.begin(), v2.begin()+2); // вставит в начало вектора v1 элементы вектора v2 -10 и -20
    v1.insert(v1.end(), 1000); // вставка в конец, аналог push_back
    for (auto e : v1) cout << e << ' ';
    cout << endl;
    v2.erase(v2.begin() + 1); // удаляем 2-й элемент v2 (-20)
    for (auto e : v2) cout << e << ' ';
    cout << endl;
    v1.erase(v1.begin(), v1.begin() + 5); // удаляем элементы v1 от первого до пятого (-10 -20 -1 1 2)
    for (auto e : v1) cout << e << ' ';
    cout << endl;

    vector<string> names{
        "Петров",
        "Иванов",
        "Сидоров",
        "Петров",
        "Сибиряков",
    };
    // так работать не будет
    for (auto i = names.begin(); i != names.end(); i++)
    {
        if (*i == "Петров")
            names.erase(i); // после удаления элемента итератор i становится недействительным
    }
    for (auto e : names) cout << e << ' ';
    cout << endl;

}

