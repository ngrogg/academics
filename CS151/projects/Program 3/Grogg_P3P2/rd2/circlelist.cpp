#include "circlelist.h"
#include <iostream>
#include <string>

circlelist::circlelist()
{
	head = NULL; 
}

circlelist::~circlelist()
{
	ListNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		ListNode *deleteme = nodePtr; //node to be deleted
		nodePtr = nodePtr -> next; //move to a node
		delete deleteme; //delete previous node
	}
	delete nodePtr; //at end
}


void circlelist::createnode(int playernum, const string& jvalue)
{
	ListNode *nodePtr = new ListNode; //create a new node
	if (nodePtr->next == NULL)
	{
		nodePtr->value1 = jvalue;
		nodePtr->value2 = jvalue;
		nodePtr->value3 = jvalue;
		nodePtr->value4 = jvalue;
		nodePtr->value5 = jvalue;
		nodePtr->playervalue = playernum;
		nodePtr->next = head;  //modified head insert function from previous lab
		head = nodePtr; //I'd like to keep head as NULL and that's it
	}
	else
	{
		ListNode *temphead =  head; //hold head 
		while (temphead->next != NULL)
		{
			temphead = temphead->next; //go through list to find end
		}
		temphead->value1 = jvalue;
		temphead->value2 = jvalue;
		temphead->value3 = jvalue;
		temphead->value4 = jvalue;
		temphead->value5 = jvalue;

		temphead->value5 = playernum;
		head = temphead; // put new values at end
	}
}

void circlelist::addarray(const string& rvalue, const string& jvalue)
{
	ListNode *nodePtr = head;
	while (nodePtr-> value1 == jvalue && nodePtr-> next != NULL)
	{nodePtr-> value1 = rvalue;}
	while (nodePtr->value2 == jvalue && nodePtr->next != NULL)
	{nodePtr->value2 = rvalue;}
	while (nodePtr->value3 == jvalue && nodePtr->next != NULL)
	{nodePtr->value3 = rvalue;}
	while (nodePtr->value4 == jvalue && nodePtr->next != NULL)
	{nodePtr->value4 = rvalue;}
	while (nodePtr->value5 == jvalue && nodePtr->next != NULL)
	{nodePtr->value5 = rvalue;}	

}

bool circlelist::getvalue(const string& rvalue, const string& jvalue)
{
	ListNode *nodePtr = head; //start list at head
	
	//not all of these will be used in every runthrough
	
	//go through rows, value by value
	while(nodePtr->value1 != rvalue && nodePtr-> next!= NULL)
	{nodePtr= nodePtr->next;}//cycle values
	if(nodePtr->value1 == rvalue)
	{return true;}
	else
	{return false;}
	while(nodePtr->value2 != rvalue && nodePtr-> next!= NULL)
	{nodePtr= nodePtr->next;}//cycle values
	if(nodePtr->value2 == rvalue)
	{return true;}
	else
	{return false;}
	while(nodePtr->value3 != rvalue && nodePtr-> next!= NULL)
	{nodePtr= nodePtr->next;}//cycle values
	if(nodePtr->value3 == rvalue)
	{return true;}
	else
	{return false;}
	while(nodePtr->value4 != rvalue && nodePtr-> next!= NULL)
	{nodePtr= nodePtr->next;}//cycle values
	if(nodePtr->value4 == rvalue)
	{return true;}
	else
	{return false;}
	while(nodePtr->value5 != rvalue && nodePtr-> next!= NULL)
	{nodePtr= nodePtr->next;}//cycle values
	if(nodePtr->value5 == rvalue)
	{return true;}
	else
	{return false;}
	

}


void circlelist::remove(const string& lastword)
{
	//head removal
	ListNode *nodePtr, *previousnodePtr; //previous used to link nodes, avoid danglingpointers/memory leak
	nodePtr = head;
	previousnodePtr = nodePtr;
	//first see if head has the value (it shouldn't but I'm coding at 1 am so you never know)
	if (head->value1 == lastword)
	{nodePtr = head;
		head = head->next;
		delete nodePtr;}
	else if (head ->value2 == lastword)
	{nodePtr = head;
		head = head->next;
		delete nodePtr;}
	else if (head ->value3 == lastword)
	{nodePtr = head;
		head = head->next;
		delete nodePtr;}
	else if (head ->value4 == lastword)
	{nodePtr = head;
		head = head->next;
		delete nodePtr;}
	else if (head ->value5 == lastword)
	{nodePtr = head;
		head = head->next;
		delete nodePtr;}
	
	else //if value not in head, move one
	{
		while (nodePtr->value1 != lastword && nodePtr->next != NULL) //cycle through list
	{
		previousnodePtr = nodePtr;
		nodePtr= nodePtr->next;
	}
	if (nodePtr->value1 == lastword) //once value found, delete
	{
		ListNode *deleteme = nodePtr; //point to node to be deleted
		previousnodePtr->next = nodePtr->next; //link previous with next to avoid pointer issues
		delete deleteme; //bye bye value
	}
	
	while (nodePtr->value2 != lastword && nodePtr->next != NULL) //cycle through list
	{
		previousnodePtr = nodePtr;
		nodePtr= nodePtr->next;
	}
	if (nodePtr->value2 == lastword) //once value found, delete
	{
		ListNode *deleteme = nodePtr; //point to node to be deleted
		previousnodePtr->next = nodePtr->next; //link previous with next to avoid pointer issues
		delete deleteme; //bye bye value
	}
	
	while (nodePtr->value3 != lastword && nodePtr->next != NULL) //cycle through list
	{
		previousnodePtr = nodePtr;
		nodePtr= nodePtr->next;
	}
	if (nodePtr->value3 == lastword) //once value found, delete
	{
		ListNode *deleteme = nodePtr; //point to node to be deleted
		previousnodePtr->next = nodePtr->next; //link previous with next to avoid pointer issues
		delete deleteme; //bye bye value
	}
	
	while (nodePtr->value4 != lastword && nodePtr->next != NULL) //cycle through list
	{
		previousnodePtr = nodePtr;
		nodePtr= nodePtr->next;
	}
	if (nodePtr->value4 == lastword) //once value found, delete
	{
		ListNode *deleteme = nodePtr; //point to node to be deleted
		previousnodePtr->next = nodePtr->next; //link previous with next to avoid pointer issues
		delete deleteme; //bye bye value
	}
	
	while (nodePtr->value5 != lastword && nodePtr->next != NULL) //cycle through list
	{
		previousnodePtr = nodePtr;
		nodePtr= nodePtr->next;
	}
	if (nodePtr->value5 == lastword) //once value found, delete
	{
		ListNode *deleteme = nodePtr; //point to node to be deleted
		previousnodePtr->next = nodePtr->next; //link previous with next to avoid pointer issues
		delete deleteme; //bye bye value
	}
	
	}
}


void circlelist::displayplayers()
{
	ListNode *nodePtr = head;
	while(nodePtr-> next != NULL)
	{
		cout << "Player " << nodePtr -> playervalue << endl;
		nodePtr = nodePtr -> next;
	}
}

void circlelist::clearnodes(const string& jvalue)
{
	ListNode *nodePtr = head;
	while (nodePtr->next != NULL) //cycle through linked list and set all nodes to "Empty value" 
	{
		nodePtr->value1 = jvalue;
		nodePtr->value2 = jvalue;
		nodePtr->value3 = jvalue;
		nodePtr->value4 = jvalue;
		nodePtr->value5 = jvalue;

		nodePtr = nodePtr-> next;
	}
	}
void circlelist::readdarray(int loopnum, int skipvar, const string& rvalue,const string& jvalue)
{
	ListNode *nodePtr = head;
	
	for(int count = 0;count < (loopnum + skipvar); count++) //go back through function to find where program left off
	{
		if(nodePtr->next != NULL)
		{nodePtr= nodePtr->next;} //go through function
		else
		{nodePtr = head;} //set loop back to top and cycle through again. 
	}
	if (nodePtr->value1 == jvalue) //assign rvalue to node only if "empty"
	{nodePtr->value1 = rvalue;}
	else if (nodePtr->value2 == jvalue)
	{nodePtr->value2 = rvalue;}
	else if (nodePtr->value3 == jvalue)
	{nodePtr->value3 = rvalue;}
	else if (nodePtr->value4 == jvalue)
	{nodePtr->value4 = rvalue;}

	else
	nodePtr->value5 = rvalue;
}

