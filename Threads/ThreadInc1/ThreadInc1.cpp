#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
unsigned int c = 0;

std::mutex mut;

void Increment() // функция инкремента глобальной переменной, не использующая синхронизацию
{
    for (int i = 0; i < 200000000; i++)
        c++;
}

void IncrementSync() // функция инкремента глобальной переменной, не использующая синхронизацию
{
    int counter = 0;
    for (int i = 0; i < 2000000; i++)
    {
        counter = 0;
        for (int j = 0; j < 100; j++)
            counter++;
        mut.lock();
        c += counter;
        mut.unlock();
    }
}
int main()
{
    // этот фрагмент программы использует инкремент в одном потоке, последовательно
    // дважды вызывая Increment();
    Increment();
    Increment();
    cout << "c= " << c << endl; // в результате всегда получаем число 4 000 000
    // этот фрагмент программы использует инкремент в двух потоках параллельно без синхронизации
    //  вызывая Increment();
    c = 0;
    thread t1(Increment);
    thread t2(Increment);
    t1.join();
    t2.join();
    cout << "c= " << c << endl; // в результате получаем все что угодно от 2 000 000 до 4 000 000, но не 4 000 000
    c = 0;
    thread t3(IncrementSync);
    thread t4(IncrementSync);
    t3.join();
    t4.join();
    cout << "c= " << c << endl; // в результате получаем все что угодно от 2 000 000 до 4 000 000, но не 4 000 000
    cin.get();
}