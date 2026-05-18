#include <future>
#include <thread>
#include <iostream>

int longRunningFunction() {
    // Длительная операция
    std::this_thread::sleep_for(
        std::chrono::seconds(1)
    );
    throw 2;
    return 42;
}

int main() {
    std::future<int> resultFuture = 
        std::async(longRunningFunction);
    // Делаем что-то еще, пока функция выполняется
    for (int i = 0; i < 20; i++)
    {
        std::cout << '.';
        std::this_thread::sleep_for(
            std::chrono::milliseconds(100)
        );
    }
    try
    {
        int result = resultFuture.get();  // Блокируется, пока результат не станет доступен
        std::cout << "Result = " << result << "\n";
    }
    catch (...)
    {
        std::cout << "Error in async function\n";
    }
}