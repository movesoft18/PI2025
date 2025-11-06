#include "CrtLib.h"
#include "windows.h"

namespace crt
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	void SetTextColor(int color)
	{
        color = color & 0b00001111;
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(hStdOut, &info);
        info.wAttributes = info.wAttributes & 0b11110000; // 0xf0
        info.wAttributes = info.wAttributes | color;
        SetConsoleTextAttribute(hStdOut, info.wAttributes);
    }
    void SetTextBackground(int color)
    {
        color = color & 0b00001111;
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(hStdOut, &info);
        info.wAttributes = info.wAttributes & 0b00001111;
        info.wAttributes = info.wAttributes | (color << 4);
        SetConsoleTextAttribute(hStdOut, info.wAttributes);
    }
    void GotoXY(int x, int y)
    {
        COORD position{x, y};
        // position.X = x;
        // position.Y = y;
        SetConsoleCursorPosition(hStdOut, position);
    }

    void SetCursorVisibility(bool visible)
    {
        CONSOLE_CURSOR_INFO info;
        GetConsoleCursorInfo(hStdOut, &info);
        info.bVisible = visible;
        SetConsoleCursorInfo(hStdOut, &info);
    }

    void HideCursor()
    {
        SetCursorVisibility(false);
    }

    void ShowCursor()
    {
        SetCursorVisibility(true);
    }

}