#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Client:public Person{
private:
    double Balance;
public:
    //Constructor:
    Client() {
        Balance = 0;
    }
    Client(int ID, string Name, string Password, double Balance) :Person(ID, Name, Password) {
        this->Balance = Balance;
    }

    //Setters:
    void setBalance(double Balance) {
        double b = 1500;
        if (Balance >= b) {
            this->Balance = Balance;
        }
        else
            cout << "the least amount to open an account is 1500 \n";
    }

    //Getters:
    double getBalance() {
        return this->Balance;
    }

    //Methods:
    void deposit(double amount) {
        this->Balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= this->Balance) {
            this->Balance -= amount;
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (amount <= this->Balance) {
            recipient.deposit(amount);
            withdraw(amount) ;
        }
        else
            cout << "not enough balance\n";
    }


    void PrintINFO() {
        cout << " Client Name : " << getName() << endl;
        cout << " Client ID : " << getID() << endl;
        cout << "Account Balance :" << getBalance() << endl;
        cout << "====================\n";
    }
};

#endif // CLIENT_H
