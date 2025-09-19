#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int count = 0;
    int start = 1;
    int sum = 0;
    while (true)
    {
        sum += start;
        start++;
        count++;
        if (sum + start > 1000) break;
    }
    cout << "Сумма " << sum
        << " Получена путем сложения первых " <<
        count << " чисел, начиная с 1\n";
}