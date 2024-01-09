#pragma once

#include <iostream>

using namespace std;

class Ticket
{
public:
    static int ticketCount;

    Ticket()
    {
        this->id = -1;
    }

    Ticket(int id, double ticketPrice)
    {
        this->id = id;
        this->ticketPrice = ticketPrice;
        ticketCount += 1;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    double getTicketPrice()
    {
        return this->ticketPrice;
    }

    void setTicketPrice(double ticketPrice) {
        this->ticketPrice = ticketPrice;
    }

    ~Ticket()
    {
    }

    friend istream &operator>>(istream &, Ticket &);
    friend ostream &operator<<(ostream &, Ticket);

private:
    int id;
    double ticketPrice;
};

int Ticket::ticketCount = 0;