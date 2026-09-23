#include <iostream>
using namespace std;

class Point
{
	// --- описание состояния (поля объекта)
	int x, y; // координаты
	int color; // цвет
	bool visibility; // видимость

public:
	Point()
	{
		x = y = color = visibility = 0;
	}
	Point(int x, int y, int color=0, bool vis=false)
	{
		this->x = x;
		this->y = y;
		this->color = color;
		visibility = vis;
		if (visibility) show();
	}
	// ----- описание поведения (методы)

	// сеттеры
	void show()
	{
		// код отображения точки на экране
		visibility = true;
	}
	void hide()
	{
		// код скрытия точки на экране
		visibility = false;
	}
	void setColor(int newColor)
	{
		color = newColor;
		if (visibility) show();
	}
	void move(int newX, int newY);
	void setPosition (int newX, int newY);
	// геттеры
	bool getVisibility() const { return visibility; }
	int getColor() const { return color; }
	int getX() const { return x; }
	int getY() const { return y; }
};

void Point::move(int newX, int newY)
{
	if (visibility) hide();
	x = newX;
	y = newY;
	if (visibility) show();
}

void Point::setPosition(int newX, int newY)
{
	move(newX, newY);
}

int main()
{
	Point p1, p2(0,0,0,false), p4{0,0,10,true};
	//p1.x = 0; p1.y = 0; p1.color = 0; p1.visibility = false;
	p1.move(10, 20);
	//p1.x = -100; p1.y = 0;
	p1.move(20, 40);
	p2.setColor(10);
	p4.show();
	//----
}


