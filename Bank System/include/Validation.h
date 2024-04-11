#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>

using namespace std;

class Validation{
public:
    static bool validName(string& Name) {
        for (int i = 0; i < Name.size(); i++) {
            if (!isalpha(Name[i]) && Name[i] != ' ' || Name.size() < 5 || Name.size() > 20)
                return false;
       }
        return true;
    }

    static bool validPass(string& Password) {
        for (int i = 0; i < Password.size(); i++) {
            if (Password[i] == ' ' || Password.size() < 8 || Password.size() > 20)
                return false;
       }
        return true;
    }

    static bool validBalance(double* Balance) {
        if (*Balance < 1500) {
            return false;
        }
        return true;
    }

    static bool validSalary(double* Salary) {
        if (*Salary < 5000) {
            return false;
        }
        return true;
    }

};

#endif // VALIDATION_H
