/*

Nicholas Grogg
CS151
Project 1
Sinking Feeling

*/

/* TO DO
					quit
					get collectible
					get key
					look
					move
Windows help file
					data into array
					clear
					win
					inventory
					score
*/

		//c++ files included
#include "character.h"
#include "character.cpp"
#include "location.h"
#include "location.cpp"

		//libraries included

#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
		//create constructors
Character You; 
Location Map;

		//enter character name
string name;
cout << "Who are you?" << endl;
getline(cin, name);
You.setname(name);

		//choose difficulty
int difficulty;

cout << "And how tough are ye " << You.getname() << "?" << endl;
cout << "1. I'm too young to remember Doom" << endl;
cout << "2. Krillin" << endl;
cout << "3. Tough enough to do this project" << endl;
cout << "4. l33t d0n't m4k3 m1st4k3s" << endl;
cout << "Please enter 1-4 to choose your difficulty: ";
cin >> difficulty;

while (difficulty >= 5 || difficulty <= 0)
{
cout << "The answer is not 42, it's between 1 and 4" << endl;
cout << "1-4" << endl;
cin >> difficulty;
}

You.settotalturns(difficulty);

		//Set up game map, change line endings for file
int ostype;

cout << "Are Ye usin' a UNIX based OS like Linux or Mac, or Windows " << You.getname() << "?" << endl;
cout << "1. Unix based" << endl;
cout << "2. Windows" << endl;
cin >> ostype;

while (ostype != 1 && ostype != 2)
{
cout << "enter 1 for Linux/Mac or 2 for Windows: ";
cin >> ostype;
}

Map.setmap(ostype);

		//Game main loop
string choice;
cin.ignore();

while ((You.getplaystate() && !You.getwinstate()) && You.getturns() > 0)
{

cout << "What would you like to do?" << endl;
getline(cin, choice);

if (choice == "Quit" || choice == "quit")
{
	You.setplaystate();
}

else if (choice == "Win" || choice == "win")
{
	if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 12)
	{You.setwinstate();}
	else
	{cout << "I wish..." << endl;}
}

else if (choice == "Clear" || choice == "clear")
{
	You.clearscreen();
}

else if (choice == "Inventory" || choice == "inventory")
{
	You.getinventory();
}

else if (choice == "Score" || choice == "score")
{
	cout << You.getscore() << endl;
}

else if (choice == "Look" || choice == "look")
{
	cout << "Location: " << "x: " << Map.getxlocation() << " y: " << Map.getylocation() << endl;
	
	if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 3 && !You.checkinventory(2)) 
	{cout << "I see a locked GOLD door." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 3 && You.checkinventory(1)) 
	{cout << "I see a locked GOLD door, and I've got the key!" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 4 && !You.checkinventory(2))
	{cout << "I see a locked SILVER door." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 4 && You.checkinventory(2))
	{cout << "I see a SILVER door, and I've got the key!" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 5 && !You.checkinventory(1))
	{cout << "I see a locked BRONZE door." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 5 && You.checkinventory(1))
	{cout << "I see a BRONZE door, and I've got the key!" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 6)
	{cout << "I see a GOLD key." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 7)
	{cout << "I see a SILVER key." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 8)
	{cout << "I see a BRONZE key." << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 9)
	{cout << "I see a GOLD collectible" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 10)
	{cout << "I see a SILVER collectible" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 11)
	{cout << "I see a BRONZE collectible" << endl;}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 12)
	{cout << "I see the EXIT" <<endl;}
	
	else
	{cout << "There's nothing remarkable here" << endl;}
	
	cout << "You have " << You.getturns() << " turns left" << endl;
}

		//Get item functions
else if ((choice == "Get Key" || choice == "get key") || (choice == "Get key" || choice == "get Key"))
{
	if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 6)
	{
		cout << "I got the GOLD key." << endl;
		You.setscore(30);
		You.setinventory(3);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);
	}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 7)
	{
		cout << "I got the SILVER key." << endl;
		You.setscore(20);
		You.setinventory(2);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);
	}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 8)
	{
		cout << "I got the BRONZE key." << endl;
		You.setscore(10);
		You.setinventory(1);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);
	}
	
	else
	{cout << "I can't do that" << endl;}
}

else if ((choice == "Get Collectible" || choice == "get collectible") || (choice == "Get collectible" || choice == "get Collectible"))
{
	if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 9)
	{
		cout << "I got the GOLD collectible." << endl;
		You.setscore(15);
		You.setinventory(6);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);
	}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 10)
	{
		cout << "I got the SILVER collectible." << endl;
		You.setscore(15);
		You.setinventory(5);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);	
	}
	
	else if (Map.getlocationproperty(Map.getxlocation(), Map.getylocation()) == 11)
	{
		cout << "I got the BRONZE collectible." << endl;
		You.setscore(15);
		You.setinventory(4);
		Map.setlocationproperty(Map.getxlocation(), Map.getylocation(), 1);
	}
	
	else
	{cout << "I can't do that" << endl;}
}

		//Move functions
else if ((choice == "Move Forward" || choice == "move forward") || (choice == "Move forward" || choice == "move Forward"))
{
	if ((Map.getlocationproperty(Map.getxlocation() , Map.getylocation() + 1) == 2) )
	{cout << "I can't go there" << endl;}

	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() + 1) == 3) && !You.checkinventory(3))
	{cout << "I don't have the gold key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() + 1) == 4) && !You.checkinventory(2))
	{cout << "I don't have the silver key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() + 1) == 5) && !You.checkinventory(1))
	{cout << "I don't have the bronze key" << endl;}
	
	else
	{ 
		Map.setylocation(Map.getylocation() + 1);
		You.setturnsleft(1);
	}
}

else if ((choice == "Move Backward" || choice == "move backward") || (choice == "Move backward" || choice == "move Backward"))
{
	if ((Map.getlocationproperty(Map.getxlocation() , Map.getylocation() - 1) == 2) )
	{cout << "I can't go there" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() - 1) == 3) && !You.checkinventory(3))
	{cout << "I don't have the gold key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() - 1) == 4) && !You.checkinventory(2))
	{cout << "I don't have the silver key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation(), Map.getylocation() - 1) == 5) && !You.checkinventory(1))
	{cout << "I don't have the bronze key" << endl;}
	
	else
	{ 
		Map.setylocation(Map.getylocation() - 1);
		You.setturnsleft(1);
	}	
}

else if ((choice == "Move Left" || choice == "move left") || (choice == "Move left" || choice == "move Left"))
{
	if ((Map.getlocationproperty(Map.getxlocation() - 1, Map.getylocation()) == 2) )
	{cout << "I can't go there" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() - 1, Map.getylocation()) == 3) && !You.checkinventory(3))
	{cout << "I don't have the gold key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() - 1, Map.getylocation()) == 4) && !You.checkinventory(2))
	{cout << "I don't have the silver key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() - 1, Map.getylocation()) == 5) && !You.checkinventory(1))
	{cout << "I don't have the bronze key" << endl;}
	
	else
	{ 
		Map.setxlocation(Map.getxlocation() - 1);
		You.setturnsleft(1);
	}	
}

else if ((choice == "Move Right" || choice == "move right") || (choice == "Move right" || choice == "move Right"))
{
	if ((Map.getlocationproperty(Map.getxlocation() + 1, Map.getylocation()) == 2) )
	{cout << "I can't go there" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() + 1, Map.getylocation()) == 3) && !You.checkinventory(3))
	{cout << "I don't have the gold key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() + 1, Map.getylocation()) == 4) && !You.checkinventory(2))
	{cout << "I don't have the silver key" << endl;}
	
	else if ((Map.getlocationproperty(Map.getxlocation() + 1, Map.getylocation()) == 5) && !You.checkinventory(1))
	{cout << "I don't have the bronze key" << endl;}
	
	else
	{ 
		Map.setxlocation(Map.getxlocation() + 1);
		You.setturnsleft(1);
	}	
}

else if (choice == "Help" || choice == "help")
{
	You.helpfunction();
}

else
{
cout << "I can't do that" << endl;
}
}

		//End main game loop

if (You.getturns() == 0)
{
cout << "Adrift in a sea of sharks, your death is certain and will be as painful as this project was to make..." << endl;
}
if (!You.getplaystate())
{
cout << "Arr, ye yellowbelly..." << endl;
}
if (You.getwinstate())
{
cout << "Congrats, you've escaped from the sinking ship" << endl;
cout << "You've scored " << You.getscore() << "/106 points " << endl;
cout << You.getname() << "'s adventure continues in 'ZOMG the pit of doom!'" << endl;
cout << " " << endl;
cout << "Thanks for playin' matey!" << endl;
}

system("pause");
return 0;

}
