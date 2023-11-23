#include <iostream>

using namespace std;

class Person {
    public:
        Person() {
            this->name = "INVALID";
            this->age = 0;
            this->balance = 0.0;
            this->hasDiscount = false;
            strcpy(this->phone, "0000000000");
        }

    private:
        string name;
        int age;
        double balance;
        bool hasDiscount;
        char phone[10];

        //! Ticket boughtTickets;
};