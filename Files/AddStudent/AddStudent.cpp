#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;

struct Student
{
    string lastName;
    string firstName;
    string middleName;
    char gender;
    string dateOfBirth;
    double avgMark;
};

Student SetStudentInfo()
{
    Student student;
    string gender;
    cout << "Введите фамилию: "; getline(cin, student.lastName);
    cout << "Введите имя: "; getline(cin, student.firstName);
    cout << "Введите отчество: "; getline(cin, student.middleName);
    cout << "Введите пол: "; getline(cin, gender);
    student.gender = gender.length() > 0 ? gender[0] : 'N';
    cout << "Введите дата рождения: "; getline(cin, student.dateOfBirth);
    cout << "Введите средний балл: "; cin >> student.avgMark;
    return student;
}

bool SaveStudent(const string& fileName, const Student& student)
{
    ofstream f(fileName, ios::app);
    if (f)
    {
        f << "\n" << student.lastName << "\n" <<
            student.firstName << "\n" <<
            student.middleName << "\n" <<
            student.gender << "\n" <<
            student.dateOfBirth << "\n" <<
            student.avgMark;
        f.close();
        return true;
    }
    return false;
}

int main()
{
    //setlocale(LC_CTYPE, "");
    system("chcp 1251");
    auto student = SetStudentInfo();
    auto res = SaveStudent("..\\students2\\students.txt", student);
    if (res)
    {
        cout << "Информация успешно записана в файл\n";
    }
    else
    {
        cout << "Ошибка записи\n";
    }
}

