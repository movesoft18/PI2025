#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите n: ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0) continue;
        sum += i;
    }
    cout << "Сумма " << sum << endl;
}