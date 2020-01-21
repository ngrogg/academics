#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>

using namespace std;

class LinkedList
{
protected:
	struct ListNode
	{
		double value;
		ListNode *next;
		ListNode(double value1, ListNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	ListNode *head;

public:
		//Constructor
	LinkedList() {head = NULL;}
		//Destructor
	~LinkedList();
		//Add number to list
	void add(double number);
		//Remove number from list
	void remove(double number);
		//Output list
	void displayList() const;
		//Sequential search
	void searchS(double number);
		//number to insert, value to insert after
	void insert_middle(double number, double before);
};


void LinkedList::add(double number)
{
	//Adds to END of list
	if (head == NULL)
	{
		head = new ListNode(number);
	}
	else
	{
		ListNode *NodePtr = head;
		while (NodePtr->next != NULL)
		{
			NodePtr = NodePtr->next;

		}
		//Create new node and add after last node
		NodePtr->next = new ListNode(number);
	}
}

void LinkedList::displayList() const
{
	//start at the head of the list
	ListNode *NodePtr = head;
	while (NodePtr)
	{
		//Print Current Node
		cout << NodePtr->value << " ---> ";
		NodePtr = NodePtr->next;
	}
}

LinkedList::~LinkedList()
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


void LinkedList::remove(double number)
{
	ListNode *NodePtr, *previousNodePtr;
	NodePtr = head;
	previousNodePtr = head;
	if (!head)
	{
		//Another slick trick
	
		return;
	}
	while (NodePtr->next != NULL && NodePtr->value != number)
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


void LinkedList::searchS(double number)
{
ListNode *NodePtr = head;	
	
//search
while (NodePtr->value != number && NodePtr->next != NULL)
{NodePtr = NodePtr->next;}

//if target variable found
if (NodePtr->value == number)
{cout << "Value " << number << " is in the list!" << endl;}
//else target varable not found
else
{cout << "Value " << number << " is not in the list..." << endl;}
}

void LinkedList::insert_middle(double number, double before)
{
		//Create iterators
	ListNode *NodePtr = head;
	ListNode *previousNodePtr = NodePtr;
	
	while (NodePtr->next != NULL && NodePtr->value != before)
	{
		//Sequential Search
		previousNodePtr = NodePtr;
		NodePtr = NodePtr->next;

	}


	//insert number before target
	if (NodePtr ->value == before)
	{
		 ListNode* NewNode = new ListNode(number);
		cout << "Inserting value " << number << " before number " << before << endl;
		//Tie previous node to new node
		previousNodePtr->next = NewNode;
		//tie new node to next node
		NewNode->next = NodePtr;
	}
	
	//else variable to insert after not in list, insert variable at end
	else
	{
		cout << "Variable not in list, adding value " << number << " to tail." << endl;
		previousNodePtr = NodePtr;
		NodePtr->next = new ListNode(number);
	}
}

