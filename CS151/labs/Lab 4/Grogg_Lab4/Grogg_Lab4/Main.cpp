//Sorts a list of numbers entered at the keyboard.
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
//Precondition: size is the size of the array a.
//Postcondition: a[0] through a[size-1] have been
//filled with values read from the keyboard.

void sort(int a[], int size);
//Precondition: size is the size of the array a.
//The array elements a[0] through a[size-1] have values.
//Postcondition: The values of a[0] through a[size-1] have been rearranged
//so that a[0] <= a[1] <= ... <= a[size-1].

void swap_values(int& v1, int& v2);
//Interchanges the values of v1 and v2.

int index_of_smallest(const int a[], int start_index, int number_used);
//Precondition: 0 <= start_index < number_used. References array elements have 
//values.
//Returns the index i such that a[i] is the smallest of the values
//a[start_index], a[start_index + 1], ..., a[number_used - 1].


int main()
{
	cout << "This program sorts numbers from lowest to highest.\n";

	int array_size;
	cout << "How many numbers will be sorted? ";
	cin >> array_size;

	IntArrayPtr a;
	a = new int[array_size];

	fill_array(a, array_size);
	sort(a, array_size);

	cout << "In sorted order the numbers are:\n";
	for (int index = 0; index < array_size; index++)
		cout << a[index] << " ";
	cout << endl;

	system("pause");
	delete[] a;
	system("pause");

	return 0;
}

//Uses the library iostream:
void fill_array(int a[], int size)
{
	using namespace std;
	cout << "Enter " << size << " integers.\n";
	for (int index = 0; index < size; index++)
		cin >> a[index];
}


//begin definition

		//Selection Sort using nested for loops
		//O(n^2) time complexity for all scenarios
void sort(int a[], int size)
{

		//Minimum value integer
int minval;

for (int count = 0; count < (size -1); count++)
{
	
minval = index_of_smallest(a, count, size);

for (int count2 = count + 1; count2 < size; count2++)
{

if (a[count2] < a[minval])
{minval = count2;}

}

if (minval != count)
{swap_values(a[count],a[minval]);}
}
}

//end function definition

void swap_values(int& v1, int& v2)
{

int temp = v1;
v1 = v2;
v2 = temp;

}

int index_of_smallest(const int a[], int start_index, int number_used)
{

		//minimum value
int minval = a[start_index];

for(int count = start_index + 1; count < number_used; count++)
{

if(a[count] < minval)
{
minval = a[count];
}

}

return minval;

}
