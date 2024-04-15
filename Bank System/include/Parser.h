#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser{
 public:
	static vector<string>split(string line,char d) {
		stringstream ss(line);
		vector<string> Tokens;
		string token;
		while (getline(ss, token,d)) {
			Tokens.push_back(token);
		}
		return Tokens;
   }

	static Client parseToClient(string line) {
		char d='&';
		vector<string>data = split(line, d);
		Client client;
		client.setID(stoi(data[0]));
		client.setName(data[1]);
		client.setBalance(stod(data[2]));
		client.setPassword(data[3]);
		return client;
	}

	static Employee parseToEmployee(string line) {
		char d = '&';
		vector<string>data = split(line, d);
		Employee employee;
		employee.setID(stoi(data[0]));
		employee.setName(data[1]);
		employee.setSalary(stod(data[2]));
		employee.setPassword(data[3]);
		return employee;
	}

	static Admin parseToAdmin(string line) {
		char d = '&';
		vector<string>data = split(line, d);
		Admin admin;
		admin.setID(stoi(data[0]));
		admin.setName(data[1]);
		admin.setSalary(stod(data[2]));
		admin.setPassword(data[3]);
		return admin;
	}
};

#endif // PARSER_H
