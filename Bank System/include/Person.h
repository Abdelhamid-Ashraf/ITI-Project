#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;

class Person{
protected:
    int ID;
    string Name, Password;
public:
    //Constructor:
    Person() {
        this->ID = 0;
    }
    Person(int ID, string Name, string Password) {
        setID(ID);
        setName(Name);
        setPassword(Password);
    }

    //Setters:
    void setID(int ID) {
        this->ID = ID;
    }
    void setName(string Name) {
        if (Validation::validName(Name)) {
            this->Name = Name;
        }
        else
            cout << "Name must be 5 to 20 alphabetic characters\n";
    }

    void setPassword(string Password) {
        if (Validation::validPass(Password)) {
            this->Password = Password;
        }
        else
            cout << "Name must be 8 to 20 characters\n";
    }

    //Getters:
    int getID() {
        return this->ID;
    }
    string getName() {
        return this->Name;
    }
    string getPassword() {
        return this->Password;
    }

    //Methods:
    virtual void PrintINFO() = 0;
};

#endif // PERSON_H
