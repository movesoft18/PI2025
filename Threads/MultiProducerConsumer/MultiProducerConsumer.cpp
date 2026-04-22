#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>
#include <string>
#include <mutex>
#include <atomic>
using namespace std;

counting_semaphore<4> sem(0);
queue<string> tasks;
mutex mut;
atomic<int> needToStop(0);

void Producer(int count)
{
    for (int i = 0; i < count; i++)
    {
        this_thread::sleep_for(chrono::seconds(rand() % 3)); // имитация работы
        string task = "Task " + to_string(i); // текст задачи
        {
            lock_guard<mutex> lock(mut);
            tasks.push(task); // ставим задачу в очередь
        }
        string message = "Создана задача " + task + '\n';
        cout << message;
        sem.release(); // разблокируем семафор
    }
    {
        lock_guard<mutex> lock(mut);
        tasks.push("End.");
    }
    sem.release();
}

void Consumer()
{
    string task;
    while (true)
    {
        sem.acquire(); // жду открытия семафора
        if (tasks.empty())
        {
            if (needToStop == 1)
            {
                sem.release();
                return;
            }
        }
        {
            lock_guard<mutex> lock(mut);
            task = tasks.front(); // читаю задачу
            tasks.pop(); // удаляю ее из очереди
        }
        if (task == "End.")
        {
            cout << "Заканчиваем работу. " << 
                this_thread::get_id() << '\n';
            needToStop = 1;
            sem.release();
            return;
        }
        cout << "Обрабатывается задача " <<
            task << " потоком " <<
            this_thread::get_id() << '\n';
        this_thread::sleep_for(chrono::seconds(rand() % 10)); // имитация работы
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(clock());
    cout << "Процессоров: " 
        << thread::hardware_concurrency() 
        << endl;
    thread producer(Producer, 20);
    thread consumer1(Consumer);
    thread consumer2(Consumer);
    thread consumer3(Consumer);
    thread consumer4(Consumer);
    producer.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();
}