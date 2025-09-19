#include <iostream>
#include <string>

int main()
{
    std::string s1 = "Привет, мир";
    std::string s2 = "";
    char symbol = '5';
    const char x = 4 ;
    auto a = 0L, b = 10L;
    auto f = 0.0f;
    std::cin >> a >> b;
    auto c = a + b;
    //x = b + c;
    std::cout << c << "\n";
    int y = 0x4f64d;  // шестнадцатиричная
    int z = 012; // восьмеричная
    int bin = 0b10010101010; // двоичная

}


/*
bool - логический тип true false 1 байт
char - символьный 1 байт ascii -128 +127
signed char
unsigned char 0..255

short (signed short int, short int) 2 -32768..+32767

int 4 байта -2^31 .. +2^31-1
long 4 байта 

long long 8 байт -2^63 +2^63-1


0.6325 6.325Е-01
34.3232 3.4232Е+01
-65.2782


float - 4 +-3.4*10^-38 +-3.4*10^38 7-8 цифр
double - 8  17-19 +-1.7Е-308 +-1.7Е308
long double - 8
1.6787237278Е-18


auto b = 0;

string text = "Привет, мир";
string text1 = "";

*/


/*

a + b
a - b
a * b
a / b
a % b

10 % 2 = 0
10 % 3 = 1
10 / 2 = 5
10 / 3 = 3

-a

(7 + a * b - c)/(2 * a)


int a = 5;
int b = 0;

a++; // 6
b--; // -1

++a; // 7
--b; // -2

b = ++a; // 8 8

 a = b;
 c = a + b;
*/

/*

int a = 10;
int b = 20;

bool e = a > b; // false

a == b
>
<
>=
<=

!=

bool x = false;

!x; // true

a && b
a || b 


a = 10;

b = 2;

c = a >> b; // 0000001000001010
               0000000010000010
с = a << b; // 0000001000001010
               0000100000101000
*/
