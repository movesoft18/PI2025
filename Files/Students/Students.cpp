#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    string lastName;
    string firstName;
    string middleName;
    char gender;
    string dateOfBirth;
    double avgScore;
};

int peopleCount(const string& fileName)
{
    ifstream f(fileName);
    if (f.is_open())
    {
        int lines = 0;
        string line;
        while (getline(f, line))
        {
            lines++;
        }
        f.close();
        return lines;// / 5;
    }
    return -1;
}

Student* getStudentsFromFile(const string& fileName, int count)
{
    ifstream f(fileName);
    if (f.is_open())
    {
        auto students = new Student[count];
        int index = 0;
        string lastName;
        string firstName;
        string middleName;
        char gender;
        string dateOfBirth;
        while (f >> lastName >> firstName >> middleName
            >> gender >> dateOfBirth)
        {
            students[index].lastName = lastName;
            students[index].firstName = firstName;
            students[index].middleName = middleName;
            students[index].gender = gender;
            students[index].dateOfBirth = dateOfBirth;
            index++;
        }
        f.close();
        return students;
    }
    return nullptr;
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
                students[i].gender << endl;
        }
    }
}

int main()
{
    //setlocale(LC_ALL, "");
    system("chcp 1251");
    int count = peopleCount("Students.txt");
    std::cout << "Кол-во студентов: " <<
        count << "\n";
    if (count > 0)
    {
        Student* students = getStudentsFromFile("Students.txt", count);
        if (students != nullptr)
        {
            printStudents(students, count);
            delete[] students;
        }
        else
            cout << "Ошибка чтения данных\n";
    }
}