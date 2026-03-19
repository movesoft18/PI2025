#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "include\robot.h"


// Пользовательская функция (здесь студент пишет свой код)
// Эта функция вызывается постоянно в процессе работы робота
// Здесь вы должны проанализировать изображение с камеры робота
// и принять решение о дальнейших действиях (например поворот камеры
// робота. Ваша задача сделать так, чтобы робот спозиционировал центр
// своей камеры на искомом объекте
void studentRobotControl(RobotSimulator& robot) {

    // вот так с ключевым словом static вы можете создавать переменные с сохранением значений
    // в промежутках между вызовами функции
    static int direction = 0;
    static int count = 0;

    // Получение изображения с камеры робота
    cv::Mat view = robot.getVisibleImage();
    cv::Mat display = view.clone();
    cvtColor(display, display, cv::COLOR_BGR2HSV);
    cv::medianBlur(display, display, 15);
    cv::Mat bin;
    cv::inRange(display, cv::Scalar(20, 179, 161), cv::Scalar(34, 255, 233), bin);
    // так вы можете получить копию изображения с камеры для манипуляций с ним
    auto m = cv::moments(bin, true);
    int x = m.m10 / m.m00;
    int y = m.m01 / m.m00;

    // вы можете отображать в отдельном окне любые промежуточные результаты обработки изображений
    cv::imshow("User Robot View", bin);

    // так можно получить шаг поворота камеры в пикселах
    // камера поворачивается на фиксированное значение
    int step = robot.getStepSize();

    // Так можете получить координаты центра изображения с камеры робота
    int centerX = view.cols / 2;
    int centerY = view.rows / 2;
    /*
    // Поэтапное позиционирование на 1 шаг за итерацию
    if (x - centerX > step) robot.moveRight();
    else if (centerX - x > step) robot.moveLeft();
    if (y - centerY > step) robot.moveDown();
    else if (centerY - y > step) robot.moveUp();
    */
    // Мгновенное позиционирование с вычислением кол-ва шагов поворота камеры
    if (x - centerX > step) 
        for (int i = 0; i < (x - centerX) / step; i++) 
            robot.moveRight();
    else if (centerX - x > step) 
        for (int i = 0; i < (centerX - x) / step; i++) 
            robot.moveLeft();
    if (y - centerY > step) 
        for (int i = 0; i < (y - centerY) / step; i++) 
            robot.moveDown();
    else if (centerY - y > step) 
        for (int i = 0; i < (centerY - y) / step; i++) 
            robot.moveUp();
    
    /*/ Демонстрация перемешения камеры - по циклу влево-вверх-вних-вправо
    if (count < 20)
    {
        switch (direction)
        {
        case 0: robot.moveLeft();
            break;
        case 1: robot.moveUp();
            break;
        case 2: robot.moveDown();
            break;
        case 3: robot.moveRight();
            break;
        }
        count++;
    }
    else
    {
        count = 0;
        direction = (direction + 1) % 4;
    }
        */

}

int main() {
    setlocale(LC_ALL, "");
    try {

        // Создаем робота
        int windowWidth = 640;
        int windowHeight = 480;
        RobotSimulator robot("background.png", windowWidth, windowHeight, 4);
        cv::namedWindow("Robot View");
        cv::resizeWindow("Robot View", cv::Size(windowWidth, windowHeight));
        std::cout << "=== Тренажер управления роботом ===" << std::endl;
        std::cout << "Размер полного изображения: "
            << robot.getFullImageSize().width << "x"
            << robot.getFullImageSize().height << std::endl;
        std::cout << "Начальные углы: Pan=" << robot.getPanAngle()
            << ", Tilt=" << robot.getTiltAngle() << std::endl;
        std::cout << "Управление:" << std::endl;
        std::cout << "  w - вверх, s - вниз, a - влево, d - вправо" << std::endl;
        std::cout << "  r - запустить автоматический поиск" << std::endl;
        std::cout << "  q - выход" << std::endl;

        bool autoMode = false;

        while (true) {
            // Показываем текущий вид робота
            cv::Mat robotView = robot.getVisibleImage();
            cv::imshow("Robot View", robotView);

            // Показываем полное изображение с областью видимости
            robot.showFullView();

            // Выводим текущие углы
            std::cout << "\rУглы: Pan=" << robot.getPanAngle()
                << ", Tilt=" << robot.getTiltAngle() << "   " << std::flush;

            if (autoMode) {
                // В автоматическом режиме запускаем пользовательскую функцию
                studentRobotControl(robot);
            }

            // Ручное управление
            char key = cv::waitKey(10);

            switch (key) {
            case 'w': robot.moveUp(); break;
            case 's': robot.moveDown(); break;
            case 'a': robot.moveLeft(); break;
            case 'd': robot.moveRight(); break;
            case 'r':
                autoMode = !autoMode;
                if (autoMode)
                    std::cout << "\nАвтоматический режим включен" << std::endl;
                else
                    std::cout << "\nАвтоматический режим выключен" << std::endl;
                break;
            case 'q': 
                return 0;
            }

        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}