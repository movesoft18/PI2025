#include <iostream>
using namespace std;
int main()
{
	int a[10]{ 1,2,3,4,5,6,7,8,9,0 };
	int* p = a;

	int s = 0;
	for (int i = 0; i < 10; i++)
		s += a[i];
	cout << s << endl;

	s = 0;
	for (int i = 0; i < 10; i++)
		s += p[i];
	cout << s << endl;

	s = 0;
	for (int i = 0; i < 10; i++)
		s += *(a + i);
	cout << s << endl;
	auto end = p + 10;
	int b = *(p + 1) + 10; // b = 12
	// end = p + 10*sizeof(int)
	cout << p << " " << end << " " << end - p << endl;
	s = 0;
	while (p != end)
	{
		s += *p++;
	}
		s += *p;
	cout << s << endl;
	char s1[] = "Hello, world!";
	char s2[] = "             ";
	/*for (int i = 0; i < 13; i++)
		s2[i] = s1[i];*/
	char* c1 = s1;
	char* c2 = s2;
	while (*c2++ = *c1++);
	cout << s1 << " " << s2 << endl;
}

