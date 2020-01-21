//This is the file: hourlyemployee.cpp 
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in 
//the header file hourlyemployee.h.
#include <string>
#include <iostream>
#include "hourlyemployee.h"
using namespace std;

		// Destructor
HourlyEmployee::~HourlyEmployee()
{ 
HourlyListNode *NodePtr = head; 
        while (NodePtr != NULL)
        {
                //Declare a new node pointer called garbage
                HourlyListNode *windows10 = NodePtr;
                //Carefully move to the next node before deleting garbage
                NodePtr = NodePtr->next;
                //delete the garbage
                delete windows10;
        }

}

		// Add item to node
void HourlyEmployee::addHE(int ei, double wr, double h, string n, string ssnllhe)
{
	//Adds to END of list
	if (head == NULL)
	{
		head = new HourlyListNode(ei, wr, h, n, ssnllhe);
	}
	else
	{
		HourlyListNode *NodePtr = head;
		while (NodePtr->next != NULL)
		{
			NodePtr = NodePtr->next;

		}
		//Create new node and add after last node
		NodePtr->next = new HourlyListNode(ei, wr, h, n, ssnllhe);
	}
}



		// Edit item in list
void HourlyEmployee::editHE(int tei, string tn, int ei, double wr, double h, string n, string ssnllhe)

{
HourlyListNode *NodePtr = head;

		//list is empty
if(head == NULL)
{cout << "List is empty" << endl;}

		//item not in list
else if(NodePtr->next == NULL)
{cout << "Item does not exist" << endl;}
		//item is found
else
{
NodePtr->eid = ei;
NodePtr->wage_rate = wr;
NodePtr->hours = h;
NodePtr->name = n;
NodePtr->ssn = ssnllhe;
NodePtr->net_pay = wr * h;
}
}

		// Output list
void HourlyEmployee::displaylistHE()
{
	//start at the head of the list
	HourlyListNode *NodePtr = head;
	while (NodePtr)
	{
		//Print Current Node
		cout << endl;
		cout << NodePtr->eid << endl;
		cout << NodePtr->wage_rate << endl;
		cout << NodePtr->hours << endl;
		cout << NodePtr->name << endl;
		cout << NodePtr->ssn << endl;
		cout << NodePtr->net_pay << endl;
		NodePtr = NodePtr->next;
	}
}	

void HourlyEmployee::displayemployeeHE(int tei, string tn)
{
	HourlyListNode *NodePtr = head;

		//If list is empty
	if(head == NULL)
	{cout << "List is empty" << endl;}

		//Go through list to find stuff
	while ((NodePtr->next != NULL && NodePtr->eid != tei) && (NodePtr->next != NULL && NodePtr->name !=tn ))
		{
			NodePtr = NodePtr->next;
		}

		//item not in list
	if(NodePtr->next == NULL)
	{cout << "Item does not exist" << endl;}
	
		//Item is found
	if(NodePtr->eid == tei && NodePtr->name == tn)
	{
		cout << NodePtr->eid << endl;
		cout << NodePtr->wage_rate << endl;
		cout << NodePtr->hours << endl;
		cout << NodePtr->name << endl;
		cout << NodePtr->ssn << endl;
		cout << NodePtr->net_pay << endl;
	}
}


