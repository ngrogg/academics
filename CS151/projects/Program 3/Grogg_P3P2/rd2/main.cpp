		//Libraries included
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>

		//Files included, comment out "circlelist.cpp" for Windows
#include "circlelist.h"
#include "circlelist.cpp"


using namespace std;

int main()
{
	
		//variables for phrase and word numbers
int playercount;
int wordcount;


		//input section
cout << "How many players (between 2 and 10) will be playing?" << endl;
cout << "Players: ";
cin >> playercount;


		//while loop verification
while (playercount < 2 || playercount > 10) 
{
	cout << "Please enter a number between 2 and 10" << endl;
	cout << "Players: ";
	cin >> playercount;
}

		//input section
cout << "How many words (between 1 and 10) are in the phrase?" << endl;
cout << "Words: ";
cin >> wordcount;


		//while loop verification
while (wordcount < 1 || wordcount > 10) 
{
	cout << "Please enter a number between 3 and 20" << endl;
	cout << "Words: ";
	cin >> wordcount;
}

		//array for phrase
string wordarray[wordcount];

cout << " " << endl;
cout << "Please enter the words of the phrase one at a time and then press enter " << endl;

		//for loop to feed words into array
for (int count = 0; count < wordcount; count++)
{
	cout << "Please enter word " << count + 1 << endl;
	cin >> wordarray[count];
}

		//for loop to output array to test
cout << "These are the words of the array " << endl;
for (int count = 0; count < wordcount; count++)
{
	cout << "Word " << count + 1 << " is " << wordarray[count] << endl;
}

		//instantiate default constructor/ Hindenberg pointer simulator
circlelist CLinkedList;

		//for loop to create linked list
for(int count = 0; count < playercount; count++)
{
		//create the nodes and assign the "Empty" value
	CLinkedList.createnode((count+1), "KUTHGYLSHVHGYGY"); 
}

		//for loop to assign array to linked list
for(int count = 0; count < wordcount; count++)
{
		// assign array to linked list
	CLinkedList.addarray(wordarray[count],"KUTHGYLSHVHGYGY");
}

		//for loop to execute game
for(int count = 0; count < (playercount - 1); count++)
{
cout << "round " << count + 1 << endl;

		//remove player with last word
cout << "removing a player" << endl;

		// look for final word and remove pointer
CLinkedList.remove(wordarray[wordcount-1]);
cout << "Player removed" << endl;
CLinkedList.displayplayers();

		//clear array, reassign all node values to "empty value"
CLinkedList.clearnodes("KUTHGYLSHVHGYGY");
cout << "Nodes reset" << endl;
for(int count = 0; count < wordcount;count++)
{
CLinkedList.readdarray((wordcount-1), count, wordarray[count],"KUTHGYLSHVHGYGY");//reassign values to nodes
}
}

		//display list type function
cout << "Only player left is ";
CLinkedList.displayplayers();
cout << " " << endl;
cout << "Therefore, Alice should be "; 
CLinkedList.displayplayers();

system("pause");
return 0;
	
}
