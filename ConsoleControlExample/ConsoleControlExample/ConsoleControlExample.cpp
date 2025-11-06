#include <iostream>
#include "Windows.h"
using namespace std;

/*
0 - черный
1 - синий
2 - зеленый
3 - голубой (циан)
4 - красный
5 - пурпурный
6 - коричневый
7 - серый
8 - темно-серый
9 - светло-синий
10 - светло-зеленый
11- светло-голубой
12 - светло-красный
13 - светло-пурпурный
14 - желтый
15 - белый

*/
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


void SetTextColor(int color)
{
    color = color & 0b00001111; // 15 0x0f
    // 0b101010111101
    // 0b000000001111
    // 0b000000001101
    CONSOLE_SCREEN_BUFFER_INFO info;
    //  0b11100011
    //& 0b11110000
    //| 0b11100000
    //  0b00001101
    //  0b11101101
    GetConsoleScreenBufferInfo(hStdOut, &info);
    info.wAttributes = info.wAttributes & 0b11110000; // 0xf0
    info.wAttributes = info.wAttributes | color;
    SetConsoleTextAttribute(hStdOut, info.wAttributes);
}

void SetTextBackground(int color)
{
    color = color & 0b00001111; // 15 0x0f
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hStdOut, &info);
    info.wAttributes = info.wAttributes & 0b00001111; // 0x0f
    // 0b00001001 -> 0b10010000
    color = color << 4;
    info.wAttributes = info.wAttributes | color;
    SetConsoleTextAttribute(hStdOut, info.wAttributes);
}

int main()
{
    cout << "Hello, world!\n";
    SetTextColor(10);
    cout << "Hello, world!\n";
    SetTextBackground(8);
    cout << "Hello, world!\n";
}

