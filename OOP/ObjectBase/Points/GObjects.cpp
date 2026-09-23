#include "GObjects.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Points");

PointBase::PointBase(float x, float y, bool visible) 
    : 
    x(x), 
    y(y), 
    visible(visible), 
    object(sf::CircleShape(3))
{
    if (visible) Show();
}
PointBase::PointBase() :PointBase(0, 0, false) 
{ 

}

PointBase::~PointBase()
{
    if (visible) Hide();
}

void PointBase::Draw(bool show)
{
    if (show)
    {
        object.setFillColor(sf::Color::White);
        object.setOutlineColor(sf::Color::White);
    }
    else
    {
        object.setFillColor(sf::Color::Black);
        object.setOutlineColor(sf::Color::Black);
    }
    object.setOutlineThickness(1);
    object.setPosition(x, y);
    window.draw(object); // здесь мы пока поступаем неправильно, обращаясь к глобальной переменной (побочный эффект)
}

// метод отображения точки
void PointBase::Show()
{
    Draw(true);
    visible = true;
}

// метод скрытия точки
void PointBase::Hide()
{
    Draw(false);
    visible = false;
}
// метод перемещения точки в новую абсолютную позицию
void PointBase::Move(int newX, int newY)
{
    bool visibleState = visible;
    Hide();
    x = newX;
    y = newY;
    if (visibleState) Show();
}
// метод перемещения точки в новую относительную позицию
void PointBase::MoveRel(int dx, int dy)
{
    bool visibleState = visible;
    Hide();
    x += dx;
    y += dy;
    if (visibleState) Show();
}

// геттеры - получение защищенных полей
bool PointBase::GetVisible() const
{
    return visible;
}

float PointBase::GetX() const
{
    return x;
}

float PointBase::GetY() const
{
    return y;
}

// сеттеры - изменение защищенных полей
void PointBase::SetX(float newX)
{
    Move(newX, y); // используем готовый метод перемещения точки
}

void PointBase::SetY(float newY)
{
    Move(x, newY); // используем готовый метод перемещения точки
}

ColorPoint::ColorPoint(
    float x, float y, 
    sf::Color color, bool visible):
    PointBase(x, y, false), color(color)
{
    if (visible) Show();
}

void ColorPoint::setColor(sf::Color newColor)
{
    color = newColor;
    if (GetVisible()) Show();
}

sf::Color ColorPoint::getColor() const
{
    return color;
}

void ColorPoint::Draw(bool show)
{
    if (show)
    {
        object.setFillColor(color);
        object.setOutlineColor(color);
    }
    else
    {
        object.setFillColor(sf::Color::Black);
        object.setOutlineColor(sf::Color::Black);
    }
    object.setOutlineThickness(1);
    object.setPosition(GetX(), GetY());
    window.draw(object); // здесь мы пока поступаем неправильно, обращаясь к глобальной переменной (побочный эффект)
}

