#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>

		// Uncomment for BSD/*NIX based systems
#include "Card.h"
#include "Card.cpp"

using namespace std;

int main()
{
		// Instantiate deck(s)
vector<card> deck;

		// Arrays for values
int cardnumber[]    = {1,2,3,4,5,6,7,8,9,10,11,12,13};
char cardsuit[]     = {'c','d','h','s'};
string cardvalue[]  = {"Ace" ,"2","3","4","5","6","7","8","9","10","Jack","Queen","King" };

		// For loop for suits
	for (int count1 = 0; count1 < 4; count1++)
	{
		// For loop for card
		for (int count2 = 0; count2 < 13; count2++)
		{//new
			deck.push_back(card(cardnumber[count2],cardsuit[count1],cardvalue[count2]));
		}
	}
int size = deck.size();

		// Shuffle cards
	for (int count = 0; count < size; count++)
	{
	   int r = count + rand() % (size - count);
	   swap(deck[count], deck[r]);
	}

		// Create two hands and assign 5 cards to each
list<card> P1;
list<card> P2;

		// Assign five cards to each hand
	for(int count = 0; count < 5; count++)
	{
	P1.assign (1, deck[count]);
	P2.assign (1, deck[count+5]);	
	}
		// Print out hands	
	for(list<card>::iterator it = P1.begin(); it!= P1.end(); it++)
        {
                cout << *it;
		cout << endl;
        }

	for(list<card>::iterator it = P2.begin(); it!= P2.end(); it++)
        {
                cout << *it;
		cout << endl;
        }


	system("pause");
	return 0;
}

