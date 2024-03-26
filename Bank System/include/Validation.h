#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>

using namespace std;

class Validation
{
    public:
	static void validName(string Name) {
        if (Name.size() >= 5 && Name.size() <= 20) {
            for (int i = 0; i < Name.size(); i++) {
                if (Name[i] >= '0' && Name[i] <= '9') {
                    cout << "name must be 5 to 20 char only \n";

                }
            }
        }
    }

    static void validPass(string Password) {
        if (Password.size() < 8 || Password.size() > 20) {
            cout << "Password must be 8 to 20 char\n";
        }
    }
};

#endif // VALIDATION_H
