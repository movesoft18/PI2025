#pragma once

namespace crt
{
	constexpr int COLOR_BLACK = 0;
	constexpr int COLOR_BLUE = 1;
	constexpr int COLOR_GREEN = 2;
	constexpr int COLOR_CYAN = 3;
	constexpr int COLOR_RED = 4;
	constexpr int COLOR_MAGENTA = 5;
	constexpr int COLOR_BROWN = 6;
	constexpr int COLOR_GRAY = 7;
	constexpr int COLOR_DARK_GRAY = 8;
	constexpr int COLOR_LIGHT_BLUE = 9;
	constexpr int COLOR_LIGHT_GREEN = 10;
	constexpr int COLOR_LIGHT_CYAN = 11;
	constexpr int COLOR_LIGHT_RED = 12;
	constexpr int COLOR_LIGHT_MAGENTA = 13;
	constexpr int COLOR_YELLOW = 14;
	constexpr int COLOR_WHITE = 15;

	void SetTextColor(int color);
	void SetTextBackground(int color);
	void GotoXY(int x, int y);
	void SetCursorVisibility(bool visible);
	void HideCursor();
	void ShowCursor();
}