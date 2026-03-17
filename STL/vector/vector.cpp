#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1; // пустой вектор
	std::vector<int> v2(v1); // вектор v2 - копия вектора v1
	std::vector<int> v3 = v1; // вектор v3 - копия вектора v1
	std::vector<int> v4(5); // вектор v4 состоит из 5 чисел, каждое число равно 0
	std::vector<int> v5(5, 2); // вектор v5 состоит из 5 чисел, каждое число равно 2
	std::vector<int> v6{ 1, 2, 4, 5 }; // вектор v6 состоит из чисел 1, 2, 4, 5
	std::vector<int> v7 = { 1, 2, 3, 5 }; // вектор v7 состоит из чисел 1, 2, 4, 5}
	std::vector<std::string> towns{
		"Москва",
		"Воткинск",
		"Тюмень",
	};
	std::vector<std::vector<int>> matrix{
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{0,0,0},
	};
	std::vector<int> numbers{ 1, 2, 3, 4, 5 };
	int first = numbers.front(); // 1
	int last = numbers.back(); // 5
	int second = numbers[1]; // 2
	int x = numbers.at(2); // 3
	std::cout << "first: " << first << std::endl;
	std::cout << "second: " << second << std::endl;
	std::cout << "last: " << last << std::endl;
	std::cout << "x: " << x << std::endl;
	numbers[0] = 6; // изменяем значение
	for (int n : numbers)
		std::cout << n << " "; // 6 2 3 4 5
	std::cout << std::endl;
	return 0;
}
