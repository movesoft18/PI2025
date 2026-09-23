#pragma once
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;

class PointBase
{
    // основные поля
    float x, y;
    bool visible;
    // вспомогательные поля
protected:
    sf::CircleShape object;
public:
    // конструктор с параметрами
    PointBase(float x, float y, bool visible);
    // конструктор по умолчанию
    PointBase();
    ~PointBase();
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
    void setColor(sf::Color newColor);
    sf::Color getColor() const;
protected:
    virtual void Draw(bool show);
};