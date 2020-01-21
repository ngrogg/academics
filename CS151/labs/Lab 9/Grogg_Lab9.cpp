#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{

		//string for input
string input;

		//length of string for char array
int stringlength;

		//user enters data
cout << "Lab 9, enter data string for histogram: ";
cin >> input;

		//get length of string for array
stringlength = input.length();

		//array for char
char chararray[stringlength];
input.copy(chararray, stringlength + 1);
chararray[stringlength+1] = '\0';

		//int array
int intarray[stringlength];

		//text histogram
int scorearray[] = {0,0,0,0,0};

		//try block
try
{
for(int count = 0;count < stringlength;count++)
{
	if(!isdigit(chararray[count]))
	{
		//exit if error
		throw "bad data, try again with valid data";
	}
	else
	{
		//feed char array into int array
		intarray[count] = chararray[count] - 48;
	}
}
		//success message #1
		cout << "all your digits are belong to us" << endl;
for(int count = 0; count < stringlength;count++)
{
	if(intarray[count] < 1 || intarray[count] > 5)
	{throw "data out of range, exiting...";}
}
		//success message #2
		cout << "all your range are belong to us" << endl;

for(int count = 0; count < stringlength; count++)
{
	if(intarray[count] == 1)
	{scorearray[0]+=1;}
	if(intarray[count] == 2)
	{scorearray[1]+=1;}
	if(intarray[count] == 3)
	{scorearray[2]+=1;}
	if(intarray[count] == 4)
	{scorearray[3]+=1;}
	if(intarray[count] == 5)
	{scorearray[4]+=1;}

}

cout << endl;
cout << "Text Histogram" << endl;
cout << endl;

for(int count = 0; count < 5; count++)
{
	cout << "Assignments finished: " << count + 1 << " # of students: " << scorearray[count] << endl;
}

}

		//catch block 1
catch(const char* data)
{cout << data << endl;}

		//catch block 2
catch(const int* data2)
{cout << data2 << endl;}

		//text histogram

system("pause");
return 0;
}
