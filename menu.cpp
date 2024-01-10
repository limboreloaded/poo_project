#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "process.cpp"
#include "person.cpp"
#include "event.cpp"

using namespace std;

class Menu : Process
{
public:
    void start()
    {
        int iteratorCount = 0;

        bool foundFile = false;

        cout << this->eventFilename << endl;

        ifstream eventFile(eventFilename);

        vector<Event> events = vector<Event>();

        string eventId;
        string location;

        string iterator;

        while (getline(eventFile, iterator))
        {
            Event event = tokenize(iterator, " ");
            events.push_back(event);
        }

        string reader;

        cout << "\033c";

        cout << "Welcome! Please choose an option from below to start operating the ticket machine!\n";
        cout << "Type (1) or (2):\n";

        cout << "1. Buy a ticket.\n";
        cout << "2. Show personal info. \n";

        cin >> reader;
        cout << "\033c";

        if (reader == "1")
        {
            cout << "Please choose an event by id!\n";

            for (int i = 0; i < events.size(); i++)
            {
                cout << events.at(i) << "\n\n";
            }

            cin >> reader;
            
            for (int i = 0; i < events.size(); i++)
            {
                string eventId = events.at(i).getEventId();
                if (eventId == reader) {
                    events.at(i).buyTicket(this->user);
                }
            }
        }

        else if (reader == "2") {
            cout << this->user;
        }
    }

    Event tokenize(string s, string del)
    {
        int iteratorCount = 0;
        Event e = Event();

        int start, end = -1 * del.size();
        do
        {
            start = end + del.size();
            end = s.find(del, start);
            string iterator = s.substr(start, end - start);

            iteratorCount += 1;

            if (iteratorCount == 1)
            {
                e.setEventId(iterator);
            }

            if (iteratorCount == 2)
            {
                e.setLocation(iterator);
            }

            if (iteratorCount == 3)
            {
                e.setTicketPrice(stod(iterator));
                iteratorCount = 0;
            }

        } while (end != -1);

        return e;
    }

    Menu()
    {
        this->user = Person();
        this->eventFilename = "";
    }

    Menu(const Person p, char *eventFilename)
    {
        this->user = p;
        this->eventFilename = eventFilename;
    }

    ~Menu()
    {
    }

private:
    Person user;
    char *eventFilename;
};