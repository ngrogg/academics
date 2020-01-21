#include <iostream>
#include <cstdlib>

using namespace std;

		//Problem 1 function
		//Interchanges the values of variable1 and variable2.
template<class T, class U>
void swap_values(T& variable1, U& variable2)
{
      T temp;

      temp = variable1;
      variable1 = variable2;
      variable2 = temp;
}

		//Problem 2 function
		//Finds minimum value and position in an array
template<class T>
void find_min(T array[], int size)
{

int indexofmin;
T minimum = array[0];
for(int count = 1; count < size; count++)
{
	if(array[count] < minimum)
	{
		minimum = array[count];
		indexofmin = count+1;
	}
}

cout << "minimum value " << minimum << " at array element " << indexofmin << endl;

}

		//Problem 3 function
		//Template class

template<class T1, class T2>
class numbers
{
public:

		//constructor
	numbers();

		//mutators
	void setnumber1(T1 n1);
	void setnumber2(T2 n2);

private:
		//template numbers
	T1 number1;
	T2 number2;
		
		//overloaded << operator
	friend ostream& operator <<(ostream& outs, numbers n)
	{
		outs << n.number1 << " " << n.number2 << endl;
		return outs;
	} 
};


int main()
{

		//Problem 1: You shouldn't be doing this

cout << "Lab 10, Problem 1." << endl;


		//default values for int, char and double
int intvar = 1701;
char charvar = 3;
double doublevar = 302.360;

		//output default values
cout << "Default values " << endl;
cout << "int variable = " << intvar << endl;
cout << "char variable  = " << charvar << endl;
cout << "doubl variable = " << doublevar << endl;

		//switch int and char, output results, and revert to default values
cout << "Switching int and char" << endl;
swap_values(intvar, charvar);
cout << "int variable = " << intvar << endl;
cout << "char variable = " << charvar << endl;
intvar = 1701;
charvar = 3;

		//switch int and double, output results, and revert to default values
cout << "Switching int and double" << endl;
swap_values(intvar, doublevar);
cout << "int var = " << intvar << endl;
cout << "double var = " << doublevar << endl;
intvar = 1701;
doublevar = 302.360;

		//switch char and double, output results, and revert to default values
cout << "Switching char and double" << endl;
swap_values(charvar, doublevar);
cout << "char variable = " << charvar << endl;
cout << "double var = " << doublevar << endl;
charvar = 3;
doublevar = 302.360;

		//Problem 2: Find min

		//size for various arrays, int, double, char
int isize;
int dsize;
int csize;

cout << "Lab 10, part 2" << endl;

		//declare size of arrays
cout << "Please enter a size for int array: ";
cin >> isize;
cout << "Please enter a size for double array: ";
cin >> dsize;
cout << "Please enter a size for int array; ";
cin >> csize;

		//while loop verification(s)
while(isize < 2 || isize > 10)
{cout << "try again: ";cin >> isize;}
while(dsize < 2 || dsize > 10)
{cout << "try again: ";cin >> dsize;}
while(csize < 2 || csize > 10)
{cout << "try again: ";cin >> csize;}

		//create arrays
int iarray[isize];
double darray[dsize];
char carray[csize];

		//user enters data into arrays
for(int count = 0; count < isize; count++)
{
cout << "int array element " << count + 1 << " : ";
cin >> iarray[count];
}
for(int count = 0; count < dsize; count++)
{
cout << "double array element " << count + 1 << " : ";
cin >> darray[count];
}
for(int count = 0; count < csize; count++)
{
cout << "char array element " << count + 1 << " : ";
cin >> carray[count];
}

cout << endl;
cout << "Finding minimum values" << endl;

		//find min
find_min(iarray,isize);
find_min(darray,dsize);
find_min(carray,csize);

		//Problem 3: A template class

cout << "Problem 3" << endl;

		//variables for problem 3
int in1 = 21;
double dn2 = 4.2;
char cn3 = '9';

		//create classes
numbers<int,double> first_class;
numbers<double,char> second_class;
numbers<double,int> third_class;

		//assign numbers to class
first_class.setnumber1(in1);
first_class.setnumber2(dn2);
second_class.setnumber1(dn2);
second_class.setnumber2(cn3);
third_class.setnumber1(dn2);
third_class.setnumber2(in1);

		//output numbers of classes
cout << "Classes: " << endl;
cout << first_class << endl;
cout << second_class << endl;
cout << third_class << endl;

system("pause");
return 0;	
}

template<class T1, class T2>
numbers<T1,T2>::numbers()
{
	
}

template<class T1, class T2>
void numbers<T1,T2>::setnumber1(T1 n1)
{
	number1 = n1;
}

template<class T1, class T2>
void numbers<T1,T2>::setnumber2(T2 n2)
{
	number2 = n2;
}
