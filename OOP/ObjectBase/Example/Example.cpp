#include <iostream>
class Person {
private:
    int years;
    int name;
public:
    Person();
private:
    std::string name1;
};
Person a;

class Man : Person {
private:
    std::string gender;
public:
    Man() :Person(), gender("m") {}
    
    void setGender(const std::string&g)
    {
        if(g=="м" || g == "ж")
            gender = g;
        else {
            throw std::invalid_argument("ошибка! можно только ввести м и ж");

        }
    }
    std::string getGender() { return gender; }
};
Man man;


int main()
{
    man.setGender("м");
    return 0;
}

