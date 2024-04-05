#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <vector>
#include "fstream"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"

class FileManager:public DataSourceInterface{
   private:
	vector<Client>clients;
	vector<Employee>employees;
	vector<Admin>admins;
	fstream myfile, myfile1, myfile2;
	string line;
public:

	void addClient(Client client) {
		clients.emplace_back(client);
		myfile.open("Client.txt", ios::app);
		if (myfile.is_open()) {
			myfile << client.getID() << "&&" << client.getName() << "&&" << client.getBalance() << "&&" << client.getPassword()<<endl;
			myfile.close();
		}
	}

	void addEmployee(Employee employee) {
		employees.emplace_back(employee);
		myfile1.open("Employee.txt", ios::app);
		if (myfile1.is_open()) {
			myfile1 << employee.getID() << "&&" << employee.getName() << "&&" << employee.getSalary() << "&&" << employee.getPassword() << endl;
			myfile1.close();
		}
	}

	void addAdmin(Admin admin) {
		admins.emplace_back(admin);
		myfile2.open("Admin.txt", ios::app);
		if (myfile2.is_open()) {
			myfile2 << admin.getID() << "&&" << admin.getName() << "&&" << admin.getSalary() << "&&" << admin.getPassword() << endl;
			myfile2.close();
		}
	}

	vector<Client>getAllClients() {
		myfile.open("Client.txt", ios::in);
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				cout << line << endl;
			}
			cout << endl;
			myfile.close();
		}
		return clients;
	}
	vector<Employee>getAllEmployees() {
		myfile1.open("Employee.txt", ios::in);
		if (myfile1.is_open()) {
			while (getline(myfile1,line)) {
				cout << line << endl;
			}
			cout << endl;
			myfile1.close();
		}
		return employees;
	}
	vector<Employee>getAllAdmins() {
		myfile2.open("Admin.txt", ios::in);
		if (myfile2.is_open()) {
			while (getline(myfile2, line)) {
				cout << line << endl;
			}
			cout << endl;
			myfile2.close();
		}
		return employees;
	}

	void removeAllClients() {
		remove("Client.txt");
	}
	void removeAllEmployees() {
		remove("Employee.txt");
	}
	void removeAllAdmins() {
		remove("Admin.txt");
	}
};

#endif // FILEMANAGER_H
