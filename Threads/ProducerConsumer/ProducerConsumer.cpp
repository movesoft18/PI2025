#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

counting_semaphore<200> sem(0);
queue<string> tasks;
mutex mut;

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
        {
            lock_guard<mutex> lock(mut);
            task = tasks.front(); // читаю задачу
            tasks.pop(); // удаляю ее из очереди
        }
        if (task == "End.")
        {
            cout << "Заканчиваем работу.\n";
            return;
        }
        string message = "Обрабатывается задача " + task + '\n';
        cout << message;
        this_thread::sleep_for(chrono::seconds(rand() % 3)); // имитация работы
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(clock());
    thread producer(Producer, 20);
    thread consumer(Consumer);
    producer.join();
    consumer.join();
}