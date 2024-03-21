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
    //constructor :
    Client(){
        Balance=0;
    }
    Client(int ID,string Name,string Password,double Balance):Person(ID,Name,Password){
        this->Balance = Balance;
    }

    //setters :
    void setBalance(double Balance){
       this->Balance=Balance;
    }

    //getters :
    double getBalance(){
        return this->Balance;
    }

    //methods :
    void Deposit(double amount){
        this->Balance+=amount;
    }
    void Withdraw(double amount){
        if(amount>=Balance){
            Balance -= amount;

        }
    }
    void TransferTo(double amount,Client&recipient){
        if(amount>=Balance){
            recipient.Deposit(amount);
            Balance-=amount;

        }
        else
            cout<<"Not enough Balance"<<endl;
    }

    void PrintINFO(){
        cout<<"     Clint Name   : " <<getName()<<endl;
        cout<<"     Client ID    : " <<getID()<<endl;
        cout<<"  Account Balance : " <<getBalance()<<endl;
        cout<<"====================="<<endl;
    }
};

#endif // CLIENT_H
