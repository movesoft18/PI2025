#include <iostream>
#include <thread>

// Функция, которая будет выполняться в отдельном потоке
void threadFunction() {
    std::cout << "Привет из" << 
        " потока 1 с ID : " << 
        std::this_thread::get_id() << std::endl;
}

void threadFunction1() {
    std::cout << "Привет из" <<
        " потока 2 с ID : " <<
        std::this_thread::get_id() << std::endl;
}

void threadFunction2() {
    std::cout << "Привет из" <<
        " потока 3 с ID : " <<
        std::this_thread::get_id() << std::endl;
}

int main() {
    setlocale(LC_ALL, "");
    // Создаём поток и передаём ему функцию для выполнения
    std::thread t(threadFunction);
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);

    // Выводим ID основного потока
    std::cout << "Привет из" << 
        " основного потока с ID : "
        << std::this_thread::get_id() << std::endl;

    // Ждём завершения потока (если не вызвать, программа может завершиться до завершения потока)
    t.join();
    t1.join();
    t2.join();

    return 0;
}
