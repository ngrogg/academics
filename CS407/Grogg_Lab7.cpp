#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

void Tri(int n, vector<double>a, vector<double>d, vector<double>c, vector<double>b, vector<double>x)
{
	// Instantiate variables
	int i;
	double xmult;

	// Solve vector
	for(i = 1; i < n; i++)
	{
		xmult = a[i-1]/d[i-1];
		d[i] = d[i] -(xmult * c[i-1]);
		b[i] = b[i] -(xmult * b[i-1]);
	}

	x[n-1] = b[n-1]/d[n-1];
	
	for(i = n-2;i > -1;i--)
	{
		x[i] = (b[i] - (c[i]*x[i+1]))/d[i];
	}
	
	// Output solution
	for(int count = 0; count < n; count++)
	{
		cout << "x #" << count+1 << " = " <<  x[count] << endl;
	}
}

int main()
{
	int n = 100;

	// Create Vectors
	vector<double> a1 (n,.5); vector<double> a2 (n,1);
	vector<double> b1 (n,2);  vector<double> b2 (n,40);
	vector<double> c1 (n,.5); vector<double> c2 (n,1);
	vector<double> d1 (n,1);  vector<double> d2 (n,-4);
	vector<double> x1 (n,0);  vector<double> x2 (n,0);

	// Fill unique value vectors
	b1[0] = 1.5; b1[99] = 1.5;
	a2[99] = -1; 
	b2[0] = -20; b2[99] = -20;
	c2[0] = -1;
	d2[0] = 4; d2[99] = 4;

	// Solve matrices with Tri
	Tri(n,a1,d1,c1,b1,x1);
	Tri(n,a2,d2,c2,b2,x2);
	
	/*
	 Due to rounding, the answers start pretty accurate and get 
	 very inaccurate as the program goes on.
	 */
	system("pause");
	return 0;
}
