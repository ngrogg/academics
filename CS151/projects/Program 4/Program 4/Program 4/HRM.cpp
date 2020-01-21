		// Libraries included
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <string>

		// Files included
#include "employee.h"
//#include "executive.h"
#include "hourlyemployee.h"
//#include "salariedemployee.h"
//#include "tempslave.h"

		// Uncomment to run on BSD/Unix based systems
#include "employee.cpp"
//#include "executive.cpp"
#include "hourlyemployee.cpp"
//#include "salariedemployee.cpp"
//#include "tempslave.cpp"

using namespace std;

int main()
{

		// Bool for while loop
bool keepgoing = true;

		//int(s) for input
int input;
int input1;
int input2;
int input3;
int input4;
		// Instantiate constructors

Employee E;
HourlyEmployee HE;

		//Variables for lists
string name;
string ssn;
int eid;
double wage_rate;
double hours;

		// While loop for program
while (keepgoing == true)
{
cout << "enter a number or 7 for help: ";
cin >> input;

if (input == 1)
{
cout << "Enter an employee type" << endl;
cout << ".1 For hourly employee" << endl;
cout << ".2 For salaried employee" << endl;
cout << ".3 For executive employee" << endl;
cout << ".4 For temp-slave employee" << endl;
cout << "employee type: ";
cin >> input1;

if (input1 == 1) 
{
	cout << "new hourly employee" << endl;

cout << "Enter worker eid, name (last name, first name), ssn, wage rate and hours worked" << endl;
cin >> eid;
cin.ignore();
getline(cin, name);
cin >> ssn;
cin >> wage_rate;
cin >> hours;

HE.addHE(eid, wage_rate, hours, name, ssn);
}

else if (input1 == 2)
{cout << "new salaried employee" << endl;}

else if (input1 == 3)
{cout << "new executive employee" << endl;}

else if (input1 == 4)
{cout << "new temp-slave employee" << endl;}

else
{cout << "invalid option" << endl;}
}

else if (input == 2)
{
cout << "Modify an employee" << endl;
}

else if (input == 3)
{
cout << "Output an employee's data" << endl;
cout << "Enter employee eid and name: ";
cin >> eid;
cin.ignore();
getline(cin,name);
HE.displayemployeeHE(eid,name);

}

else if (input == 4)
{
cout << "Delete an employee" << endl;
}

else if (input ==5)
{
cout << "Output payroll to console" << endl;
HE.displaylistHE();

}

else if (input == 6)
{
cout << "Export payroll to text file" << endl;
}

else if (input == 7)
{
cout << "Help" << endl;
cout << endl;
cout << "1. Add an employee" << endl;
cout << "2. Modify an employee" << endl;
cout << "3. Output an employee's data " << endl;
cout << "4. Delete an employee " << endl;
cout << "5. Output payroll to console" << endl;
cout << "6. Export payroll to text file" << endl;
cout << "7. Display this help message" << endl;
cout << "8. Quit " << endl;
cout << endl;
}

else if (input == 8)
{
keepgoing = false;
}

else
{
cout << "Invalid option" << endl;
}

}

system("pause");
return 0;

}


