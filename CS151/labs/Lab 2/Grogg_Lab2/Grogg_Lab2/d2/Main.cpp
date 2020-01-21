/*
Nicholas Grogg
CS151
Lab 2
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

#include "Pedometer.h"
#include "Pedometer.cpp"

using namespace std;

int main()
{

/*
Park perimeter in km, using Default Constructor values
(1400 steps *110)/100000
*/

int gardenlap = 1.54;

int keepgoing = 1;

while (keepgoing == 1)
{

		//Default constructor
Pedometer DC;
		//Overloaded constructor with default values of 0.
Pedometer UserPedometer(0,0);


cout << "Enter the starting step value and stride distance in cm" << endl;
cin >> UserPedometer;

		//Verification Loop
while (UserPedometer.GetSteps() < 0 || UserPedometer.GetStride() < 0)
{
cout << "Please enter values greater than 0" << endl;
cin >> UserPedometer;
}

//remainder of program
//do math to find out how many times around the park to burn calories

int kilocalorie;

cout << "Enter kilocalorie value of food: ";
cin >> kilocalorie;

while (kilocalore < 0)
{
cout << "Enter kilocalorie value of food: ";
cin >> kilocalorie;
}



		//quit variable
int doover;

cout << "Would you like to go again? Enter 1 or 0: ";

cin >> doover;

		//Verification loop
while (doover != 1 && doover != 0)
{

cout << "Enter 1 or 0, mind your spaces: ";
cin >> doover;

}

keepgoing = doover;
//reset function


}
system("pause");
return 0;

}


/*

A kilo calorie is equal to .001 calories

*/
