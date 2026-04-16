#include <iostream>
#include <thread>
using namespace std;

// Функция, которая будет выполняться в отдельном потоке
void threadSum(long long a, long long b, long long& result)
{
    long long sum = 0;
    for (long long i = a; i <= b; i++)
        sum += i;
    result = sum;
}

int main() {
    setlocale(LC_ALL, "");
    long long res1 = 0, res2 = 0, res3 = 0;
    // Создаём поток и передаём ему функцию для выполнения
    std::thread t(threadSum, 1, 1000000, std::ref(res1));
    std::thread t1(threadSum, 1000001, 2000000, ref(res2));
    std::thread t2(threadSum, 2000001, 3000000, ref(res3));
    
    //...
    cout << "Идут вычисления ...\n";
    // Ждём завершения потока (если не вызвать, программа может завершиться до завершения потока)
    t.join();
    t1.join();
    t2.join();

    cout << "Сумма чисел от 1 до 1000000 = " << res1 << endl;
    cout << "Сумма чисел от 1000001 до 2000000 = " << res2 << endl;
    cout << "Сумма чисел от 2000001 до 3000000 = " << res3 << endl;

    return 0;
}
