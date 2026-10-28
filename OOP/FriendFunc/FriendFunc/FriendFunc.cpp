#include <iostream>

class Accumulator
{
private:
    int m_value;
public:
    Accumulator() { m_value = 0; }
    void add(int value) { m_value += value; }
    void reset() { m_value = 0; }
    // Сделаем функцию reset() другом этого класса
    friend void reset(Accumulator& accumulator);
};

// reset() теперь является другом класса Accumulator
void reset(Accumulator& accumulator)
{
    // и может получить доступ к закрытым данным объектов Accumulator
    accumulator.m_value = 0;
}


class Value
{
private:
    int m_value;
public:
    Value(int value) { m_value = value; }
    friend bool isEqual(const Value& value1, const Value& value2);
};

bool isEqual(const Value& value1, const Value& value2)
{
    return (value1.m_value == value2.m_value);
}

int main()
{
    Accumulator acc;
    acc.add(5); // добавляем 5 в накапливающий сумматор
    // acc.m_value = 0;  // не работает
    reset(acc); // сбрасываем накапливающий сумматор в 0

    return 0;
}