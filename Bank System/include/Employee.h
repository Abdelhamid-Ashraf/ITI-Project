#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Person.h"
#include <vector>
#include "Client.h"

using namespace std;

class Employee:public Person{
protected:
    double Salary;
    vector<Client>clients;
public:
    //Constructor:
    Employee() {
        this->Salary = 0;
    }
    Employee(int ID, string Name, string Password, double Salary) :Person(ID, Name, Password) {
        setSalary(Salary);
    }

    //Setters:
    void setSalary(double Salary) {
        if (Validation::validSalary(Salary)) {
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
    void addClient(Client&client) {
        clients.emplace_back(client);
    }

    Client* searchClient(int ID) {
        for (auto& client : clients) {
            if (client.getID() == ID) {
                client.PrintINFO();
                return &client;
            }
        }
    }

    void ListClients() {
        for (auto& client : clients) {
            client.PrintINFO();
        }
    }

    void EditClient(int ID, string Name, string Password, double Balance) {
        for (auto& client : clients) {
            if (client.getID() == ID && client.getName() == Name && client.getPassword() == Password && client.getBalance() == Balance) {
                int answer;
                do
                {
                    cout << "What do u want to change ?\n";
                    cout << "1- Name\n2- Password\n3- Balance\n4- Exit\n";
                    cin >> answer;
                    if (answer == 1) {
                        cout << "current name is : " << client.getName() << endl;
                        cout << "please enter the new name \n";
                        string newname;
                        cin >> newname;
                        client.setName(newname);
                        cout << "name has been changed successfully " << client.getName() << endl;
                        return;
                    }
                    else if (answer == 2) {
                        cout << "current Password is : " << client.getPassword() << endl;
                        cout << "please enter the new Password \n";
                        string newPassword;
                        cin >> newPassword;
                        client.setPassword(newPassword);
                        cout << "Password has been changed successfully " << client.getPassword() << endl;
                        return;
                    }
                    else if (answer == 3) {
                        cout << "current Balance is : " << client.getBalance() << endl;
                        cout << "please enter the new Balance \n";
                        double newBalance;
                        cin >> newBalance;
                        client.setBalance(newBalance);
                        cout << "Balance has been changed successfully " << client.getBalance() << endl;
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
            else if (client.getID() != ID || client.getName() != Name || client.getPassword() != Password || client.getBalance() != Balance) {
                cout << "Client is not found\n";
                break;
            }
        }
    }

    //print employee info :
    void PrintINFO() {
        Person::PrintINFO();
        cout << "employee Salary : " << this->Salary << endl;
    }

};

#endif // EMPLOYEE_H
