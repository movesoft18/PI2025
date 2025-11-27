#include <iostream>
#include <fstream>
#include <string>
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

int peopleCount(const string& fileName)
{
    ifstream f(fileName);
    if (f.is_open())
    {
        f.seekg(0, ios::end);
        return f.tellg() / sizeof(Student);
    }
    return -1;
}

Student* getStudentsFromFile(const string& fileName, int count)
{
    ifstream f(fileName);
    if (f.is_open())
    {
        auto students = new Student[count];
        f.read((char*)students, count * sizeof(Student));
        f.close();
        return students;
    }
    return nullptr;
}

void getStudentFromFileByIndex(const string& fileName, int index)
{
    ifstream f(fileName);
    int count = peopleCount(fileName);
    if (peopleCount(fileName) > 0 && index < count)
    {
        if (f.is_open())
        {
            Student student;
            f.seekg(index * sizeof(Student));
            f.read((char*)(&student), sizeof(Student));
            f.close();
            cout << "Информация о студенте с индексом " << index << ":\n";
            cout << student.lastName << " " <<
                student.firstName << " " <<
                student.middleName << " " <<
                student.dateOfBirth << " " <<
                student.gender << " " <<
                student.avgScore << endl;
        }
    }

}

void printStudents(Student* students, int count)
{
    if (students != nullptr)
    {
        for (int i = 0; i < count; i++)
        {
            cout << students[i].lastName << " " <<
                students[i].firstName << " " <<
                students[i].middleName << " " <<
                students[i].dateOfBirth << " " <<
                students[i].gender << " " <<
                students[i].avgScore << endl;
        }
    }
}

int main()
{
    //setlocale(LC_CTYPE, "");
    system("chcp 1251");
    const string fileName = "..\\AddStudentsBin\\Students.bin";
    int count = peopleCount(fileName);
    std::cout << "Кол-во студентов: " <<
        count << "\n";
    if (count > 0)
    {
        Student* students = getStudentsFromFile(fileName, count);
        if (students != nullptr)
        {
            printStudents(students, count);
            delete[] students;
        }
        else
            cout << "Ошибка чтения данных\n";
        getStudentFromFileByIndex(fileName, 2);
    }
}