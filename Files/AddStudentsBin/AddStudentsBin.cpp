#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;

struct Student
{
    char lastName[31];
    char firstName[21];
    char middleName[31];
    char gender;
    char dateOfBirth[11];
    double avgScore;
};

Student SetStudentInfo()
{
    Student student;
    string value;
    cout << "Введите фамилию: "; cin.getline(student.lastName, 31, '\n');
    cout << "Введите имя: "; cin.getline(student.firstName, 21, '\n');
    cout << "Введите отчество: "; cin.getline(student.middleName, 31, '\n');
    cout << "Введите пол: "; getline(cin, value);
    student.gender = value.length() > 0 ? value[0] : 'N';
    cout << "Введите дата рождения: "; cin.getline(student.dateOfBirth, 11, '\n');
    cout << "Введите средний балл: "; getline(cin, value);
    student.avgScore = stod(value);
    return student;
}

bool SaveStudent(const string& fileName, const Student& student)
{
    ofstream f(fileName, ios::binary | ios::app);
    if (f)
    {
        f.write((char*)(&student), sizeof(Student));
        f.close();
        return true;
    }
    return false;
}

int main()
{
    //setlocale(LC_CTYPE, "");
    system("chcp 1251");
    cout << sizeof(Student) << endl;
    auto student = SetStudentInfo();
    auto res = SaveStudent("students.bin", student);
    if (res)
    {
        cout << "Информация успешно записана в файл\n";
    }
    else
    {
        cout << "Ошибка записи\n";
    }
}

