#include <cstdlib>

#include "voter.h"


		//Default Construtor, should not be used
Voter::Voter()
{
	dynamic = NULL;
	ID = 0;
}

		//Overloaded constructor
Voter::Voter(int i, int s)
{
	
	dynamic = new double[s];
	ID = i;
	
}

		//Copy Constructor
Voter::Voter(Voter& obj)
{
	dynamic = new double;
	*dynamic = *obj.dynamic;
}

		//Destructor
Voter::~Voter()
{
	delete dynamic;
}

		//Accessors
void Voter::SetSize(int s)
{
	size = s;
}
		//Mutators
int Voter::GetSize()
{
	return size;
}

int Voter::GetID()
{
	return ID;
}

//int Voter::CalcResults()


//Overloaded = operator
