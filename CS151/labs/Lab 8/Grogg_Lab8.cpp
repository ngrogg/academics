#include <cstdlib>
#include <iostream>
#include <cmath>


using namespace std;


		//Recursive function for 
int FibR(int n)
{
if(n == 0)
{return 0;}
else if(n == 1)
{return 1;}
else
{
return(FibR(n-1)+FibR(n-2));
}
}

int FibI(int n)
{

if(n == 0)
{return 0;}
else if(n == 1)
{return 1;}
else
{
		//two generations back, eloquence defined!
int genb4b4 = 0;

		//one generation back
int genb4 = 1;	

		//sum to return
int sum = 0;
for(int count = 1; count < n;count++)
{
	sum = genb4 + genb4b4;
	genb4b4 = genb4;
	genb4 = sum;
}
return sum;
}
}

int main()
{

		//Recursive section
cout << "Recursive section" << endl;
		
		//variable for input
int input;

		//user enters number
cout << "Please enter how many generations you'd like to iterate through: ";
cin >> input;

		//Verification loop
while(input <= 1)
{
cout << "Please enter how many generations you'd like to iterate through: ";
cin >> input;
}

		//Function
cout << "After " << input << " generations there will be: " << FibR(input) << " frog(s)" << endl;
cout << endl;


		//Iterative section
cout << "Iterative section" << endl;

cout << "After " << input << " generations there will be: " << FibI(input) << " frog(s)" << endl;

cout << endl;

		//Direct Calculation section
cout << "Direct Calculation section" << endl;

		//due to decimal answers, even with rounding numbers may sometimes be off by one
int DC = round((1/(sqrt(5)))*((pow(((1+(sqrt(5)))/2),input)-pow((1-(sqrt(5))/2),input))));
cout << "After " << input << " generations there will be: " << DC << " frog(s)" << endl;

system("pause");
return 0;

}
