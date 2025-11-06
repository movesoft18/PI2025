#include <iostream>
using namespace std;

struct Person
{
    string name;
    string passport;
    int yearOfBorn;
    char gender;
    //...
};

int main()
{
    Person p1 
    {
        "Иванов Иван Иванович",
        "9101 123456",
        1970,
        'М',
    };
    Person p2;
    p2.name = "Сидорова Клавдия Петровна";
    p2.passport = "9100 987654";
    p2.yearOfBorn = 2005;
    p2.gender = 'Ж';

    Person persons[10];
    persons[0].name = "gdhjagdhagdj";

}
