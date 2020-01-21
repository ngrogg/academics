#include <string>
#include <cstdlib>

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
	std::string name;

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
	std::string getname();
	bool getplaystate();
	bool getwinstate();

		//character mutators
	void helpfunction();
	void setname(std::string n);
	void setplaystate();
	void setscore(int s);
	void settotalturns(int t);
	void setturnsleft(int t);
	void setwinstate();
	void clearscreen();

		//inventory accessors
	void getinventory();
	bool checkinventory(int c);

		//inventory mutators
	void setinventory(int i);

};
#endif
