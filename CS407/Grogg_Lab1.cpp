#include <iostream>
#include <cstdlib> 
#include <string>
#include <cmath>

/*
 * Part 2 deals with precision and the margin of error of a derivative.
 * The precision exceeds the capability of the data type and the error 
 * grows as Delta E is exceeded.
 * */
using namespace std;

// Function to solve and return Horner's algorithm
// Form  polynomial[0]*(n-1) + polynomial[1]*(n-2) +...+ polynomial[n-1]
int Horner_Algorithm(int polynomial[], int x, int size)
{

	// result to return
	int result = polynomial[0];

	// Calculate value, start at 1 to ignore initial result
	for(int count = 1;count < size; count++)
	{
		result = (result * x) + polynomial[count];
	}

	return result;
}

int main()
{
	cout << "CS407 Lab 1 Part 1" << endl;

	cout << "Solving p(x) = 2x4 + 9x2 - 16x + 12 at p(-6)" << endl;

	// Initialize Variables
	int P1_1[] = {2, 0, 9, -16, 12};
	int P1_x1 = -6;
	int P1_size1 = sizeof(P1_1)/sizeof(P1_1[0]);

	// Calculate answer and output
	cout << "Solution is " << Horner_Algorithm(P1_1, P1_x1, P1_size1) << endl;

	cout << "Solving p(x) = 2x4 - 3x3 - 5x2 + 3x + 8 at p(2)" << endl;

	// Initialize Variables
	int P1_2[] = {2, -3, -5, 3, 8};
	int P1_x2 = 2;
	int P1_size2 = sizeof(P1_2)/sizeof(P1_2[0]);

	// Calculate answer and output
	cout << "Solution is " << Horner_Algorithm(P1_2, P1_x2, P1_size2) << endl;

	cout << endl;
	cout << "CS407 Lab 1 Part 2" << endl;
	// Page 10 of my text

	int i, imax, n = 30;
	long double error, y, x = 0.5, h = 1, emax = 0;
	
	for (i = 0; i<n; i++)
	{
		h = h * 0.25;
		y = (sin(x+h) - sin(x))/h;
		error = fabs(cos(x) - y);
		cout << "i = " << i << " h = " << h << " y = " << y << " error = " << error << endl;
	}	

	if(error > emax)
	{
		emax = error;
		imax = i;
	}

	cout << "imax = " << imax << " emax = " << emax << endl;

	cout << endl;
	cout << "CS407 Lab 1 Part 3" << endl;

	// Arrays of strings to hold variants of name
	string namept1[5] = {"Cheb","Q","Ceb","Tscheb","Tcheb"};
	string namept2[2] = {"y","i"};
	string namept3[6] = {"shev","wev","schef","cev","cheff","scheff"};

	// For keeping track of how many spellings in total there are
	int total = 0;

	// Enumerate and output the possible values
	for(int count1 = 0;count1 < 5;count1++)
	{
		for(int count2 = 0;count2 < 2;count2++)
		{
			for(int count3 = 0;count3 < 6;count3++)
			{
				cout << namept1[count1] << namept2[count2] << namept3[count3] << endl;
				total+=1;
			}
		}
	}
	cout << "There are " << total << " possible spellings" << endl;
}
