#include <iostream>
#include <list>
using namespace std;

list<int>::iterator addListIter(list<int>::iterator first, int pos)
{
	for (int i = 0; i < pos; i++) first++;
	return first;
}

int main()
{
	std::list<int> v1; // пустой список
	std::list<int> v2(v1); // список v2 - копия вектора v1
	std::list<int> v3 = v1; // список v3 - копия вектора v1
	std::list<int> v4(5); // список v4 состоит из 5 чисел, каждое число равно 0
	std::list<int> v5(5, 2); // список v5 состоит из 5 чисел, каждое число равно 2
	std::list<int> v6{ 1, 2, 4, 5 }; // список v6 состоит из чисел 1, 2, 4, 5
	std::list<int> v7 = { 1, 2, 3, 5 }; // список v7 состоит из чисел 1, 2, 4, 5}
	std::list<std::string> towns{
		"Москва",
		"Воткинск",
		"Тюмень",
	};

	std::list<int> numbers{ 1, 2, 3, 4, 5 };
	int first = numbers.front(); // 1
	int last = numbers.back(); // 5
	int size = numbers.size(); // 5 - размер списка
	//int second = numbers[1]; // list не поддерживает индексацию
	//int x = numbers.at(2); // list не поддерживает at
	std::cout << "first: " << first << std::endl;
	std::cout << "last: " << last << std::endl;
	for (int n : numbers)
		std::cout << n << " "; // 1 2 3 4 5
	std::cout << std::endl;

	for (list<int>::iterator it = numbers.begin();
		it != numbers.end(); it++)
		cout << *it << " ";
	cout << endl;

	numbers.push_back(100); // добавили 100 в конец списка
	numbers.push_front(200); // добавили 200 в начало списка

	for (auto it = numbers.begin();it != numbers.end(); it++)
		cout << *it << " ";
	cout << endl;

	//numbers.insert(numbers.begin() + 2, 300); // так не работает, итератор нельзя передвинуть на несколько элементов
	auto iter = numbers.begin();
	iter++;
	iter++;
	numbers.insert(iter, 300);
	numbers.insert(addListIter(numbers.begin(), 5), 400);

	for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
		cout << *it << " ";
	cout << endl;

	numbers.erase(numbers.begin());// удаляем первый элемент
	numbers.erase(--numbers.end());// удаляем последний, предварительно передвинув итератор на последний элемент
	numbers.erase(++numbers.begin());// удаляем второй элемент
	for (int n : numbers)
		std::cout << n << " ";
	numbers.clear(); // очистка списка
	/*
	list<string> names{
	"Петров",
	"Иванов",
	"Сидоров",
	"Петров",
	"Сибиряков",
	};
	// так работать не будет
	for (auto i = names.begin(); i != names.end(); i++)
	{
		if (*i == "Петров")
			names.erase(i); // после удаления элемента итератор i становится недействительным
	}
	for (auto e : names) cout << e << ' ';
	cout << endl;
	*/
}