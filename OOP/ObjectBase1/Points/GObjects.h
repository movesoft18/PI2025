#pragma once
#include <SFML/Graphics.hpp>

//extern sf::RenderWindow window;

class PointBase
{
    // основные поля
    float x, y;
    bool visible;
    // вспомогательные поля
protected:
    sf::Shape* object;
    static sf::RenderWindow* window; // статическое поле (указатель), ссылающееся на окно рендеринга
public:
    // конструктор с параметрами
    PointBase(float x, float y, bool visible);
    // конструктор по умолчанию
    PointBase();
    virtual ~PointBase();
    static void SetRenderWindow(sf::RenderWindow* win)
    {
        window = win;
        // PointBase::window = win; // или так, через имя класса;
    }
protected:
    virtual void Draw(bool show);
public:
    // метод отображения точки
    void Show();
    // метод скрытия точки
    void Hide();
    // метод перемещения точки в новую абсолютную позицию
    void Move(int newX, int newY);
    // метод перемещения точки в новую относительную позицию
    void MoveRel(int dx, int dy);
    // геттеры - получение защищенных полей
    bool GetVisible() const;
    float GetX() const;
    float GetY() const;
    // сеттеры - изменение защищенных полей
    void SetX(float newX);
    void SetY(float newY);
};


class ColorPoint : public PointBase
{
    sf::Color color;

public:
    ColorPoint(float x, float y, sf::Color color, bool visible = false);
    ~ColorPoint() override;
    void setColor(sf::Color newColor);
    sf::Color getColor() const;
protected:
    void Draw(bool show) override;
};

class Circle : public ColorPoint
{
    float radius;
protected:
    void Draw(bool show) override;
public:
    Circle(float x, float y, float radius, sf::Color color = sf::Color::White, bool visible = false);
    ~Circle() override;
    float getRadius() const;
    void setRadius(float newRadius);
};
class FillCircle : public Circle
{
    sf::Color fillColor;
public:
    FillCircle(float x, float y, float radius, 
        sf::Color color = sf::Color::White,sf::Color fillColor = sf::Color::Blue, bool visible = false);
    ~FillCircle() override;
    sf::Color GetColor() const;
    void SetColor(sf::Color newColor);
protected:
    void Draw(bool show) override;
};

class Rectangle : public ColorPoint
{
protected:
    // float x, y; // - координаты верхнего левого угла (унаследованы от PointBase)
    // sf::Color color; // унаследован от ColorPoint;
    // CircleShape object; //унаследован от PointBase - но этот объект нам не нужен в данном классе, взамен него нам нужен RectangleShape

    float width, height; // ширина и высота прямоугольника.
protected:
    void Draw(bool show) override;

public:
    Rectangle(float x, float y, float width, float height, sf::Color color = sf::Color::Black, bool visible = true);

    ~Rectangle() override;
    // Остальные геттеры и сеттеры указывать не будем, их наличие нам неинтересно
    // в рамках обсуждаемой проблемы
};