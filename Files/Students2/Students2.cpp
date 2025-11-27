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
        return lines / 6;
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
        string gender;
        string score;
        while (getline(f, students[index].lastName))
        {
            getline(f, students[index].firstName);
            getline(f, students[index].middleName);
            getline(f, gender);
            students[index].gender = gender.length() > 0 ?
                gender[0] : 'N';
            getline(f, students[index].dateOfBirth);
            getline(f, score);
            students[index].avgScore = stod(score);
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
                students[i].gender << " " <<
                students[i].avgScore << endl;
        }
    }
}

int main()
{
    //setlocale(LC_CTYPE, "");
    system("chcp 1251");
    const string fileName = "Students.txt";
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
    }
}