#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "GObjects.h"
using namespace sf;

// базовый класс
constexpr int count = 100;
int main()
{
    window.setFramerateLimit(5);
    PointBase* points[count]; // массив указателей на объекты
    // генерируем случайные объекты
    for (int i = 0; i < count; i++)
    {
        float x = rand() % 800;
        float y = rand() % 600;
        if (rand() % 2 == 0)
            points[i] = new ColorPoint(x, y, sf::Color::Green, true);
        else
            points[i] = new PointBase(x, y, true);
    }

    // Объект, который, собственно, является главным окном приложения
    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        window.clear();
        for (int i = 0; i < count; i++)
            points[i]->Show();
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                    for (int i = 0; i < count; i++)
                        points[i]->MoveRel(10, 10);
            }
       }
      // Отрисовка окна 
       window.display();
    }
    return 0;
}

