#include <iostream>
#include <vector>
#include "person.cpp"
#include "event.cpp"
#include "ticket.cpp"
#include "menu.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    char *eventFilename = argv[1];

    Person p;
    cin >> p;

    Menu menu = Menu(p, eventFilename);
    menu.start();

    return 0;
}