#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>

#define PI 3.14159265

using namespace std;

void arctan(double x)
{
	// Initialize variables
	double c=1,d=1;
	double n;
	cout << "Enter value for n: ";
	cin >> n;

	double a = pow(2,(-n/2));
	double b = x/(1+sqrt(1+(pow(x,2))));

	//While loop with stop condition
	while(1-a <= pow(2,-n))
	{
		// reassign variables
		c = (2*c)/(1+a);
		d = (2*a*b)/(1+(pow(b,2)));
		d = d/(1+sqrt(1-(pow(d,2))));
		d = (b+d)/(1-(b*d));
	        b = d/(1+sqrt(1+pow(d,2)));	
		a = (2*(sqrt(a)))/(1+a);

		// output f=c*ln(1+b/1-b)
		cout << "Custom arctan = " << setprecision(2) <<  c* log((1+b)/(1-b));
	}


}

int main()
{
	// More Trig, Lab 4 part 1

	// Assign x
	
	long double x;
	long double sinx;
	long double xminx;

	cout << "enter value for x: ";
	cin >> x;

	// Take sin of x
	
	sinx = sin(x * (PI/180));

	cout << "sin of x = " << sinx << endl;

	// Take x - sin(x)
	
	xminx = x - sinx;
	cout << "x - sin(x) = " << xminx << endl;

	// Multiply answer by 10^-4
	
	cout << "x - sin(x) * 10^-4 = " << sinx * pow(10,-4) << endl;
	
	// Direct Calculation of x

	cout << "Direct x = " <<  x - sin(x * (PI/180)) << endl;

	cout << "margin of difference = " << abs(xminx - (x-sin(x * (PI/180)))) << endl;  

	/*
	
	-- g++ results --
	X value: 30
	step result: 29.5
	direct calculation: 29.5
	difference: 0
	
	X value: 1
	step result: 0.982548
	direct calculation: 0.982548
	difference: 0
	
	X value: .001
	step result: .000982547
	direct calculation: .000982547
	difference: 0
	
	-- Windows results --
	X value: 30
	step result: 
	direct calculation: 
	difference: 
	
	X value: 1
	step result: 
	direct calculation: 
	difference: 
	
	X value: .001
	step result:
	direct calculation: 
	difference: 

	From what I can see, even with small numbers on g++ the difference is non-existent
	Windows
	*/

	// Even More Trig Lab 4 part 2
	cout << "Arctan stuff" << endl;
	
	double x2;

	cout << "Enter value x to solve for: ";
	cin >> x2;

	arctan(x2);

	cout << "STL arctan = " << atan(x2 * (180/PI)) << endl;

	//system("pause");
	return 0;
}
