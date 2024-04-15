#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

class FilesHelper{
public:
    static void saveLast(string fileName, int id) {
     fstream filesavelast(fileName);
     filesavelast << id;
     filesavelast.close();
 }

 static int getLast(string fileName) {
     int id;
     fstream filegetlast;
     filegetlast.open(fileName,ios::app);
     filegetlast >> id;
     filegetlast.close();
     return id;
 }

 static void saveClient(string filename,string lastIDFile, Client client) {
     fstream file;
     file.open("Client.txt", ios::app);
     if (file.is_open()) {
         file << client.getID() << "&&" << client.getName() << "&&" << client.getBalance() << "&&" << client.getPassword() << endl;
         file.close();
     }
     int lastID = getLast(lastIDFile);
     saveLast(lastIDFile, lastID + 1);
 }

 static void saveEmployee(string filename ,string lastIDFile ,Employee employee) {
     fstream file;
      file.open(filename, ios::app);
     if (file.is_open()) {
         file << employee.getID() << "&&" << employee.getName() << "&&" << employee.getSalary() << "&&" << employee.getPassword() << endl;
         file.close();
     }
     int lastID = getLast(lastIDFile);
     saveLast(lastIDFile, lastID + 1);
 }

 static vector<Client> getClients() {
     fstream file;
     string line;
     vector<Client>clients;
     file.open("Client.txt", ios::in);
     if (file.is_open()) {
         while (getline(file, line)) {
             clients.emplace_back(Parser::parseToClient(line));
         }
     }
     file.close();
     return clients;
 }

 static vector<Employee> getEmployees() {
     fstream file;
     string line;
     vector<Employee>employees;
     file.open("Employee.txt", ios::in);
     if (file.is_open()) {
         while (getline(file, line)) {
             employees.emplace_back(Parser::parseToEmployee(line));
         }
     }
     file.close();
     return employees;
 }

 static vector<Admin> getAdmins() {
     fstream file;
     string line;
     vector<Admin>admins;
     file.open("Admin.txt", ios::in);
     if (file.is_open()) {
         while (getline(file, line)) {
             admins.emplace_back(Parser::parseToAdmin(line));
         }
     }
     file.close();
     return admins;
 }

 static void clearFile(string filename, string lastIDFile) {
     fstream file(filename, ios::out | ios::trunc);
     file.close();
     fstream file1(lastIDFile, ios::out | ios::trunc);
     file.close();
 }
};

#endif // FILESHELPER_H
