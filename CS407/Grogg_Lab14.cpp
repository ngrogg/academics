#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Helper functions 

long double f1(long double x)
{
	long double p = (-1 * pow(x, 2));
	return exp(p);
}
long double f2(long double x)
{
	return sin(x);
}
long double f3(long double x)
{
	return exp(x);
}
long double f4(long double x)
{
	return atan(x);
}
long double f5(long double x)
{
	long double p = (pow(x,2) + 2);
	return pow(p, -1);
}
long double f6(long double x)
{
	long double p = sin(x);
	return p/x;
}
long double f7(long double x)
{
	long double p = pow(x,2);
	return p - 2;
}

// Functions
// option, which f(x) to use, a and b are the bounds
void Trapezoid(int option, long double a, long double b)
{

	int i,n = 60;
	long double h, sum, x;

	h = (b-a)/n;

	// set sum based on which function to solve for
	if (option == 1)
	{sum = .5 * (f1(a) + f1(b));}

	if (option == 2)
	{sum = .5 * (f2(a) + f2(b));}
	
	if (option == 3)
	{sum = .5 * (f3(a) + f3(b));}
	
	if (option == 4)
	{sum = .5 * (f4(a) + f4(b));}
	
	if (option == 5)
	{sum = .5 * (f5(a) + f5(b));}
	
	if (option == 6)
	{sum = .5 * (f6(a) + f6(b));}
	
	if (option == 7)
	{sum = .5 * (f7(a) + f7(b));}

	for(i = 0; i < n-1; i++)
	{
		x = a + (i*h);

		// Assign sum = sum + f(x) based on option
		if(option == 1)
		{sum = sum + f1(x);}

		if(option == 2)
		{sum = sum + f2(x);}

		if(option == 3)
		{sum = sum + f3(x);}

		if(option == 4)
		{sum = sum + f4(x);}

		if(option == 5)
		{sum = sum + f5(x);}

		if(option == 6)
		{sum = sum + f6(x);}
		
		if(option == 7)
		{sum = sum + f7(x);}

	}

	sum = sum*h;
	cout << " Sum = " << sum << endl;

}

int main()
{
	// Section 5.2,  page 91
	
	// Part a 
	cout << "Part a" << endl;
	Trapezoid(1, 0, 1);
	cout << "Actual answer:" << " approx. 0.746824"  << endl;

	// Part b 
	long double pi = 4*atan(1);
	cout << "Part b" << endl;
	Trapezoid(2, 0, pi);
	cout << "Actual answer:" << " 2"  << endl;

	// Part c 
	cout << "Part c" << endl;
	Trapezoid(3, 0, 1);
	cout << "Actual answer:" << " approx. 1.7183"  << endl;

	// Part d
	cout << "Part d" << endl;
	Trapezoid(4, 0, 1);
	cout << "Actual answer:" << " approx. 0.43882"  << endl;

	// Part e 
	cout << "Part e" << endl;
	Trapezoid(5, 0, 1);
	cout << "Actual answer:" << " approx. 0.43521"  << endl;

	// Part f 
	cout << "Part f, using .1 instead of 0" << endl;
	Trapezoid(6, 0.1, 1);
	cout << "Actual answer:" << " approx. 0.846139"  << endl;
	
	// Part g 
	cout << "Part g" << endl;
	Trapezoid(7, 1, 3);
	cout << "Actual answer:" << " approx. 4.6667"  << endl;

	cout << "All answers approximate closely, high partitions would";
	cout << " likely increase accuracy further" << endl;

	system("pause");
	return 0;
	
}
