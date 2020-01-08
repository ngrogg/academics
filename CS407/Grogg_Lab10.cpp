#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

/* Helper functions */

// Newton helper functions
double f(double x)
{
	double a = pow(x,3) - 5*x + 3;
	return a;
}

// derivative f'(x)
double fd(double x)
{
	double a = 3*pow(x,2) - 5;
	return a;
}

/* Math Functions */

// Bisection Function
void Bisection(double a,double b, double fa, double fb)
/{
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

// Newton Function
void Newton(double xi, double fx)
{
	int n,nmax = 5;
	double d, delta = .001,epsilon = .001,fp;

	// Delta and Epsilon and used to create error bounds

	for(n = 0;n < nmax; n++)
	{
		// Derivative
		fp = fd(xi);

		// Check if derivative is too small
		if(abs(fp) < delta)
		{
			cout << "Derivative too small" << endl;
			return;
		}
		d = fx/fp;
		xi = xi - d;
		
		// assign f(x) to use
		fx = f(xi);

		if(abs(d) < epsilon)
		{
			cout << "Convergence" << endl;
			cout << "x =" << xi << endl;
			return;
		}
		
	}
	cout << "After " << nmax << " iterations x = " << xi << endl;
}

// Secant Function

int main()
{
	/*
	f(x) = x^3 -5x + 3 = 0
	x0 = -3, x1 = 3
	*/
 
	//system("pause");
	return 0;
}
