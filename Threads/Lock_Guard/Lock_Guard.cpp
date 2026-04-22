#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
unsigned int c = 0;

std::mutex mut;

void IncrementSync() // функция инкремента глобальной переменной, не использующая синхронизацию
{
    int counter = 0;
    for (int i = 0; i < 2000000; i++)
    {
        counter = 0;
        for (int j = 0; j < 100; j++)
            counter++;
        {
            std::lock_guard<std::mutex> lock(mut);
            c += counter;   
        }
    }
}
int main()
{
    c = 0;
    thread t3(IncrementSync);
    thread t4(IncrementSync);
    t3.join();
    t4.join();
    cout << "c= " << c << endl; // в результате получаем все что угодно от 2 000 000 до 4 000 000, но не 4 000 000
    cin.get();
}