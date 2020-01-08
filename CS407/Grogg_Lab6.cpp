#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void Gauss( vector < vector <double> > a, int ai, int aj, vector<int> &L) //vector,row,col
{
	// Instantiate variables
	double r,rmax,smax,xmult;
	int j,k;
	int n=ai-1; 

	// S answer array
	double S[ai];
		
	for(int i =0; i<n;i++)
	{
		L[i] = i;
		smax = 0;
		for(int j=0; j<n;j++)
		{
			smax = max(smax, abs(a[i][j]));
		}
		S[i] = smax;
	}

	for(k = 0; k < n-1; k++)
	{
		rmax = 0;
		for(int i = k; i < n; i++)
		{
			r = abs((a[L[i]][k])/(S[L[i]]));
			if(r > rmax)
			{
				rmax = r;
				j = i;
			}
		}

		swap(L[j], L[k]);

		for(int i = k + 1; i < n; i++)
		{
			xmult = (a[L[i]][k])/(a[L[k]][k]);
			a[L[i]][k] = xmult;
			for(j = k+1; j < n; j++)
			{
				a[L[i]][j] = a[L[i]][j] - (xmult * a[L[k]][j]);
			}
		}

	}

}

void Solve(vector<vector<double> > a, vector<int> L, int ai, int aj)
{
	double sum;
	int k;
	int n = ai-1;

	double x[ai];
	double b[ai];

	// Solve procedure	
	for (k = 0; k < n; k++)
	{	
		for (int i = k+1; i < n; i++)
		{
			b[L[i]] = b[L[i]] - (a[L[i]][k] * b[L[k]]);

		}
	}	

	x[n-1] = b[L[n-1]] / a[L[n-1]][n-1];

	for(int i = n-1; i > -1; i--)
	{
		sum = b[L[i]];
		for(int j = i+1; j < n; j++)
		{
			sum = sum - (a[L[i]][j] * x[j]);
		}

		x[i] = sum/a[L[i]][i];
	}

	// output answer x array

	for(int i = 0; i<=n;i++)
	{
		cout << "Answer #" << i+1 << " = " << x[i] << endl;
	}
}

	

int main()
{
	vector<vector<double> > a1{ { 1, -1, 2},
				   {-2, 1, -1},
				   {4, -1, 2 } };

	vector<vector<double> > a2{ {0,1}, 
		 	  	   {1,1}};
	
	vector<vector<double> > a3{ { .4096, .1234, .3678, .2943, .4043},
				   { .2246, .3872, .4015, .1129, .1550},
			           { .3645, .1920, .3781, .0643, .4240},
				   { .1784, .4002, .2786, .3927, .2557} };


	vector<int> L1{0,0,0};
	vector<int> L2{0,0};
	vector<int> L3{0,0,0,0};

	// Gauss arrays
	Gauss(a1,3,3,L1);
	Gauss(a2,2,2,L2);
	Gauss(a3,5,4,L3);

	// Solve arrays	
	cout << "Solving array 1" << endl;
	Solve(a1,L1,3,3);
	
	cout << "Solving array 2" << endl;
	Solve(a2,L2,2,2);
	
	cout << "Solving array 3" << endl;
	Solve(a3,L3,5,4);

	//system("pause");
	return 0;

}
