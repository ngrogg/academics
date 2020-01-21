// Specification file for the DateTime Class
#ifndef DATETIME_H
#define DATETIME_H

// we need to include both the date and time classes
#include "Date.h"
#include "Time.h"
#include<string>
using namespace std;

class DateTime : public Date, public Time
{
protected:
	string dateTimeString;
public:
	DateTime(int d, int mn, int y, int h, int mt, int s); // Overloaded Constructor

	const string getDateTime()
	{
		return dateTimeString;
	}
}; // End DateTime Frankenclass

#endif
