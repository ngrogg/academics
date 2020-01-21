		//Libraries included
#include <iostream>
#include <cstdlib>
#include <string>

		//Files included, uncomment .cpp file for Mac/Linux
#include "circle-list.cpp"
#include "circle-list.h"

using namespace std;

int main()
{

		//number of players
int playernum;
int words;

cout << "Program 3" << endl;
cout << "Number of players: ";
cin >> playernum;

cout << "Length of phrase: ";
cin >> words;


		//verification loops
while(playernum > 10 || playernum < 2)
{
cout << "Invalid # of players" << endl;
cout << "Number of players: ";
cin >> playernum;
}

while(words > 10 || words < 1)
{
cout << "Invalid phrase length" << endl;
cout << "Length of prase: ";
cin >> words;
}

		//array to hold phrase
string phrase[words];

		//create circular linked list



		//for loop to execute program
for()
{}

system("pause");
return 0;
}
