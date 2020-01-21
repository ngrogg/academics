#include "character.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

		//default constructor
Character::Character()
{
keepplaying = true;
winner = false; 
score = 0;

		//character inventory variables
bronzekey = false;
goldkey = false;
silverkey = false;
gkeyhint = false;
skeyhint = false;
bkeyhint = false;

}

		//character accessors
int Character::getscore()
{
return score;
}

int Character::getturns()
{
return turnsremaining;
}

std::string Character::getname()
{
return name;
}

bool Character::getplaystate()
{
return keepplaying;
}

bool Character::getwinstate()
{
return winner;
}

void Character::helpfunction()
{
cout << "Escape the sinking ship before time runs out" << endl;
cout << "Commands are not case sensitive" << endl;
cout << "Move forward & move Forward both work" << endl;
cout << " " << endl;
cout << "Move" << endl;
cout << "Move + forward/backward/left/right to move" << endl;
cout << " " << endl;
cout << "Quit" << endl;
cout << "Exits the game" << endl;
cout << " " << endl;
cout << "Clear" << endl;
cout << "Clears the screen" << endl;
cout << " " << endl;
cout << "Look" << endl;
cout << "X + Y location + location properties and turns remaining in game" << endl;
cout << " " << endl;
cout << "Inventory" << endl;
cout << "Output current inventory" << endl;
cout << " " << endl;
cout << "Get + item " << endl;
cout << "Get item (if possible) " << endl;
cout << "Example: Get collectible or Get Key" << endl;
cout << "Items are used automatically" << endl;
cout << " " << endl;
cout << "Score" << endl;
cout << "Output current score" << endl;
cout << " " << endl;
cout << "Win" << endl;
cout << "Win the game (if exit present)" << endl;
cout << " " << endl;
}
		//character mutators
void Character::setname(string n)
{
name = n;
}

void Character::setplaystate()
{
keepplaying = false;
}

void Character::setscore(int s)
{
score = score + s;
}

void Character::settotalturns(int t)
{

if (t == 1)
{
turnsremaining = 60;
}

else if (t == 2)
{
turnsremaining = 55;
}

else if (t == 3)
{
turnsremaining = 50;
}

else
{
turnsremaining = 45;
}
}

void Character::setturnsleft(int t)
{
	turnsremaining = turnsremaining - t;
}

void Character::setwinstate()
{
winner = true;
score += 1;
}

void Character::clearscreen()
{
system("cls");
}
	
		//inventory accessors
bool Character::checkinventory(int c)
{
	if (c == 3)
	{
		if (goldkey == true)
		{return true;}
		else
		{return false;}
	}
	
	if (c == 2)
	{
		if (silverkey == true)
		{return true;}
		else
		{return false;}
	}
	if (c == 1)
	{
		if (bronzekey == true)
		{return true;}
		else
		{return false;}
	}	
	return 1;
}
void Character::getinventory()
{
cout << "You have " << endl;
if(bronzekey == true)
{
cout << "The bronze key" << endl;
}

if(silverkey == true)
{
cout << "The silver key" << endl;
}

if(goldkey == true)
{
cout << "The gold key" << endl;
}

if(bkeyhint == true)
{
cout << "hint for 3,5" << endl;
}

if(skeyhint == true)
{
cout << "hint for 8,3" << endl;
}

if(gkeyhint == true)
{
cout << "hint for 9,5" << endl;
}
}

		//inventory mutator
void Character::setinventory(int i)
{
if(i == 1)
{
bronzekey = true;
}

if(i == 2)
{
silverkey = true;
}

if(i == 3)
{
goldkey = true;
}

if(i == 4)
{
cout << "Bronze hint: 3,5" << endl;
bkeyhint = true;
}

if(i == 5)
{
cout << "Silver hint: 7,4" << endl;
skeyhint = true;
}
if(i == 6)
{
cout << "Gold hint: 8,1" << endl;
gkeyhint = true;
}
}


