#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	/*
	 Attempting to run the program with 

	 0x + 1y = 1
	 x + y = 2

	 ends up with division by zero.
	 */

	const int row=4; 
	const int col=4;
	int k;

	double xmult, summ;
	
	// Initialize double array
	double a[row][col];

	// right hand side array is the size of the number of rows, one answer for each variable
	double b[row]; 

	// Initialize solution array
	double xa[row];

	
	// Fill 2d matrix
	
	a[0][0] = 6;  a[0][1] = -2;  a[0][2] = 2; a[0][3] = 4;
	a[1][0] = 12; a[1][1] = -8;  a[1][2] = 6; a[1][3] = 10;
	a[2][0] = 3;  a[2][1] = -13; a[2][2] = 9; a[2][3] = 3;
	a[3][0] = -6; a[3][1] = 4;   a[3][2] = 1; a[3][3] = 18;

	// Fill right hand matrix
	b[0] = 16; b[1] = 26; b[2] = -19; b[3] = -34;

	// Part 1, forward elimination
 	for(k=0; k<row-1; k++) //for k=1 to n-1 
	{
		for(int i=k+1; i<row; i++)//i=k+1 to n
		{
			xmult = (a[i][k])/(a[k][k]);
			a[i][k] = xmult;

			for(int j=k+1; j<row; j++) //j=k+1 to n
			{
				a[i][j] = a[i][j] - (xmult * a[k][j]);
			}
			b[i] = b[i] - (xmult * b[k]);
		}
	}

	// Set initial value
	xa[col-1] = (b[row-1])*(a[row-1][col-1]); 
	
	//  Part 2, Back Substitution
	for(int i=row-1; i>=0; i--) // For i=n-1 to 1
	{
		summ = b[i];
		for(int j=i+1; j<row; j++) // For j = i+1 to n
		{
			summ = summ - ((a[i][j]) * (xa[j]));
		}
		xa[i] = (summ) / (a[i][i]);
	}

	// output
	for(int count=0;count<col;count++)
	{
		cout << "array x row " << count + 1 << " " << xa[count] << endl;
	}

	//system("pause");
	return 0;
}
