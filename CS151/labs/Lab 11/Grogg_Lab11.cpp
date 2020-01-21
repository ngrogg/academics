//libraries included
#include <iostream>
#include <cstdlib>

		//Uncomment .cpp file for BSD/UNIX based systems
#include "DateTime.h"
//#include "DateTime.cpp"

using namespace std;

int main()
{

		//Values for class
int DAY, MONTH, YEAR, HOUR, MINUTE, SECOND;

		//User enters values for class

cout << "Please enter a value for day: ";
cin >> DAY;
cout << "Please enter a value for month: ";
cin >> MONTH;
cout << "Please enter a value for year: ";
cin >> YEAR;
cout << "Please enter a value for hour: ";
cin >> HOUR;
cout << "Please enter a value for minute: ";
cin >> MINUTE;
cout << "Please enter a value for second: ";
cin >> SECOND;

		//Create class
DateTime Franken(DAY, MONTH, YEAR, HOUR, MINUTE, SECOND);

cout << Franken.getDateTime() << endl;

system("pause");
return 0;
}
