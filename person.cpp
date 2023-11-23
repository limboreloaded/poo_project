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
            this->attendedEvents = nullptr;
        }

        Person(string name, int age, double balance, const char* phone) {
            this->name = name;
            this->age = age;
            this->balance = balance;
            this->hasDiscount = age < 18 || age > 60 ? true : false;
            strcpy(this->phone, phone);
        }

        string getName() {
            return this->name;
        }

        void setName(string name) {
            this->name = name;
        }

        double getBalance() {
            return this->balance;
        }

        void setBalance(double balance) {
            this->balance = balance;
        }

        bool getHasDiscount() {
            return this->hasDiscount;
        }

        void setHasDiscount(bool hasDiscount) {
            this->hasDiscount = hasDiscount;
        }

        char* getPhone() {
            return this->phone;
        }

        char* setPhone(char* phone) {
            strcpy(this->phone, phone);
        }

        ~Person() {
            if (this->attendedEvents != nullptr) {
                delete[] this->attendedEvents;
            }
        } 

    private:
        string name;
        int age;
        double balance;
        bool hasDiscount;
        char phone[10];
        string* attendedEvents;
};