#pragma once

#include <iostream>
#include "person.cpp"

using namespace std;

class Event
{
private:
    string eventId;
    string location;
    Person *participants;
    double ticketPrice;
    int participantCount;

public:
    Event(string eventId, string location, double ticketPrice, int participantCount)
    {
        this->eventId = eventId;
        this->location = location;
        this->participants = nullptr;
        this->ticketPrice = ticketPrice;
        this->participantCount = 0;
    }

    string getEventId()
    {
        return this->eventId;
    }

    void setEventId(string eventId)
    {
        this->eventId = eventId;
    }

    double getTicketPrice()
    {
        return this->ticketPrice;
    }

    void setTicketPrice(double ticketPrice)
    {
        this->ticketPrice = ticketPrice;
    }

    int getParticipantCount()
    {
        return this->participantCount;
    }

    void setParticipantCount(int participantCount)
    {
        this->participantCount = participantCount;
    }

    string getLocation()
    {
        return this->location;
    }

    void setLocation(string location)
    {
        this->location = location;
    }

    void raiseTicketPrice(int amount)
    {
        this->ticketPrice += amount;
    }

    Person* getParticipants() {
        Person* participants = new Person[this->participantCount];

        for (int i = 0; i < this->participantCount; i++) {
            participants[i] = this->participants[i];
        }

        return participants;
    }

    void setParticipants(Person *participants, int participantCount)
    {
        if (this->participants != nullptr)
        {
            delete[] this->participants;
        }

        this->participants = new Person[participantCount];

        for (int i = 0; i < participantCount; i++)
        {
            this->participants[i] = participants[i];
        }

        this->participantCount = participantCount;
    }

    void addParticipant(Person &participant)
    {
        Person *participantCopy = new Person[this->participantCount];

        if (this->participants != nullptr)
        {
            delete[] this->participants;
        }

        this->participantCount += 1;

        this->participants = new Person[this->participantCount];

        for (int i = 0; i < this->participantCount - 1; i++)
        {
            this->participants[i] = participantCopy[i];
        }

        this->participants[this->participantCount - 1] = participant;

        participant.addAttendedEvent(this->eventId);

        delete[] participantCopy;
    }

    Event operator=(const Event &e)
    {
        this->eventId = e.eventId;
        this->location = e.location;
        this->ticketPrice = e.ticketPrice;
        this->participantCount = e.participantCount;

        if (e.participants != nullptr)
        {
            if (this->participants != nullptr)
                delete[] this->participants;
            this->participants = new Person[e.participantCount];

            for (int i = 0; i < e.participantCount; i++)
            {
                this->participants[i] = e.participants[i];
            }
        }

        return (*this);
    }

    ~Event()
    {
        if (this->participants != nullptr)
        {
            delete[] this->participants;
        }
    }

    friend istream &operator>>(istream &, Event &);
    friend ostream &operator<<(ostream &, Event);
};

ostream& operator<<(ostream& out, Event e) {
    cout << "Event id: " << e.eventId << endl;
    cout << "Event location: " << e.location << endl;
    cout << "Ticket price: " << e.ticketPrice << endl;
    cout << "Total participants: " << e.participantCount;

    return out;
}