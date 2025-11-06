#include <iostream>
using namespace std;
struct Person
{
	char name[20];
	int age;
	//...
};

int main()
{
	int* p1 = nullptr, *p5 = 0;
	double* p2 = NULL;
	Person* p3 = nullptr;
	int x = 10;
	int x1 = 11;
	double y = 432.67;
	Person man
	{
		"Иванов",
		24,
	};
	p1 = &x;
	p2 = &y;
	p3 = &man;
	cout << x << " " << p1 << endl;
	x = 20;
	cout << x << " " << p1 << endl;
	*p1 = 30;
	cout << x << " " << p1 << endl;
	p1 = &x1;
	p5 = p1;
	void* v = &x1;
	cout << sizeof(Person) << endl;
	Person* p = new Person{"Петров", 30};
	p1 = new int;
	*p1 = 400;
	cout << *p1 << endl;
	p->age = 22;
	delete p1;
	delete p;
	p = nullptr;
	p1 = nullptr;
	//cout << *p1 << endl;
	if (p1 != nullptr)
	{
		cout << *p1 << endl;
	}
}