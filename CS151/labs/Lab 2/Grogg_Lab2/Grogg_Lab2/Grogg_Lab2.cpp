/*
Nicholas Grogg
CS 151
Lab 2
*/

#include <iostream>
#include <cstdlib>
#include "Grogg_Lab2.h"

using namespace std;

		//define class for program
class Pedometer
{

private:
		//number of steps variable
	int nsteps;

		//length of stride variable
	int nstride;

public:

	void Set_Step(int s);
	void Set_Stride(int s);
	
	int Get_Step();
	int Get_Stride();

	Pedometer();
	Pedometer(int ste, int str);
/*
	Reset
	Increment
*/
};

int main()
{



system("pause");
return 0;
}
