#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"

using namespace std;

int main(){
    Employee e(12, "ahmedmahmod", "4664123asd", 5000),e1(13, "mozzaftany", "4664123abd", 6000);
    Admin a(10,"mohsenElmoder","22211133bb",10000);
    Client c(1,"mahmd","654321asd",3000), c1(2, "abdelhamid", "12356abdo", 2000);

   //employee :
   cout<< " employee info \n";
e.PrintINFO();
e1.PrintINFO();
cout << "==================\n";

e.addClient(c);
e.addClient(c1);

cout<< " employee search for client \n";
e.searchforClient(1);
cout << "==================\n";
cout<< " Clients info from employee\n";
e.PrintClientsINFO();

//client :
cout<< " Deposit \n";
c.Deposit(2000);
c.PrintINFO();

cout<< " Withdraw \n";
c.Withdraw(1000);
c.PrintINFO();

cout<< " Transfer \n";
c.TransferTo(1000, c1);
c.PrintINFO();
c1.PrintINFO();
cout << "==================\n";

//admin :
a.addEmployee(e);
a.addEmployee(e1);
cout << "==================\n";
a.PrintINFO();
cout << "==================\n";
cout<< " employee info from admin \n";
a.PrintEmployeeINFO();

}
