#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"

using namespace std;

class Employee:public Person{
protected:
    double Salary;
    vector<Client>clients;
public:
    //constructor :
    Employee(){
        Salary=0;
    }
    Employee(int ID,string Name,string Password,double Salary):Person(ID,Name,Password){
        this->Salary = Salary;
    }

    //setters :
    void setSalary(double Salary){
        this->Salary = Salary;
    }

    //getters :
    double getSalary(){
        return this->Salary;
    }

    //methods :
    //add Client :
    void addClient(Client newclient){
        clients.emplace_back(newclient);
    }

    //search for Client :
    void searchforClient(int ID){
        for(auto&client:clients){
            if(client.getID()==ID){
                client.PrintINFO();
            }
        }
    }

    //print clients :
    void PrintClientsINFO(){
        for(auto&client:clients){
            client.PrintINFO();
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

    //print employee info :
    void PrintINFO(){
        cout<<"    Employee Name   : " <<getName()<<endl;
        cout<<"     Employee ID    : " <<getID()<<endl;
        cout<<"   Employee Salary  : " <<getSalary()<<endl;
        cout<<"====================="<<endl;
    }

};

#endif // EMPLOYEE_H
