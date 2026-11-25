#include <iostream>
#include <cassert>
using namespace std;
class IntList
{
private:
    int m_list[10]{};
public:
    void setItem(int index, int value) { m_list[index] = value; }
    int getItem(int index) const { return m_list[index]; }
    
    int& operator[] (int index)
    {
        //if (index < 0 || index > 10)
        //    throw out_of_range("Index out of range");
        assert(index >= 0 && index <= 9);
        return m_list[index];
    }
};

int main()
{
    IntList list{};
    list.setItem(2, 3);

    list[4] = 87;
    list[5] = list[0];
    list[20] = 100;
    cout << list[4];
    return 0;

}
