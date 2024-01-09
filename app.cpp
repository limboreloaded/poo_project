#include <iostream>
#include <vector>
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
    Event e2 = Event("1", "Pit", 5, 0);

    p2.setName("John Doe");
    p3.setName("Jane Doe");

    Person pArr[3] = { p, p2, p3 };

    e.setParticipants(pArr, 3);

    e.buyTicket(p);
    e2.buyTicket(p);
 
    vector<Ticket> tickets = p.getTickets();

    for (int i = 0; i < tickets.size(); i++) {
        
    }

    return 0;
}