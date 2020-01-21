#ifndef TIME_H
#define TIME_H

class Time
{
protected:
	int hr;
	int mt;
	int sec;
public:
		//Empty Constructor
	Time()
	{}	
		//accessors
	int GetHour()
	{return hr;}
	int GetMinute()
	{return mt;}
	int GetSecond()
	{return sec;}

};

#endif
