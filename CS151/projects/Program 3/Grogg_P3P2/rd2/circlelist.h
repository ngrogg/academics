#pragma once

#ifndef circlelist_h
#define circlelist_h

#include <string>

using namespace std;

class circlelist
{

protected:

	struct ListNode
	{
			//holds up to five words, for worst case scenario 2 players and 10 words
			//If not used, I will assign a junk value and use in a if/else to not go beyond a certain point.
		string value1; 
		string value2; 
		string value3; 
		string value4;
		string value5;

			//number for player, ex player 1 is 1
		int playervalue;
	
			//point to next value
		ListNode *next; 
	};

	ListNode *head;
 
public:	
		//default constructor, creates an empty list
	circlelist();

		//destructor
	~circlelist();

		//get function to output node's values, jvalue used to return false
	bool getvalue(const string& rvalue, const string& jvalue);

		//remove function
	void remove(const string& lastword);

		//create a node
	void createnode(int playernum, const string& jvalue);

		//
	void addarray(const string& rvalue, const string& jvalue);

		//output players not out
	void displayplayers();

		//clear all nodes to "empty value"
	void clearnodes(const string& jvalue); 
	
		//reassign array to nodes, used after initial set up
	void readdarray(int loopnum, int skipvar, const string& rvalue,const string& jvalue);

};
#endif
