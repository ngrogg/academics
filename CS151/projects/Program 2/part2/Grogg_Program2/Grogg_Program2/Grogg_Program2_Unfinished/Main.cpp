#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <string>

#include "voter.cpp"
#include "voter.h"

using namespace std;

int main()
{
		//User ID is preset to prevent issues with result file	
	int UserID = 1701;
	int size;
	
			//Read ballot.txt file in
	ifstream ballot;
	ballot.open("ballot.txt");
	
	string filetext;
	
	ballot >> size;
	
	while(filetext != "0")
	{
		ballot >> filetext;
		cout << filetext << endl;
	}
	
	ballot.close();
	
		//Size is preset to avoid issues with ballot file
		
		//Create Constructor
	Voter Me(UserID, size);
	Me.SetSize(size);
	
	cout << "I am voter #" << Me.GetID() << " and my ballot has " << Me.GetSize() << " polls." << endl;
	
		//Read results.txt file in
	ifstream resultsi;
	resultsi.open("results.txt");
	if(resultsi.fail())
	{cout << "File not found" << endl; exit(1);}
	
		//count for dynamic result array
	int resultsi_count = 0;
	string junk;
	while(!resultsi.eof())
	{
		getline(resultsi, junk);
		resultsi_count += 1;
	}
	
	int* dynamic_voter = new int[resultsi_count];
	string* dynamic_votes = new string[resultsi_count];
	resultsi.close();
	
	resultsi.open("results.txt");
	
		//two arrays, voter int array, voting string array	
	for(int count = 0; count < resultsi_count; count++)
	{
		resultsi >> dynamic_voter[count];
		resultsi >> dynamic_votes[count];
	}
	
	resultsi.close();
	
		//Calculate results of election
	
	
		//Output results_final.txt
	//ofstream resultso;
	
	system("pause");
	return 0;
}
