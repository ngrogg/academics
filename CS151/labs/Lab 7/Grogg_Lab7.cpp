#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>

//uncomment for non-Windows OS
#include "queue.cpp"
#include "stack.cpp"

#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
	
		//Initialize stack and queue
Stack s;
Queue q;

		//Variable for while loop
char answer;	

		//variable to enter chars into stack/queue
char next;	

while (answer != 'n' && answer != 'N')
{
		//counter for phrase size
	int phraseS = 0;
	
		//Enter phrase
	cout << "Keeping spaces, special characters and capitals in mind, enter your phrase" << endl;
	cin.get(next);
	
	while (next != '\n')
	{
			//put char into stack and queue
		s.push(next); 
		q.add(next);
        cin.get(next);
			//increase counter for array size
        phraseS += 1; 
	}
	
		//Array to hold the phrase
	char sarray[phraseS + 1];
	char qarray[phraseS + 1];
	
		//counters for moving stack and queue to array for comparison
	int scount = 0;
	int qcount = 0;
	
		//Move stack into array for comparison
	while (!s.empty())
	{
		sarray[scount] = s.pop();
		scount += 1;
	}
		
		//move queue into array for comparison
	while (!q.empty())
    {
		qarray[qcount] = q.remove();
		qcount += 1;
	}
	
		//Fail variable
	bool Pal = true;
	
		//Compare arrays
	for(int count = 0; count < phraseS; count++)
	{
		if(sarray[count] == qarray[count])
		{Pal = true;}
		else
		{Pal = false;}
	}
	
		//Output if phrase is a palindrome or not
	if(!Pal)
	{cout << "phrase is not a palindrome..." << endl;}
	else
	{cout << "phrase is a palindrome!" << endl;}
	
		//Quit thing
	cout << "Keep going? n/N/y/Y ";
	cin >> answer;
		
		//Verification loop for quit
	while ((answer != 'n' && answer != 'N') && (answer != 'y' && answer != 'Y'))
	{
	cout << "Keep going? n/N/y/Y ";
	cin >> answer;		
	}
	
		//clear input buffer
	cin.ignore();
}
	
	system("pause");
	return 0;
}
