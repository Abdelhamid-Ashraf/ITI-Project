#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

class Admin:public Employee{
private:
    vector<Employee>employees;
public:
    //constructor:
    Admin(){
    }
    Admin(int ID,string Name,string Password,double Salary):Employee(ID,Name,Password,Salary){
    }

    //methods:
    //add Client :
    void addClient(Client newclient){
        clients.emplace_back(newclient);
    }
    //add employee :
    void addEmployee(Employee newemployee){
        employees.emplace_back(newemployee);
    }
    //search for Client :
    void searchforClient(int ID){
        for(auto&client:clients){
            if(client.getID()==ID){
                client.PrintINFO();
            }
        }
    }
    //search for employee :
    void searchforEmployee(int ID){
        for(auto&employee:employees){
            if(employee.getID()==ID){
                employee.PrintINFO();
            }
        }
    }

    //print clients :
    void PrintClientsINFO(){
        for(auto&client:clients){
            client.PrintINFO();
        }
    }
    //print clients :
    void PrintEmployeeINFO(){
        for(auto&employee:employees){
            employee.PrintINFO();
        }
    }

    //edit client info :
    void editClientINFO(int ID,string Name,string Password) {
        for (auto& client : clients) {
                if (client.getID() == ID && client.getName() == Name && client.getPassword() == Password) {
                    cout << "Edit Old Client INFO : " << endl;
                    cout << "    Client ID    : " << client.getID() << endl;
                    cout << "   Client Name   : " << client.getName() << endl;
                    cout << "do you want to change name or password or both? " << endl;
                    string answer, newName, newPassword;
                    cin >> answer;
                    if (answer == "name") {
                            cout << "enter new name : " << endl;
                            cin >> newName;
                            cout << endl;
                            client.setName(newName);
                            cout << "name changed successfully " << endl;
                            return;
                    }
                    else if (answer == "password") {
                            cout << "enter new Password : " << endl;
                            cin >> newPassword;
                            cout << endl;
                            client.setPassword(newPassword);
                            cout << "Password changed successfully " << endl;
                            return;
                    }

                    else if (answer == "both") {
                            cout << "enter new name : " << endl;
                            cin >> newName;
                            cout << endl;
                            client.setName(newName);
                            cout << "name changed successfully " << endl;
                            cout << "enter new Password : " << endl;
                            cin >> newPassword;
                            cout << endl;
                            client.setPassword(newPassword);
                            cout << "Password changed successfully " << endl;
                            return;
                    }
                }
         }
    }

    //edit employee info :
    void editEmployeeINFO(int ID,string Name,string Password) {
        for (auto& employee : employees) {
                if (employee.getID() == ID && employee.getName() == Name && employee.getPassword() == Password) {
                    cout << " Edit Old Client INFO : " << endl;
                    cout << "    Employee ID    : " << employee.getID() << endl;
                    cout << "   Employee Name   : " << employee.getName() << endl;
                    cout << " do you want to change name or password or both? " << endl;
                    string answer, newName, newPassword;
                    cin >> answer;
                    if (answer == "name") {
                            cout << "enter new name : " << endl;
                            cin >> newName;
                            cout << endl;
                            employee.setName(newName);
                            cout << "name changed successfully " << endl;
                            return;
                    }
                    else if (answer == "password") {
                            cout << "enter new Password : " << endl;
                            cin >> newPassword;
                            cout << endl;
                            employee.setPassword(newPassword);
                            cout << "Password changed successfully " << endl;
                            return;
                    }

                    else if (answer == "both") {
                            cout << "enter new name : " << endl;
                            cin >> newName;
                            cout << endl;
                            employee.setName(newName);
                            cout << "name changed successfully " << endl;
                            cout << "enter new Password : " << endl;
                            cin >> newPassword;
                            cout << endl;
                            employee.setPassword(newPassword);
                            cout << "Password changed successfully " << endl;
                            return;
                    }
                }
         }
    }

    //Print INFo:
    void PrintINFO(){
        cout << "    Admin Name   : " <<getName()<<endl;
        cout << "     Admin ID    : " <<getID()<<endl;
        cout << "   Admin Salary  : " <<getSalary()<<endl;
        cout << "====================="<<endl;
    }

};

#endif // ADMIN_H
