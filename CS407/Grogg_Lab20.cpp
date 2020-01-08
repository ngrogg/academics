#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
 The data changes by becoming more angular
 with the graphs minimum and maximum getting farther apart
 and more extreme.
 */

void BSpline2_Coef(int n, double t[], double y[], double h[], double a[])
{
	int i;
	double d,v,p,q,r;

	for(i = 1; i < n; i++)
	{
		h[i] = t[i]-t[i-1];
	}
	h[0] = h[1];
	h[n] = h[n-1];
	d = -1;
	v = 2*y[0];
	p = d*v;
	q = 2;
	
	for(i = 1; i < n;i++)
	{
		r = h[i+1]/h[i];
		d = (-1*r)*d;
		v = (-1*r)*v + (r+1)*y[i];
		p = p + v*d;
		q = q + pow(d,2);
	}
	a[0] = (-1*p)/q;
	for(i = 1; i <= n; i++)
	{
		a[i] = ((h[i-1]+h[i])*y[i-1]-(h[i]*a[i-1]))/h[i-1];
	}

}

void BSpline2_Eval(int n, double t[], double a[], double h[], double x)
{
	int i,counter;
	double d,e;
	double answer;

	for(counter = n-2; counter > -1; counter--)
	{
		if(x - t[counter] >= 0)
		{
			return;
		}
	
	i = counter + 1;
	d = (a[i+1]*(x - t[i-1]) + a[i]*(t[i] - x + h[i+1]))/(h[i]+h[i+1]);
	e = (a[i]*(x-t[i-1]+h[i-1]) + a[i-1]*(t[i-1] - x + h[i]))/(h[i-1]+h[i]);
	answer = (d*(x-t[i-1])+e*(t[i]-x))/h[i];
	cout << "Answer = " << answer << endl;
	}
}

int main()
{

	// Instantiate arrays and variables
	int n = 8;
	double t[8] = {0,1,2,3,4,5,6,7};
	double y[8] = {1.0, 1.5, 1.6, 1.5, .9, 2.2, 2.8, 3.1};
	double a[8];
	double h[8];
	double x = 0.01; // x value to change

	BSpline2_Coef(n,t,y,h,a);
	BSpline2_Eval(n,t,a,h,x);
	//system("pause");
	return 0;
}
