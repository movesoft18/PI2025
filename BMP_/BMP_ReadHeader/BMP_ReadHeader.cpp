#include <iostream>
#include <fstream>
using namespace std;

#pragma pack (push,1) // обязательно выключаем выравнивание элементов структур по умолчанию
struct BitmapFileHeader
{
    char  bfType[2]; // Сигнатура ВМ
    uint32_t bfSize; // Должно быть равно размеру файла в байтах
    uint16_t  bfReserved1;
    uint16_t  bfReserved2;
    uint32_t bfOffBits; // Позиция растровых данных в файле
};

struct BitmapInfoHeader
{
    uint32_t biSize;        // Размер BitmapInfoHeader в байтах 40
    int32_t biWidth;        // Ширина в пикселях
    int32_t biHeight;       // Высота в пикселях
    uint16_t biPlanes;      // Всегда 1
    uint16_t biBitCount;    // Кол-во бит на пиксель
    uint32_t biCompression; // Сжато ли изображение
    uint32_t biSizeImage;   // Размер изображения в байтах
    int32_t biXPelsPerMeter;// указывает предпочтительное разрешение по вертикали в пикселах на метр
    int32_t biYPelsPerMeter;// указывает предпочтительное разрешение по вертикали в пикселах на метр
    uint32_t biClrUsed;     // Кол-во используемых цветов
    uint32_t biClrImportant;// Кол-во важных цветов
};

struct RGBQuad
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;
};

#pragma pack(pop)

int fileSize(const string& fileName)
{
    ifstream f(fileName);
    if (f.is_open())
    {
        f.seekg(0, ios::end);
        return f.tellg();
    }
    return -1;
}

int main()
{
    const string fileName = "16.bmp";
    setlocale(LC_ALL, "");
    ifstream f(fileName, ios::binary);
    if (f)
    {
        BitmapFileHeader bfh;
        BitmapInfoHeader bih;
        RGBQuad* colors;
        f.read((char*)&bfh, sizeof(BitmapFileHeader));
        cout << "Сигнатура: " << bfh.bfType[0] << bfh.bfType[1] << endl;
        cout << "Размер файла: " << bfh.bfSize << endl;
        cout << "Истинный размер файла: " << fileSize(fileName) << endl;
        cout << "Смещение растровых данных: " << bfh.bfOffBits << "\n\n";

        if (bfh.bfType[0] != 'B' || bfh.bfType[1] != 'M' ||
            bfh.bfSize != fileSize(fileName))
        {
            cout << "Файл поврежден\n";
            return 1;
        }

        f.read((char*)&bih, sizeof(BitmapInfoHeader));
        cout << "Ширина: " << bih.biWidth << endl;
        cout << "Высота: " << bih.biHeight << endl;
        cout << "Бит на пиксель: " << bih.biBitCount << endl;
        cout << "Сжатие: " << bih.biCompression << endl;
        cout << "Размер изобр: " << bih.biSizeImage << endl;
        cout << "Разрешение Х: " << bih.biXPelsPerMeter << endl;
        cout << "Разрешение У: " << bih.biYPelsPerMeter << endl;
        cout << "Исп. цветов: " << bih.biClrUsed << endl;
        cout << "Важных цветов: " << bih.biClrImportant << endl;
        
        if (bih.biBitCount != 24)
        {
            size_t paletteSize = bih.biClrUsed == 0 ? 1 << bih.biBitCount : bih.biClrUsed;
            colors = new RGBQuad[paletteSize];
            f.read((char*)colors, sizeof(RGBQuad) * paletteSize);
            //...
            delete[] colors;
        }
        f.close();
    }
}
