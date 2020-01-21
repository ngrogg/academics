#pragma once

#ifndef Voter_h
#define Voter_h

class Voter
{
private:

		//Dynamic array size variable
	int size;	
	
		//Dynamic array
	double* dynamic;
	
	
		//Voter ID
	int ID;


public:
		//Default Constructor
	Voter();
		
		//Overloaded Constructor
	Voter(int i, int s);
	
		//Copy Constructor, const wouldn't cooperate...
	Voter(Voter& obj);
	
		//Destructor
	~Voter();
	
		//Mutators
	void SetSize(int);
		
		//Accessors
	int GetSize();
	int GetID();
	
		//Calculation functions
	//int CalcResults();
	
};

#endif
