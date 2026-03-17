#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{ 1,6,4,3,6,7 };
    for (auto e : v)
        cout << e << " ";
    cout << endl;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    for (vector<int>::iterator it = v.begin();
        it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
