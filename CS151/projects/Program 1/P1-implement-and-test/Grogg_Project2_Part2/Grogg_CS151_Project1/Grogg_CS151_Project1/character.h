#pragma once

#ifndef Character_h
#define Character_h
class Character
{
private:

		//character variables
	bool keepplaying;
	bool winner; 
	int score;
	int turnsremaining;
	string name;

		//character inventory variables
	bool bronzekey;
	bool goldkey;
	bool silverkey;
	bool gkeyhint;
	bool skeyhint;
	bool bkeyhint;

public:

		//default constructor
	Character();

		//character accessors
	int getscore();
	int getturns();
	int getname();
	void lookfunc();

		//character mutators
	void helpfunction();
	void setname(string n);
	void setplaystate();
	void setscore(int);
	void setturnsleft(int);
	void setwinstate();
	
		//inventory accessors
	void getinventory();

		//inventory mutators
	void setinventory(int);

};
#endif
