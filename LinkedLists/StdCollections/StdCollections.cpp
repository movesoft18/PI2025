#include <iostream>
#include <list>
#include <vector>
struct ListItem
{
    int id; // идентификатор товара
    char name[30];  // название
    float price; // цена за единицу
    float count; // количество
};

std::list<ListItem> list;

int main()
{
    setlocale(LC_ALL, "");
    list.push_front({1, "Яблоки", 34, 89});
    list.push_front({ 2, "Бананы", 399, 849 });
    list.push_front({ 3, "Груши", 134, 889 });
    for (auto& e : list)
    {
        std::cout << e.id << " " << e.name << " "
            << e.price << " " << e.count << "\n";
    }

    std::vector<ListItem> v;
    v.push_back({ 1, "Яблоки", 34, 89 });
    v.push_back({ 2, "Бананы", 399, 849 });
    v.push_back({ 3, "Груши", 134, 889 });
    for (auto& e : v)
    {
        std::cout << e.id << " " << e.name << " "
            << e.price << " " << e.count << "\n";
    }

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i].id << " " << v[i].name << " "
            << v[i].price << " " << v[i].count << "\n";
    }

    std::vector<int> vint{ 1,2,3,4,5,6,7,8,9,0 };
    std::vector<int> v2 = vint;
    std::cout << vint[5] << " " << vint.at(5) << "\n";
    vint.clear();
    std::vector<std::vector<int>> matrix
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    std::cout << matrix[2][1] << "\n";
}

