#pragma once

#include <iostream>
#include <vector>
#include "ticket.cpp"

using namespace std;

class Person
{
public:
    Person()
    {
        this->name = "";
        this->age = 0;
        this->balance = 0.0;
        this->hasDiscount = false;
        strcpy(this->phone, "0000000000");
        this->attendedEvents = nullptr;
        this->eventsCount = 0;
        this->tickets = vector<Ticket>();
    }

    Person(string name, int age, double balance, const char *phone)
    {
        this->name = name;
        this->age = age;
        this->balance = balance;
        this->hasDiscount = age < 18 || age > 60 ? true : false;
        this->attendedEvents = nullptr;
        this->eventsCount = 0;
        strcpy(this->phone, phone);
        this->tickets = vector<Ticket>();
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    double getBalance()
    {
        return this->balance;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    bool getHasDiscount()
    {
        return this->hasDiscount;
    }

    void setHasDiscount(bool hasDiscount)
    {
        this->hasDiscount = hasDiscount;
    }

    char *getPhone()
    {
        return this->phone;
    }

    void setPhone(char *phone)
    {
        strcpy(this->phone, phone);
    }

    string *getAttendedEvents()
    {
        return this->attendedEvents;
    }

    void setAttendedEvents(char *attendedEvents, int eventsCount)
    {
        if (this->attendedEvents != nullptr)
        {
            delete[] this->attendedEvents;
        }

        this->attendedEvents = new string[eventsCount];

        for (int i = 0; i < eventsCount; i++)
        {
            this->attendedEvents[i] = attendedEvents[i];
        }

        this->eventsCount = eventsCount;
    }

    void addToBalance(double amount)
    {
        this->balance += amount;
    }

    vector<Ticket> getTickets() {
        return this->tickets;
    }

    void setTickets(vector<Ticket> tickets) {
        this->tickets = tickets;
    }

    void buyTicket(double ticketPrice)
    {
        double balance = this->balance;

        if (balance < ticketPrice)
        {
            cout << "Balance too low";
            exit(0);
        }

        this->setBalance(balance - ticketPrice);

        int ticketCount = Ticket::ticketCount;

        Ticket ticket = Ticket(ticketCount, ticketPrice);

        this->tickets.push_back(ticket);

        cout << "Bought ticket: " << ticket.getId() << " ";
    }

    void removeFromBalance(double amount)
    {
        this->balance -= amount;
    }

    void addAttendedEvent(string eventId)
    {
        if (this->attendedEvents == nullptr)
        {
            this->attendedEvents = new string[0];
        }

       this->attendedEvents[this->eventsCount] = eventId;
       this->eventsCount++;
    }

    bool operator>(Person p)
    {
        return this->age > p.age;
    }

    Person operator=(const Person &p)
    {
        this->name = p.name;
        this->age = p.age;
        this->balance = p.balance;
        this->hasDiscount = age < 18 || age > 60 ? true : false;
        strcpy(this->phone, p.phone);
        this->eventsCount = p.eventsCount;

        if (p.attendedEvents != nullptr)
        {
            if (this->attendedEvents != nullptr)
                delete[] this->attendedEvents;
            this->attendedEvents = new string[p.eventsCount];

            for (int i = 0; i < p.eventsCount; i++)
            {
                this->attendedEvents[i] = p.attendedEvents[i];
            }
        }

        return (*this);
    }

    ~Person()
    {
        if (this->attendedEvents != nullptr)
        {
            delete[] this->attendedEvents;
        }
    }

    friend istream &operator>>(istream &, Person &);
    friend ostream &operator<<(ostream &, Person);

private:
    string name;
    int age;
    double balance;
    bool hasDiscount;
    char phone[10];
    string *attendedEvents;
    vector<Ticket> tickets;

    int eventsCount;
};

istream &operator>>(istream &in, Person &p)
{
    char nameBuffer[256];

    cout << "Welcome! Please add your personal info below as requested..." << endl;
    cout << "Enter name: ";

    fgets(nameBuffer, sizeof(nameBuffer), stdin);
    p.name.assign(nameBuffer);

    cout << endl;

    cout << "Enter age: ";
    in >> p.age;
    cout << endl;

    cout << "Enter balance: ";
    in >> p.balance;
    cout << endl;

    bool hasPhoneNumber = false;

    while (!hasPhoneNumber)
    {
        char phoneBuffer[11];

        cout << "Enter phone number: ";

        fgets(phoneBuffer, sizeof(phoneBuffer), stdin);
        fgets(phoneBuffer, sizeof(phoneBuffer), stdin);
        cout << endl;

        if (strlen(phoneBuffer) == 10)
        {
            strcpy(p.phone, phoneBuffer);
            hasPhoneNumber = true;
        }
        else
        {
            cout << phoneBuffer;
            cout << "Invalid phone number, please try again!";
            cout << endl;
        }
    }

    return in;
}

ostream &operator<<(ostream &out, Person p)
{
    cout << "Your name: " << p.name << endl;
    cout << "Your age: " << p.age << endl;
    cout << "Your available balance: " << p.balance << endl;
    cout << "Discount: " << (p.hasDiscount ? "Yes." : "No.") << endl;
    cout << "Your phone number: " << p.phone << endl;

    return out;
}