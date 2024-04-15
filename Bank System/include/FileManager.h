#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "fstream"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"

using namespace std;

class FileManager:public DataSourceInterface{
 public:

	void addClient(Client client) {
		FilesHelper::saveClient("Client.txt", "lastClientID", client);
	}

	void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employee.txt", "lastEmployeeID", employee);
	}

	void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admin.txt", "lastAdminID", admin);
	}

	vector<Client>getAllClients() {
		return FilesHelper::getClients();

	}

	vector<Employee>getAllEmployees() {
		return FilesHelper::getEmployees();
	}

	vector<Admin>getAllAdmins() {
		return FilesHelper::getAdmins();
	}

	void removeAllClients() {
		FilesHelper::clearFile("Client.txt", "lastClientID");
	}
	void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "lastEmployeeID");
	}
	void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "lastAdminID");
	}

};

#endif // FILEMANAGER_H
