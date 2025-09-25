#include <iostream>

//void sum()
//{
//    int a, b;
//    std::cout << "Введите 2 числа для суммирования: ";
//    std::cin >> a >> b;
//    auto c = a + b;
//    std::cout << "Сумма = " << c << "\n";
//}

int x, y;


int sub(int a, int b)
{
    if (a < 0 || b < 0)
        return 0;
    int c = a - b;
    return c;
}


int main()
{
    setlocale(LC_ALL, "");
    int result = sub(5, 9);
    //sub(76, 65);

}