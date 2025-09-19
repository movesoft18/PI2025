
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	double numbers[10] = {-1,22,-3,44,5,678,7,98,9,0};
	int numbers1[]{4,7,45,3,5,9,6};
	int n = numbers[2];
	numbers[9] = 100;
	char s1[] = {'h','e','l','l','o','!'};
	char s2[] = "hello!";
	int arraySize = sizeof(numbers) / sizeof(numbers[0]);
	constexpr int array1Size = sizeof(numbers1) / sizeof(numbers1[0]);
	
	for (int i = 0; i < array1Size; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент: ";
		cin >> numbers1[i];
	}
	
	for (int i = 0; i < array1Size; i++)
	{
		cout << numbers1[i] << " ";
	}
	cout << endl;

	int sum = 0;
	for (int i = 0; i < array1Size; i++)
	{
		sum += numbers1[i];
	}
	cout << "Сумма элементов массива = " << sum << endl;
	sum = 0;
	
	for (auto e : numbers)
	{
		sum += e;
	}
	cout << "Сумма элементов массива numbers = " << sum << endl;
}