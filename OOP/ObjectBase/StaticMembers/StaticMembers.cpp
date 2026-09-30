#include <iostream>
#include <string>
using namespace std;

class SomeObject
{
    static int nextId;
    int id;
    std::string name;
public:
    
    SomeObject(std::string name) : name(name)
    {
        id = getNextId();
    }
    std::string getName() const { return name; }
    int getId() const { return id; }
    static int getNextId() { 
        return nextId++; 
    }
    static int getLastId() { return nextId; }
};

int SomeObject::nextId = 1;

constexpr int COUNT = 1000;

int main()
{
    SomeObject* objects[COUNT];
    for (int i = 0; i < COUNT; i++) {
        objects[i] = new SomeObject("obj" + to_string(i));
        cout << objects[i]->getName() << "  " 
            << objects[i]->getId() << endl;
    }
    int id = SomeObject::getLastId();
    // ...
    for (int i = 0; i < COUNT; i++) {
        delete objects[i];
    }
}
