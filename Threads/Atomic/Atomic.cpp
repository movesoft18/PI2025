#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

std::atomic<unsigned int> c(0);


void Increment() // функция инкремента глобальной переменной, не использующая синхронизацию
{
    for (int i = 0; i < 200000000; i++)
        c++;
}

int main()
{
    c = 0;
    thread t1(Increment);
    thread t2(Increment);
    t1.join();
    t2.join();
    cout << "c= " << c << endl; // в результате получаем все что угодно от 2 000 000 до 4 000 000, но не 4 000 000
    cin.get();
}