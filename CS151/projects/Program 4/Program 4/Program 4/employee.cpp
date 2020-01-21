//This is the file: employee.cpp. 
//This is the implementation for the class Employee.
//The interface for the class Employee is in the header file employee.h.
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using namespace std;

		// Destructor
Employee::~Employee()
{
	ListNode *NodePtr = head;
	while (NodePtr != NULL)
	{
		//Declare a new node pointer called garbage
		ListNode *windows10 = NodePtr;
		//Carefully move to the next node before deleting garbage
		NodePtr = NodePtr->next;
		//delete the garbage
		delete windows10;
	}
}


		// Remove Node
void Employee::remove(int e, string n)
{
	ListNode *NodePtr, *previousNodePtr;
	NodePtr = head;
	previousNodePtr = head;
	if (!head)
	{
		//Another slick trick
	
		return;
	}

	while ((NodePtr->next != NULL && NodePtr->eid != e) && (NodePtr->next != NULL && NodePtr->name != n))
	{
		//Sequential Search
		previousNodePtr = NodePtr;
		NodePtr = NodePtr->next;

	}


	//delete NodePtr
	if (NodePtr)
	{

		//Link the previous node to the node after NodePtr
		previousNodePtr->next = NodePtr->next;
		delete NodePtr;
	}

}

