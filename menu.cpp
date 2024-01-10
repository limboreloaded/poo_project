#include <iostream>
#include "process.cpp"
#include "person.cpp"

using namespace std;

class Menu : Process
{
public:
    void start()
    {
        int eventsCount = 0;

        cout << this->user << endl;
        cout << this->eventFilename << endl;
    }

    Menu()
    {
        this->user = Person();
        this->eventFilename = "";
    }

    Menu(const Person p, char* eventFilename)
    {
        this->user = p;
        this->eventFilename = eventFilename;
    }

    ~Menu()
    {
    }

private:
    Person user;
    char* eventFilename;
};