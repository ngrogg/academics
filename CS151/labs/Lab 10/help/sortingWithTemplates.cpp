/*
File: sortingWithTemplates.cpp
Michael R. Peterson
10/19/2011
For CS 151

This file is based on examples 17.1 - 17.3 in Savitch, Problem Solving with C++, 8th ed.
This file demonstrates use of templates to create a generic sort function that can be
used to sort arrays containing any data type, as long as that data type is comparable (i.e.
the < operator is defined for that type).
*/

#include <iostream>
using namespace std;

/********************************************************************************
* Functions employing templates.  We are including the function declaration and *
* definition together to ensure compatibility with more compilers.  Templates   *
* can be wonky with some compilers. Such compilers do not allow seperate        *
* compilation of templates, so we make sure the function declaration and        *
* definition appear together, in the file where they will be used.              *
*********************************************************************************/

// swap two values of the same data type
template<class T>
void swap_values(T& variable1, T& variable2)
{
	T temp;

	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

// helper function for the sort function that identifies the index of the smallest
// value within an array
template<class BaseType>
int index_of_smallest(const BaseType a[], int start_index, int number_used)
{
	BaseType min = a[start_index];
	int index_of_min = start_index;

	// use a loop to find the smallest value in the given range
	for(int index = start_index + 1; index < number_used; index++)
	{
		if(a[index] < min)
		{
			min = a[index];
			index_of_min = index;
			// min is now the smallest of a[start_index] through a[index]
		}
	}

	// min is now the smallest of a[start_index] through a[number_used-1]
	return index_of_min;
}

// function that sorts an array of any comparable type
// remember, the array is implicitly passed by reference
// number_used indicates how many cells of the array, counting from the beginning,
// contain data to be sorted
template<class BaseType>
void sort(BaseType a[], int number_used)
{
	int index_of_next_smallest;
	for(int index = 0; index < number_used - 1; index++)
	{
		// place the correct value in a[index]
		index_of_next_smallest = index_of_smallest(a,index,number_used);
		swap_values(a[index], a[index_of_next_smallest]);
		// at this point, a[0] <= a[1] <=...<= a[index] are the smallest of
		// the original array elements.  The remaining elements still need to
		// be sorted.
	}
	// now, all the elements are sorted.
}

/********************************************************************************
* Main function to demonstrate sorting of arrays of different base data types   *
* using the functions defined above.                                            *
*********************************************************************************/

int main()
{
	// example 1: sort some integers
	int i;
	int intArr[10] = {9, 8, 7, 6, 5, 1, 2, 3, 0, 4};
	cout << "Unsorted integers:" << endl;
	for(i = 0; i < 10; i++)
	{
		cout << intArr[i] << " ";
	}
	cout << endl;
	sort(intArr, 10);
	cout << "After sorting the integers:" << endl;
	for(i = 0; i < 10; i++)
	{
		cout << intArr[i] << " ";
	}
	cout << endl << endl;

	// example 2: sort some doubles
	double doubleArr[5] = {5.5,3.3, 4.4, 2.2, 1.1};
	cout << "Unsorted doubles:" << endl;
	for(i = 0; i < 5; i++)
	{
		cout << doubleArr[i] << " ";
	}
	cout << endl;
	sort(doubleArr, 5);
	cout << "After sorting the doubles:" << endl;
	for(i = 0; i < 5; i++)
	{
		cout << doubleArr[i] << " ";
	}
	cout << endl << endl;

	// example 3: sort some chars
	char charArr[7] = {'G', 'E', 'N', 'E', 'R', 'I', 'C'};
	cout << "Unsorted chars:" << endl;
	for(i = 0; i < 7; i++)
	{
		cout << charArr[i] << " ";
	}
	cout << endl;
	sort(charArr, 7);
	cout << "After sorting the chars:" << endl;
	for(i = 0; i < 7; i++)
	{
		cout << charArr[i] << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}