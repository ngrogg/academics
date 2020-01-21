#ifndef DATE_H
#define DATE_H

class Date
{
protected:
	int dy;
	int mon;
	int yr;
public:
		//empty constructor
	Date()
	{}
		//accessors
	int GetDay()
	{return dy;}
	int GetMonth()
	{return mon;}
	int GetYear()
	{return yr;}

};
#endif
