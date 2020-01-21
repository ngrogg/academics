#include "location.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

		//constructor
Location::Location()
{
xlocation = 1; 
ylocation = 2; 
}

		//location accessors
int Location::getxlocation()
{
return xlocation;
}

int Location::getylocation()
{
return ylocation;
}

int Location::getlocationproperty(int x, int y)
{
property = location_array[x][y];
return property;

}

		//location mutators
void Location::setxlocation(int x)
{
xlocation = x;
}

void Location::setylocation(int y)
{
ylocation = y;
}

void Location::setlocationproperty(int x, int y, int p)
{
	location_array[x][y] = p;
}

		//sets up array for map
void Location::setmap(int m)
{

//loops inside loops to read a data file and assign 

//y values first
//x values in nested for loop

if (m == 1)
{
std::ifstream instream;
instream.open("unixmap.txt");

for(int count2 = 0; count2 < 7; count2++)
{
	for(int count1 = 0; count1 < 13; count1++)
	{
	instream >> location_array[count1][count2];
	}
}

instream.close();
}

//if (m = 2)
//{

//}

}
