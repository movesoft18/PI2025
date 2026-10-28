#include <iostream>

// предварительное объявление для класса Storage
class Storage;

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    // предварительное объявление, указанное выше, необходимо для этой строки объявления
    void displayItem(const Storage& storage);
};

class Storage // полное определение класса Storage
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storage(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Сделать функцию-член Display::displayItem другом класса Storage
    // (требуется увидеть полное объявление класса Display, как указано выше)
    friend void Display::displayItem(const Storage& storage);
};

// Теперь мы можем определить Display::displayItem, которой
// необходимо увидеть полное определение класса Storage
void Display::displayItem(const Storage& storage)
{
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else // display double first
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

int main()
{
    Storage storage(5, 6.7);
    Display display(false);

    display.displayItem(storage);

    return 0;
}