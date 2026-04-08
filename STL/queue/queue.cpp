#include <iostream>
#include <queue>

int main()
{
    std::queue<std::string> q;
    setlocale(LC_ALL, "");
    if (q.empty())
        std::cout << "Очередь пуста \n";
    std::cout << q.size() << "\n";
    q.push("Петров");
    q.push("Иванов");
    q.push("Сидоров");
    q.push("Пьянков");
    std::cout << "В очереди " << q.size() << " эл.\n";
    std::cout << "Первый элемент " << q.front() << "\n";
    std::cout << "Последний элемент " << q.back() << "\n";
    while (!q.empty())
    {
        auto name = q.front();
        std::cout << name << "\n";
        q.pop();
    }
    std::cout << "В очереди " << q.size() << " эл.\n";
}