#include <iostream>
#include <stack>

int main()
{
    setlocale(LC_ALL, "");
    std::stack<std::string> st;
    if (st.empty())
        std::cout << "Стек пуст \n";
    std::cout << st.size() << "\n";
    st.push("Петров");
    st.push("Иванов");
    st.push("Сидоров");
    st.push("Пьянков");
    std::cout << "В стеке " << st.size() << " эл.\n";
    while (!st.empty())
    {
        auto name = st.top();
        std::cout << name << "\n";
        st.pop();
    }
    std::cout << "В стеке " << st.size() << " эл.\n";
}

