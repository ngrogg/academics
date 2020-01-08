#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// Define functions
double f(double x)
{
	double a = pow(x,3) - 2*pow(x,2) + x -3;
	return a;
}

// derivative f'(x)
double fd(double x)
{
	double a = 3*pow(x,2) - 4*x;
	return a;
}

double g(double x)
{
	double a = pow(x,4) + 2*pow(x,3) - 7*pow(x,2) + 3;
	return a;
}

// derivate g'(x)
double gd(double x)
{
	double a = 4*pow(x,3) + 6*pow(x,2) - 14*x;
	return a;
}

double h(double x)
{
	double a = pow(x,3) - 2*x - 5;
	return a;
}

double hd(double x)
{
	double a = 3*pow(x,2) -2;
	return a;
}


void Newton(double xi, double fx, char a)
{
	int n,nmax = 5;
	double d, delta = .001,epsilon = .001,fp;

	// Delta and Epsilon and used to create error bounds

	for(n = 0;n < nmax; n++)
	{
		// Choose which derivative to use
		if(a == 'f')
		{
			fp = fd(xi);
		}
		else if (a == 'g')
		{
			fp = gd(xi);
		}
		else 
		{
			fp = hd(xi);
		}

		// Check if derivative is too small
		if(abs(fp) < delta)
		{
			cout << "Derivative too small" << endl;
			return;
		}
		d = fx/fp;
		xi = xi - d;
		
		// choose which f(x) to use
		if(a == 'f')
		{
			fx = f(xi);
		}
		else if (a == 'g')
		{
			fx = g(xi);
		}
		else 
		{
			fx = h(xi);
		}

		if(abs(d) < epsilon)
		{
			cout << "Convergence" << endl;
			cout << "x =" << xi << endl;
			return;
		}
		
	}
	cout << "After " << nmax << " iterations x = " << xi << endl;
}

int main()
{
	// f(x) = x^3 + 2x^2 + x-3, x0 =3
	double fx = f(3);
	Newton(3,fx,'f');

	// g(x) = x^4 + 2x^3 + 7x^2 + 3, x0 =1
	double gx1 = g(1);
	Newton(1,gx1,'g');
	
	// g(x) = x^4 + 2x^3 + 7x^2 + 3, x0 =2
	double gx2 = g(2);
	Newton(2,gx2,'g');

	// h(x) = x^3 - 2x -5, x = 2.5 
	// graph shows 2.095, want greater than
	double hx = h(2.5);
	Newton(2.5,hx,'h');
	
	system("pause");
	return 0;
}
