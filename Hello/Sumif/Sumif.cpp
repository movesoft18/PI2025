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
    
    float x = -6.7;
    float y = x / 2;
    if (x >= -10)

    {

        x = x + 1;

        y = x + 2;

    }
    else
    {
        x = x - 1;
        y = y - 1;
    }

}