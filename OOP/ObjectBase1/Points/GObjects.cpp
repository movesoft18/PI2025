#include "GObjects.h"

//sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Points");

PointBase::PointBase(float x, float y, bool visible) 
    : 
    x(x), 
    y(y), 
    visible(visible), 
    object(nullptr)
{
    if (visible) Show();
}
PointBase::PointBase() :PointBase(0, 0, false) 
{ 

}

PointBase::~PointBase()
{
    // если объект создан, удаляем его из динамической памяти и присваиваем указателю nullptr
    if (object)
    {
        if (visible) Hide();
        delete object;
        object == nullptr;
    }
}

void PointBase::Draw(bool show)
{
    if (!window) return;
    if (object == nullptr)
        // для данного класса это будет CircleShape
        object = new sf::CircleShape(3);
    // дальше для PointBase все стандартно
    if (show)
    {
        object->setFillColor(sf::Color::White);
        object->setOutlineColor(sf::Color::White);
    }
    else
    {
        object->setFillColor(sf::Color::Black);
        object->setOutlineColor(sf::Color::Black);
    }
    object->setOutlineThickness(1);
    object->setPosition(x, y);
    window->draw(*object); 
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

ColorPoint::~ColorPoint()
{
    if (GetVisible()) Hide();
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
    if (!window) return;
    if (object == nullptr)
        // для данного класса это будет CircleShape
        object = new sf::CircleShape(3);
    if (show)
    {
        object->setFillColor(color);
        object->setOutlineColor(color);
    }
    else
    {
        object->setFillColor(sf::Color::Black);
        object->setOutlineColor(sf::Color::Black);
    }
    object->setOutlineThickness(1);
    object->setPosition(GetX(), GetY());
    window->draw(*object); // здесь мы пока поступаем неправильно, обращаясь к глобальной переменной (побочный эффект)
}

Circle::Circle(float x, float y, float radius,
    sf::Color color, bool visible):
    ColorPoint(x, y, color, false), radius(radius)
{
    if (visible) Show();
}

Circle::~Circle()
{
    if (GetVisible()) Hide();
}

float Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(float newRadius)
{
    radius = newRadius;
    if (GetVisible()) Show();
}

void Circle::Draw(bool show)
{
    if (!window) return;
    if (object == nullptr)
        // для данного класса это будет CircleShape
        object = new sf::CircleShape(radius);
    // устанавливаем прозрачный цвет фона
    object->setFillColor(sf::Color::Transparent);
    // задаем радиус
    //object->setRadius(radius);  // так сделать не получится, поскольку Shape не содержит методов, устанавливающих радиус
        // поэтому мы должны обращаться не к методам класса Shape, а к методам CircleShape
        // для этого используем даункаст Shape* к CircleShape*
        // это будет безопасно, т.к. мы на 100% уверены, что для данного класса object ссылается на CircleShape, т.к. несколькими
        // строками кода мы его и создали.
    sf::CircleShape* circle = static_cast<sf::CircleShape*>(object); // даункаст, дальше везде используем circle    
    // устанавливаем прозрачный цвет фона
    circle->setFillColor(sf::Color::Transparent);
    // устанавливаем радиус
    circle->setRadius(radius);
    if (show)
    {
        circle->setOutlineColor(getColor());
    }
    else
    {
        circle->setOutlineColor(sf::Color::Black);
    }
    circle->setOutlineThickness(1);
    circle->setPosition(GetX(), GetY());
    window->draw(*object);
}



FillCircle::FillCircle(float x, float y, float radius,
    sf::Color color,sf::Color fillColor, bool visible) :
    Circle(x,y,radius, color, false),
    fillColor(fillColor)
{
    if (visible) Show();
}

FillCircle::~FillCircle()
{
    if (GetVisible()) Hide();
}

sf::Color FillCircle::GetColor() const
{
    return fillColor;
}

void FillCircle::SetColor(sf::Color newColor) 
{
    fillColor = newColor;
    if (GetVisible()) Show();
}

void FillCircle::Draw(bool show)
{
    if (object == nullptr)
        // для данного класса это будет CircleShape
        object = new sf::CircleShape(getRadius());
    // устанавливаем прозрачный цвет фона
    object->setFillColor(sf::Color::Transparent);
    // задаем радиус
    //object->setRadius(radius);  // так сделать не получится, поскольку Shape не содержит методов, устанавливающих радиус
        // поэтому мы должны обращаться не к методам класса Shape, а к методам CircleShape
        // для этого используем даункаст Shape* к CircleShape*
        // это будет безопасно, т.к. мы на 100% уверены, что для данного класса object ссылается на CircleShape, т.к. несколькими
        // строками кода мы его и создали.
    sf::CircleShape* circle = static_cast<sf::CircleShape*>(object); // даункаст, дальше везде используем circle    
    if (!window) return;

    //object.setFillColor(sf::Color::Transparent);
    // устанавливаем радиус
    circle->setRadius(getRadius());
    if (show)
    {
        circle->setOutlineColor(getColor());
        circle->setFillColor(fillColor);
    }
    else
    {
        circle->setOutlineColor(sf::Color::Black);
        circle->setFillColor(sf::Color::Black);
    }
    circle->setOutlineThickness(1);
    circle->setPosition(GetX(), GetY());
    window->draw(*object);
}

void Rectangle::Draw(bool show) 
{
    if (!window) return;
    // А вот в этом классе создаем другой объект - RectangleShape
    if (object == nullptr)
        // для данного класса это будет RectangleShape
        object = new sf::RectangleShape(sf::Vector2f(width, height));
    sf::RectangleShape* rect = static_cast<sf::RectangleShape*>(object); // даункаст, дальше везде используем rect
    // устанавливаем прозрачный цвет фона
    rect->setFillColor(sf::Color::Transparent);
    // задаем радиус
    if (show)
    {
        rect->setOutlineColor(getColor());
    }
    else
    {
        rect->setOutlineColor(sf::Color::Black);
    }
    rect->setOutlineThickness(1);
    rect->setPosition(GetX(), GetY());
    window->draw(*object);
}

Rectangle::Rectangle(float x, float y, float width, float height, sf::Color color, bool visible) :
    ColorPoint(x, y, color, false), 
    width(width), 
    height(height) 
{
    if (visible) Show();
}

Rectangle::~Rectangle()
{
    if (GetVisible()) Hide();
}

// инициализация статического поля
sf::RenderWindow* PointBase::window = nullptr;