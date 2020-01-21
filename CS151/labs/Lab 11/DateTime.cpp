#include <iostream>
#include <cstdlib>
#include <string>

#include "DateTime.h"

DateTime::DateTime(int d, int mn, int y, int h, int mt, int s)
{
	dy	= d;
	mon	= mn;
	yr	= y;
	hr	= h;
	mn	= mt;
	sec	= s;

	dateTimeString = "User entered time = "  + to_string(hr) + ":" + to_string(mn) + ":" + to_string(sec) + " " + to_string(mon) + "-" + to_string(dy) + "-" + to_string(yr);
}
