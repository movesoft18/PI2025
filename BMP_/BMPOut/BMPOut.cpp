#include <iostream>
#include "SFML\Graphics.hpp"
#include <fstream>
using namespace std;
using namespace sf;

#pragma pack(push, 1)
struct BitmapFileHeader
{
    char  bfType[2]; // содержит BM
    uint32_t bfSize; // размер файла в байтах
    uint16_t  bfReserved1; // не используется
    uint16_t  bfReserved2; // не используется
    uint32_t bfOffBits; // смещение до растровых данных
};

struct BitmapInfoHeader
{
    uint32_t biSize;            // должно быть 40
    int32_t biWidth;            // ширина
    int32_t biHeight;           // высота
    uint16_t biPlanes;          // всегда 1
    uint16_t biBitCount;        // число бит на пиксель 
    // 1 - 2 цвета,
    // 4 - 16 цветов,
    // 8 - 256 цветов,
    // 24 - 16777216 цветов
    uint32_t biCompression;     // Сжато ли изображение 0 - не сжато
    uint32_t biSizeImage;       // содержит размер растрового изображения в байтах
    int32_t biXPelsPerMeter;    // разрешение по х
    int32_t biYPelsPerMeter;    // разрешение по у
    uint32_t biClrUsed;         // кол-во используемых цветов
    uint32_t biClrImportant;    // кол-во важных цветов
};

struct RGBQuad
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;
};

#pragma pack(pop)

RenderWindow window(VideoMode(1024, 768), "BMP Test");

void Show24BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)
{
    // эту функцию вы должны будете реализовать сами
}

void Show8BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)
{
    // эту функцию вы должны будете реализовать сами
}

// вывод 16-ти цветного изображения. Каждая точка кодируется 4-мя битами. 1 байт содержит данные о 2-х
// соседних точках изображения
// функция принимает ссылки на заголовки файла и ссылку на файловый поток с растровыми данными
void Show4BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)
{
    CircleShape point(1.f);// объявляем объект SFML - окружность дияметром 1, т.к. объекта-точки в SFML нет
    // вычисляем количество используемых цветов. Если biClrUsed == 0, используются все доступные цвета
    int colors = (BIH.biClrUsed == 0) ? 16 : BIH.biClrUsed;
    RGBQuad* palette = new RGBQuad[sizeof(RGBQuad) * colors];// выделяем память для палитры. Количество элементов равно количесвту цветов
    f.read((char*)palette, sizeof(RGBQuad) * colors);// читаем палитру. Она иет сразу за BitmapInfoHeader
    f.seekg(BFH.bfOffBits);// позиционируем указатель файла на начало растровых данных
    int rowLength = BIH.biWidth / 2 + BIH.biWidth % 2;// вычисляем длину строки изображения в байтах
    if (rowLength % 4 != 0) // она должна быть кратна 4-м.
        rowLength = rowLength / 4 * 4 + 4;
    unsigned char* bits = new unsigned char[rowLength];// выделяем память для растровых данных
    for (int y = BIH.biHeight - 1; y >= 0; y--) // цикл вывода строк. Строки располагаются снизу-вверх
    {
        f.read((char*)bits, rowLength); // для каждой строки читаем растровые данные в память
        for (int x = 0; x < BIH.biWidth; x++) // цикл вывода пикселей строки
        {
            // вычисляем индекс цвета colorIndex
            // индекс цвета может располагаться в 4-х старших или 4-х младших битах проверемого байта
            // проверяемый байт выичляется x/2, где х - координата х выводимого пикселя
            // если х кратен 2-м, то берем старшие 4 бита, если не кратен, то младшие 4 бита.
            //старшие 4 бита берутся путем битового сдвига байта вправо на 4 бита (остаются только старшие 4 бита, младшие исчезают за границами разрядной сетки)
            // младшие 4 бита можно получить путем побитовой операции И нашего байта с маской 0x0f (00001111)
            unsigned char colorIndex = (x % 2 == 0) ? (bits[x / 2] >> 4) : (bits[x / 2] & 0x0f);
            // выбираем из палитрыы элементы с вычисленным индексом и помещаем их в переменные blue, green, red
            unsigned char blue = palette[colorIndex].blue;
            unsigned char green = palette[colorIndex].green;
            unsigned char red = palette[colorIndex].red;
            point.setFillColor(Color(red, green, blue));// задаем цвет нашей единичной окружности
            point.setPosition(x, y); // позиционируем окружность в нужную точку окна
            window.draw(point); // рисуем точку
        }
    }
    delete[] bits; // освобождаем память, выделенную под строку растра
    delete[] palette; // освобождаем память, выделенную для палитры
}

// вывод монохромного изображения. Каждый бит растровых данных кодирует одну точку
// функция принимает ссылки на заголовки файла и ссылку на файловый поток с растровыми данными
void Show1BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)
{
    CircleShape point(1.f); // объявляем объект SFML - окружность диаметром 1, т.к. объекта-точки в SFML нет
    // вычисляем количество используемых цветов. Если biClrUsed == 0, используются все доступные цвета
    int colors = (BIH.biClrUsed == 0) ? 2 : BIH.biClrUsed;
    RGBQuad* palette = new RGBQuad[sizeof(RGBQuad) * colors]; // выделяем память для палитры. Количество элементов равно количесвту цветов
    f.read((char*)palette, sizeof(RGBQuad) * colors); // читаем палитру. Она иет сразу за BitmapInfoHeader
    f.seekg(BFH.bfOffBits); // позиционируем указатель файла на начало растровых данных

    int rowLength = BIH.biWidth / 8 + (BIH.biWidth % 8 != 0); // вычисляем длину строки изображения в байтах
    if (rowLength % 4 != 0) // она должна быть кратна 4-м.
        rowLength = rowLength / 4 * 4 + 4;

    uint8_t* bits = new uint8_t[rowLength]; // выделяем память растровых данных
    for (int y = BIH.biHeight - 1; y >= 0; y--) // цикл вывода строк. Строки располагаются снизу-вверх
    {
        f.read((char*)bits, rowLength); // для каждой строки читаем растровые данные в память
        uint8_t mask = 128; // задаем маску для определения бита изображения. Первый пиксель выделяется маской 10000000b == 128
        for (int x = 0; x < BIH.biWidth; x++) // цикл вывода пикселей строки
        {
            if (x % 8 == 0) // проверяем, закончили ли разбирать очередной байт растровых данных
                mask = 128; // если да, то маска сбрасывается в первоначальное состояние

            // вычисляем индекс цвета colorIndex в зависимости от значенияя бита в байте
            // х/8 - выражение для вычисления номера байта
            // bits[x / 8] & mask - выражение для вычисления кстановлен ли соответствующий бит или сброшен
            // например проверим 6 бит:
            // байт                    01011001
            // маска            01000000 - в маске должно быть такое число, в котором установлен лишь тот бит, номер которого мы хотим проверить в интересующем байте
            // результат 01000000 - если результат == 0, то проверемй бит тоже 0, если результат != 0, то бит == 1
            uint8_t colorIndex = (bits[x / 8] & mask) != 0 ? 1 : 0;
            // выбираем из палитрыы элементы с вычисленным индексом и помещаем их в переменные blue, green, red
            uint8_t blue = palette[colorIndex].blue;
            uint8_t green = palette[colorIndex].green;
            uint8_t red = palette[colorIndex].red;
            point.setFillColor(Color(red, green, blue));// задаем цвет нашей единичной окружности
            point.setPosition(x, y); // позиционируем окружность в нужную точку окна
            window.draw(point); // рисуем точку
            mask >>= 1; // сдвигаем маску вправо на 1 двоичный разряд, чтобы обеспечить проверку следующей по счету точки растровых данных
        }
    }
    delete[] bits; // освобождаем память, выделенную под строку растра
    delete[] palette; // освобождаем память, выделенную для палитры
}

bool ReadAndShowBMP(const string& FN)
{
    BitmapFileHeader BFH; // объявляем переменную для хранения заголовка BitmapFileHeader
    BitmapInfoHeader BIH; // объявляем переменную для хранения заголовка BitmapInfoHeader
    ifstream f(FN, ios::binary); // открываем для фтения файл в бинарном режиме
    if (!f) // если файл не открыт
        return false; // выходим с отрицательным результатом
    f.read((char*)&BFH, sizeof(BitmapFileHeader)); // читаем из файла заголовок BitmapFileHeader в переменную BFH
    f.read((char*)&BIH, sizeof(BitmapInfoHeader));       // читаем из файла заголовок BitmapInfoHeader в переменную BIH
    switch (BIH.biBitCount) // в зависимости от количества бит на пиксель вызываем разные функции отрисовки изображения
    {
    case 1:
        Show1BitImage(BFH, BIH, f); // монохромное
        break;
    case 4:
        Show4BitImage(BFH, BIH, f); // 16-ти цветное
        break;
    case 8:
        Show8BitImage(BFH, BIH, f); // 256-ти цветное
        break;
    case 24:
        Show24BitImage(BFH, BIH, f); // полноцветное
        break;
    }
    f.close(); // закрываем файл
}

int main()
{
    window.clear(); // очищаем окно
    ReadAndShowBMP("Trump16.bmp"); // вызываем нашу функцию вывода bmp файла
    window.display(); // отображаем построенное изображение нв экране
    //window.setFramerateLimit(1);
    while (window.isOpen()) // ждем закрытия окна
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }
}