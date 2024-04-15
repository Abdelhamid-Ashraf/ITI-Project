#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include "Employee.h"
#include <vector>


using namespace std;

class Admin:public Employee{
private:
    vector<Employee>employees;
public:
    //Constructor:
    Admin() {
    }
    Admin(int ID, string Name, string Password, double Salary) : Employee(ID, Name, Password,Salary) {

    }

    //Methods:
    void addEmployee(Employee& employee) {
        employees.emplace_back(employee);
    }

    Employee* serachEmployee(int ID) {
        for (auto& employee : employees) {
            if (employee.getID() == ID) {
                employee.PrintINFO();
                return &employee;
            }
        }
    }

    void ListEmployee() {
        for (auto& employee : employees) {
            employee.PrintINFO();
        }
    }

    void EditEmployee(int ID, string Name, string Password, double Salary) {
        for (auto& employee : employees) {
            if (employee.getID() == ID && employee.getName() == Name && employee.getPassword() == Password && employee.getSalary() == Salary) {
                int answer;
                do
                {
                    cout << "What do u want to change ?\n";
                    cout << "1- Name\n2- Password\n3- Balance\n4- Exit\n";
                    cin >> answer;
                    if (answer == 1) {
                        cout << "current name is : " << employee.getName() << endl;
                        cout << "please enter the new name \n";
                        string newname;
                        cin >> newname;
                        employee.setName(newname);
                        cout << "name has been changed successfully " << employee.getName() << endl;
                        return;
                    }
                    else if (answer == 2) {
                        cout << "current Password is : " << employee.getPassword() << endl;
                        cout << "please enter the new Password \n";
                        string newPassword;
                        cin >> newPassword;
                        employee.setPassword(newPassword);
                        cout << "Password has been changed successfully " << employee.getPassword() << endl;
                        return;
                    }
                    else if (answer == 3) {
                        cout << "current Salary is : " << employee.getSalary() << endl;
                        cout << "please enter the new Salary \n";
                        double newSalary;
                        cin >> newSalary;
                        employee.setSalary(newSalary);
                        cout << "Salary hase been changed successfully " << employee.getSalary() << endl;
                        return;
                    }
                    else if (answer == 4) {
                        cout << "thank you\n";
                        break;
                    }
                    else
                        cout << "wrong aswer\n";

                } while (answer >= 1 || answer <= 4);
            }
            else if (employee.getID() != ID || employee.getName() != Name || employee.getPassword() != Password || employee.getSalary() != Salary) {
                cout << "employee is not found\n";
                break;
            }
        }
    }

};

#endif // ADMIN_H
