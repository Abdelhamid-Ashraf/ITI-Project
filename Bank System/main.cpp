#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FileManager.h"

using namespace std;

int main() {
Admin a(10, "Admin", "22211133bb", 10000);
Employee e(12, "Employee a", "4664123asd", 5000), e1(13, "Employee b", "4664123abd", 6000);
Client c(1, "Client a", "654321asd", 3000), c1(2, "Client b", "12356abdo", 4000), c2(3, "Client c", "123487bbr", 6000);


//Admin info :
cout << "    Admin : \n";
cout << "============\n";
a.PrintINFO();
cout << "\n===================\n";

//Employee info :
cout << "  Employee : \n";
cout << "============\n";
e.PrintINFO();
cout << "============\n";
e1.PrintINFO();
cout << "\n===================\n";

//Client info :
cout << " Client : \n";
cout << "============\n";
cout << "befor deposit\n";
c.PrintINFO();

cout << "after deposit\n";
c.deposit(2000);
c.PrintINFO();

cout << "after withdraw\n";
c.withdraw(1010);
c.PrintINFO();

cout << "after transfer\n";
c.transferTo(500, c1);
c.PrintINFO();
c1.PrintINFO();
cout << "\n===================\n";

e.addClient(c);
e.addClient(c1);
e.addClient(c2);
e.serachClient(3);
e.ListClients();

a.addEmployee(e);
a.addEmployee(e1);

}
