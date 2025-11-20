#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    if (argc < 3)
    {
        cout << "Недостаточно данных.\nФормат запуска ArgSum.exe <число1> <число2>";
        return -1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = a + b;
    cout << a << "+" << b << "=" << c << endl;
}
