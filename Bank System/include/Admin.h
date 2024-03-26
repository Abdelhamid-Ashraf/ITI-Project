#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Admin:public Employee{
public:
    //Constructor:
    Admin() {
    }
    Admin(int ID, string Name, string Password, double Salary) : Employee(ID, Name, Password,Salary) {

    }

    //Methods:

    void PrintINFO() {
        cout << "ADMIN Name : " << getName() << endl;
        cout << "ADMIN ID : " << getID() << endl;
        cout << "ADMIN Salary : " << getSalary() << endl;
    }

};

#endif // ADMIN_H
