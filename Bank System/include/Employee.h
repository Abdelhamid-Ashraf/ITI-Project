#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Person.h"


using namespace std;

class Employee:public Person{
protected:
    double Salary;
public:
    //Constructor:
    Employee() {
        Salary = 0;
    }
    Employee(int ID, string Name, string Password, double Salary) :Person(ID, Name, Password) {
        this->Salary = Salary;
    }

    //Setters:
    void setSalary(double Salary) {
        double b = 5000;
        if (Salary >= b) {
            this->Salary = Salary;
        }
        else
            cout << "the least amount to open an account is 5000 \n";
    }

    //Getters:
    double getSalary() {
        return this->Salary;
    }


    //Methods :
    //print employee info :
    void PrintINFO() {
        cout << "Employee Name : " << getName() << endl;
        cout << "Employee ID : " << getID() << endl;
        cout << "Employee Salary : " << getSalary() << endl;
    }

};

#endif // EMPLOYEE_H
