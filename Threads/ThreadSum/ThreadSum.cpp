#include <iostream>
#include <thread>
using namespace std;

// Функция, которая будет выполняться в отдельном потоке
void threadSum(long long a, long long b) 
{
    long long sum = 0;
    for (long long i = a; i <= b; i++)
        sum += i;
    cout << "Сумма чисел от " << a << " до " << b << 
        " = " << sum << endl;
}

int main() {
    setlocale(LC_ALL, "");
    // Создаём поток и передаём ему функцию для выполнения
    std::thread t(threadSum, 1, 1000000);
    std::thread t1(threadSum, 1000001, 2000000);
    std::thread t2(threadSum, 2000001, 3000000);

    // Выводим из основного потока
    long long sum = 0, a = 4000000, b = 5000000;
    for (long long i = a; i <= b; i++)
        sum += i;
    cout << "Сумма чисел от " << a << " до " << b <<
        " = " << sum << endl;
    // Ждём завершения потока (если не вызвать, программа может завершиться до завершения потока)
    t.join();
    t1.join();
    t2.join();

    return 0;
}
