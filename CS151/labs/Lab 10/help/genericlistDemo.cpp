/*
File: genericlistDemo.cpp
Michael R. Peterson
10/19/2011
For CS 151
From Savitch, Problem Solving with C++, 8th ed. Display 17.5
File to demonstrate the use of the generic list.  Note that we
are including BOTH the .h and .cpp files containing the generic list
declaration and implementation
*/

#include <iostream>
#include "genericList.h"
#include "genericList.cpp"


using namespace std;
using namespace CS151GenericList;

int main()
{
	// first example: create a list containing only ints
	GenericList<int> first_list(5);
	first_list.add(2);
	first_list.add(4);
	first_list.add(8);
	first_list.add(16);
	cout << "first_list = " << endl;
	cout << first_list;
	cout << endl;

	// second example: create a list containing only chars
	GenericList<char> second_list(5);
	second_list.add('H');
	second_list.add('e');
	second_list.add('l');
	second_list.add('l');
	second_list.add('o');
	cout << "second_list = " << endl;
	cout << second_list;
	cout << endl;

	system("pause");
	return 0;
}