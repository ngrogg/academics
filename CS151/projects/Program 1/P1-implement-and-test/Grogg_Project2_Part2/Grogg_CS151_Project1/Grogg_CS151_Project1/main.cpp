/*

Nicholas Grogg
CS151
Project 1
Sinking Feeling

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
		//create constructor
Character.You(); 

		//enter character name
string name;
cout << "Who are you?" << endl;
cin.getline(100, name);
Character.setname(name);

		//choose difficulty
int difficulty;

cout << "How tough are ye?" << endl
cout << "1. Can I play Daddy?" << endl;
cout << "2. Krillin" << endl;
cout << "3. Frustrate me long time" << endl;
cout << "4. l33t don't make mistakes" << endl;
cout << "Please enter 1-4 to choose your difficulty: "
cin >> difficulty;

while (difficulty >= 5 || difficulty <= 0)
{
cout << "The answer is not 42, it's between 1 and 4" << endl;
cout << "1-4" << endl;
cin >> difficulty;
}

system("pause");
return 0;

}
