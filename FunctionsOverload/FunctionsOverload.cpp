#include <iostream>

//int sum(int a, int b)
//{
//    return a + b;
//}

int sum(int a, int b, int c = 0, int d = 0, int e = 0, int f = 0)
{
    return a + b + c + d + e + f;
}

float sum(float a, float b)
{
    return a + b;
}

float sum(float a, int b)
{
    return a + b;
}

float sum(int a, float b)
{
    return a + b;
}

float sum(double a, double b)
{
    return a + b;
}




int main()
{
    std::cout << sum(4, 787) << "\n";
    std::cout << sum(4.0f, 787.0f) << "\n";
    std::cout << sum(4.6, 787.5) << "\n";
    std::cout << sum(4, 787.8f) << "\n";
    std::cout << sum(4.6f, 787) << "\n";
    std::cout << sum(4, 7, 8) << "\n";

}
