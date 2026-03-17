#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class RobotSimulator {
private:
    cv::Mat fullImage;           // Полное изображение с шарами
    cv::Mat visibleArea;         // Видимая область (то, что "видит" робот)

    // Параметры камеры/окна обзора
    int windowWidth;             // Ширина окна обзора
    int windowHeight;            // Высота окна обзора
    int currentX;                // Текущая позиция X центра окна
    int currentY;                // Текущая позиция Y центра окна

    // Углы поворота камеры (в градусах)
    double panAngle;             // Горизонтальный угол (влево-вправо)
    double tiltAngle;            // Вертикальный угол (вверх-вниз)

    // Шаг перемещения
    int moveStep;

public:
    // Конструктор
    RobotSimulator(const std::string& imagePath, int width = 200, int height = 150, int step = 20);

    // Обновление видимой области
    void updateVisibleArea();

    // Получить текущее видимое изображение
    cv::Mat getVisibleImage();

    // Движение камеры
    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight(); 

    // Получить текущие углы
    double getPanAngle() const; 
    double getTiltAngle() const;
    int getStepSize() const;

    // Получить размеры полного изображения
    cv::Size getFullImageSize() const;

    // Показать полное изображение с отмеченной областью видимости
    void showFullView();

    // Установить размер окна
    void setWindowSize(int width, int height);
};

