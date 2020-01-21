#include "character.h"


		//default constructor
Character()
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
int getscore()
{
return score;
}

int getturns()
{
return turnsremaining;
}

int getname()
{
return name;
}
void lookfunc()
{

}

		//character mutators
void helpfunction()
{

}
void setname(string n)
{
name = n;
}
void setplaystate()
{

}
void setscore(int)
{

}
void setturnsleft(int)
{

}
void setwinstate()
{

}
	
		//inventory accessors
void getinventory()
{

}

		//inventory mutators
void setinventory(int)
{

}

