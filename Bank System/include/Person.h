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
        ID = 0;
    }
    Person(int ID, string Name, string Passowrd) {
        this->ID = ID;
        this->Name = Name;
        this->Password = Passowrd;
    }

    //Setters:
    void setID(int ID) {
        this->ID = ID;
    }
    void setName(string Name) {
       Validation::validName(Name);
        this->Name = Name;
    }

    void setPassword(string Password) {
       Validation::validPass(Password);
        this->Password = Password;
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
