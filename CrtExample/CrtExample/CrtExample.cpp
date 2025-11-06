#include <iostream>
#include "CrtLib.h"
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace crt;

int main()
{
    setlocale(LC_ALL, "");
    GotoXY(15, 5);
    SetTextColor(COLOR_GREEN);
    cout << "Hello World!\n";
    Sleep(1000);
    if (_kbhit())
    {
        char s = _getch();
        SetTextBackground(COLOR_DARK_GRAY);
        cout << "Нажата клавиша " << s << endl;
    }
    else
    {
        cout << "Завершение программы. Кнопки не нажимались\n";
    }

}

