#include <iostream>
#include "person.cpp"
#include "event.cpp"
#include "ticket.cpp"

using namespace std;

int main() {
    Person p;
    cin >> p;

    Person p2 = p;
    Person p3 = p;

    Event e = Event("0", "Buc", 10, 0);

    p2.setName("John Doe");
    p3.setName("Jane Doe");

    Person pArr[3] = { p, p2, p3 };

    e.setParticipants(pArr, 3);

    e.buyTicket(p);

    return 0;
}