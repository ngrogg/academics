#pragma once

#ifndef circlelist_h
#define circlelist_h

#include <string>

class circle-list
{
protected:
	struct ListNode
	{
			//Holds up to five words, for minimum 2 players and maximum 10 words
			//Unused nodes will be assigned NULL value
		string value1;
		string value2;
		string value3;
		string value4;
		string value5;

			//value for player number, ie player 2 is 2 etc...
		int playernum;
		
			//Pointer to next node, last node will point to head
		ListNode *next;
	
	};
	
	ListNode *head;

public:

		//create empty list
	circle-list();
	
		//destructor
	~circle-list();
	
		//add node
	void create_node();
	
		//delete node
	void delete_node();	
		
		//add data to node
	void add_data();

};

#endif
