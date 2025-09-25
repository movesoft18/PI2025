#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int matrix[3][2]{
        { 3, -2 },
        {15, 17 },
        { 0, -1 }
    };
    cout << matrix[1][1] << endl;
    matrix[2][0] = 100;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    double m[3][3]{
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    cout << "Введите матрицу 3х3:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m[i][j];
        }
    }
    double determinant =
        m[0][0] * m[1][1] * m[2][2] +
        m[0][1] * m[1][2] * m[2][0] +
        m[1][0] * m[2][1] * m[0][2] -
        m[0][2] * m[1][1] * m[2][0] -
        m[0][1] * m[1][0] * m[2][2] -
        m[0][0] * m[1][2] * m[2][1];
    cout << "Определитель = " << determinant << endl;

}