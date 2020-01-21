/*
Lab 1
Nicholas Grogg
CS151
FALL 2017
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

//		Start, end, and calculation variables	

int startn, endn, placen;
int cyclecount = 1;

cout << "Please enter a number greater than 1 and less than 1,000,000: ";
cin >> startn;

cout << "Please enter a number smaller than the previous number: ";
cin >> endn;

//		Verification Loops(s)

while (startn >= 1000000 || startn <= 0)
{

cout << "Please enter a number greater than 1 and less than 1,000,000: ";
cin >> startn;

}

while (startn <= endn)
{

cout << "Please enter a number smaller than the starting number: ";
cin >> endn;


}

//		 print n

cout << "Starting at " << startn << " and ending at " << endn <<  endl;

cout << startn << " ";

placen = startn;

while (placen > endn)
{

//		if n = 1 then STOP

if (placen == 1)
{

cout << endl;
cout << endn << " " << startn << " " << cyclecount;
cout << endl;

exit(1);

}

//		if n is odd then n = 3n + 1  

if ((placen % 2) != 0)
{

placen = (placen*3) + 1;
cyclecount += 1;

} 

//		else n = n/2  

else
{

placen = (placen/2);
cyclecount += 1;

}

//		Repeat

cout <<  placen << " ";

}

cout << endl;
cout << endn << " " << startn << " " << cyclecount;
cout << endl;


system ("pause");
return 0;
}
