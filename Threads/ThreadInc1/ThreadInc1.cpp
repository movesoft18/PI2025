#include <iostream>
#include <thread>
#include <time.h>
using namespace std;
unsigned int c = 0;
void Increment() // функция инкремента глобальной переменной, не использующая синхронизацию
{
    for (int i = 0; i < 200000000; i++)
        c++;
}
int main()
{
    // этот фрагмент программы использует инкремент в одном потоке, последовательно
    // дважды вызывая Increment();
    int t = clock();
    Increment();
    Increment();
    t = clock() - t;
    cout << "c= " << c << " time= " << t << " msec" << endl; // в результате всегда получаем число 4 000 000
    // этот фрагмент программы использует инкремент в двух потоках параллельно без синхронизации
    //  вызывая Increment();
    c = 0;
    t = clock();
    thread t1(Increment);
    thread t2(Increment);
    t1.join();
    t2.join();
    t = clock() - t;
    cout << "c= " << c << " time= " << t << " msec" << endl; // в результате получаем все что угодно от 2 000 000 до 4 000 000, но не 4 000 000
    cin.get();
}