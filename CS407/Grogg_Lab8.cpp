/*
 * Lab 8, Nicholas Grogg
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

// Functions to define f(x), g(x) etc.
double f(double x)
{
	double a = pow(x,3) - (3*x) + 1;
	return a;
}

double g(double x)
{
	double a = pow(x,3) - 2 * sin(x);
	return a;
}

double h(double x)
{
	double a = x + 10 - x * cosh(50/x);
	return a;
}

double j(double x)
{
	double a = pow(x,3) - 3*x -5;
	return a;
}


// Function to calculate bisection
void Bisection(double a,double b, double fa, double fb)
{
	int n,nmax = 5;
	double c,error,e = .0001;
	double fc;

	// if sign(fa) = sign(fb)
	if(signbit(fa) == signbit(fb))
	{
		cout << "function has same signs at a and b" << endl;
		return;
	}

	error = b - a;

	for (n = 0; n < nmax; n++)
	{
		error = error/2;
		c = a + error;
		fc = f(c);
	}
	if(abs(error) < e)
	{
		cout << "convergence" << endl;
		cout << "c = " << c << endl;
		cout << "f(c) = " << fc << endl;
		return;
	}
	if(signbit(fa) == signbit(fc))
	{
		b = c;
		fb = fc;
	}
	else
	{
		a = c;
		fa = fc;
	}
	cout << "c = " << c << endl;
	cout << "f(c) = " << fc << endl;
}

int main()
{

	// f(x) = x^3 - 3x + 1, 0,1
	double faa = f(0);
	double fbb = f(1);
	Bisection(0,1,faa,fbb);
	
	// g(x) = x^3 -2*sin(x), .5,2
	double ga = g(.5);
	double gb = g(2);
	Bisection(.5,2,ga,gb);
	
	// h(x) = x+10-x*cosh(50/x), 120,130
	double ha = h(120);
	double hb = h(130);
	Bisection(120,130,ha,hb);
	
	// j(x) = x^3 - 3x - 5, 2,3
	double ja = j(2);
	double jb = j(3);
	Bisection(2,3,ja,jb);

	system("pause");
	return 0;
}
