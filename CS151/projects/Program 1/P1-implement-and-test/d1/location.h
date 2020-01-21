#pragma once

#ifndef Location_h
#define Location_h
class Location
{
private:
		//array x and y variables
	int xlocation;
	int ylocation;
		
		//array location property
	int property;

		//location array
	int location_array[13][7];

public:

		//constructor
	Location();

		//location accessors
	int getxlocation();
	int getylocation();
	int getlocationproperty(int x, int y);

		//location mutators
	void setxlocation(int x);
	void setylocation(int y);
	void setlocationproperty(int x, int y, int p);

		//sets up array for map
	void setmap(int m);
};
#endif
