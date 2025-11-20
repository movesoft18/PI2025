#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    std::ofstream f;
    //...
    f.open("test.txt");
    if (f)
    {
        f << "Hello World!\n";
        f.close();
    }
    else
    {
        cout << "Невозможно создать файл.\n";
    }
    std::ifstream f1("test.txt");
    if (f1.is_open())
    {
        std::string s;
        //f1 >> s;
        getline(f1, s);
        f1.close();
        cout << s << " " << endl;
    }
}

// ofstream - поток вывода
// ifstream - поток ввода
// fstream - поток ввода/вывода
