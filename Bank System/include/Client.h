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
        setBalance(&Balance);
    }

    //Setters:
    void setBalance(double* Balance) {
        if (Validation::validBalance(Balance)) {
            this->Balance = *Balance;
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
            cout << "Successfull transaction\n";
        }
        else
            cout << "\nAmount excceded\n";
    }
    void transferTo(double amount, Client& recipient) {
        if (amount <= this->Balance) {
            recipient.deposit(amount);
            withdraw(amount) ;
        }
        else
            cout << "not enough balance\n";
    }
    void checkBalance() {
        cout << "Balance : " << this->Balance << endl;
    }

    void PrintINFO() {
        Person::PrintINFO();
        cout << "Account Balance : " << this->Balance << endl;
        cout << "====================\n";
    }

};

#endif // CLIENT_H
