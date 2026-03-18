#include <iostream>
#include <array>
using namespace std;

int main()
{
	std::array<int, 0> v1; // пустой массив
	std::array<int, 5> v4; // массив v4 состоит из 5 чисел, каждое число не определено
	std::array<int, 4> v6{ 1, 2, 4, 5 }; // массив v6 состоит из чисел 1, 2, 4, 5
	std::array<int, 4> v7 = { 1, 2, 3, 5 }; // массив v7 состоит из чисел 1, 2, 4, 5}
	std::array<std::string, 3> towns{
		"Москва",
		"Воткинск",
		"Тюмень",
	};

	std::array<int, 5> numbers{ 1, 2, 3, 4, 5 };
	int first = numbers.front(); // 1
	int last = numbers.back(); // 5
	int size = numbers.size(); // 5 - размер массив
	int second = numbers[1]; // 2
	int x = numbers.at(2); // 2
	std::cout << "first: " << first << std::endl;
	std::cout << "last: " << last << std::endl;
	for (int n : numbers)
		std::cout << n << " "; // 1 2 3 4 5
	std::cout << std::endl;

	for (array<int, 5>::iterator it = numbers.begin();
		it != numbers.end(); it++)
		cout << *it << " ";
	cout << endl;

	//numbers.push_back(100); // нельзя добавлять элементы, нет таких функций
	//numbers.push_front(200); // нельзя добавлять элементы, нет таких функций

	for (auto it = numbers.begin(); it != numbers.end(); it++)
		cout << *it << " ";
	cout << endl;

	//numbers.insert(numbers.begin() + 2, 300); // нельзя вставлять элементы, нет таких функций

	for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
		cout << *it << " ";
	cout << endl;

	//numbers.erase(numbers.begin());// нельзя удалять элементы, нет такой функции
	for (int n : numbers)
		std::cout << n << " ";
	//numbers.clear(); // нельзя очистить список
}