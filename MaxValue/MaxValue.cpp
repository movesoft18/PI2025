
#include <iostream>

template <typename T>
int indexOfMax(T array[], int count)
{
    int index = 0;
    T maxValue = array[index];
    for (int i = 1; i < count; i++)
    {
        if (array[i] > maxValue)
        {
            index = i;
            maxValue = array[i];
        }
    }
    return index;
}

using namespace std;

int main()
{
    int a[10]{ 14,2,321,4,53,-6,7,83,9,111110 };
    double b[10]{ 14.3,2,-32.1,4,53,-6,7,8.3,9,1111.10 };
    string s[3]{
        "masha",
        "Petya",
        "Vasya",
    };
    int index = indexOfMax(a, 10);
    cout << "index=" << index << " value="
        << a[index] << endl;
    index = indexOfMax(b, 10);
    cout << "index=" << index << " value="
        << b[index] << endl;
    index = indexOfMax(s, 3);
    cout << "index=" << index << " value="
        << s[index] << endl;
}

