#include <iostream>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    std::cout << "Кол-во параметров: " << argc << "\n";
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << "\n";
    }
}
