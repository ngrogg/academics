#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

template<typename T>
class LinkedList {
protected:
	struct ListNode {
		string name;
		T value;
		ListNode *next;
		ListNode(T newVal, string newName, ListNode *nextNode = NULL) {
			name = newName;
			value = newVal;
			next = nextNode;
		}
	};
	ListNode *head;

public:
	// Constructor
	LinkedList() {
		head = NULL;
	}
	// Destructor
	~LinkedList();
	// Run the program, my hacky way of getting around passing the template function
	void runProgram();
	// Add item to end of list (Append)
	void append(T val, string n);
	// Add record to a specific spot, adds to end if out of scope (Insert)
	void appendSpecific(T val, int target, string n);
	// Search and output index from list (Find)
	void search(int target);
	// Remove index item from list (Remove)
	void remove(int target);
	// Output list (Additional)
	void displayList() const;
	
	// Helper function, prevents redundant use of cout statements...
	void menu() {
		cout << "Enter 'a' to add a value" << endl;
		cout << "Enter 's' to add a value at a specific index" << endl;
		cout << "Enter 'd' to delete a value at a specific index" << endl;
		cout << "Enter 'f' to find a value at a specific index" << endl;
		cout << "Enter 'o' to output the linked list" << endl;
		cout << "Enter 'q' to quit" << endl;
	}
};

template<typename T>
LinkedList<T>::~LinkedList() {
	ListNode *NodePtr = head;
	while (NodePtr != NULL) {
		// Declare garbage pointer to delete
		ListNode *garbage = NodePtr;

		// Move to next node before deleting
		NodePtr = NodePtr->next;

		// Delete node
		delete garbage;
	}
}

template<typename T>
void LinkedList<T>::runProgram() {
	T listInput;
	char input;
	string name;

	menu();
	cin >> input;

	while (input != 'q') {
		if (input == 'a') {
			cout << "Name of node to create: ";
			// Cleans input buffer, otherwise getline doesn't work
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Node value to append: ";
			cin >> listInput;
			append(listInput, name);
		}
		else if (input == 's') {
			int targetIndex;
			cout << "Target index (initial index 0): ";
			cin >> targetIndex;
			cout << "Name of node to create: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Node value to append: ";
			cin >> listInput;
			appendSpecific(listInput, targetIndex, name);
		}
		else if (input == 'd') {
			int targetIndex;
			cout << "Index to remove (initial index 0): ";
			cin >> targetIndex;
			remove(targetIndex);
		}
		else if (input == 'f') {
			int targetIndex;
			cout << "Index to search (initial index 0): ";
			cin >> targetIndex;
			search(targetIndex);
		}
		else if (input == 'o') {
			cout << "Outputting List" << endl;
			displayList();
		}
		else if (input == 'q') {
			cout << "quitting" << endl;
		}
		else {
			cout << "Invalid option" << endl;
		}
		menu();
		cin >> input;
	}
}

template<typename T>
void LinkedList<T>::append(T val, string n) {
	// Add to end of list if list is empty
	if (head == NULL) {
		head = new ListNode(val, n);
	}

	// Else go to end and append
	else {
		ListNode *NodePtr = head;

		// Cycle through linked list
		while (NodePtr->next != NULL) {
			NodePtr = NodePtr->next;
		}

		// Create new node and add after it
		NodePtr->next = new ListNode(val, n);
	}
}

template<typename T>
void LinkedList<T>::appendSpecific(T val, int target, string n) {
	ListNode *NodePtr = head;
	ListNode *previousNodePtr = NodePtr;
	int index = 0;

	// If head is target value
	if (target == 0) {
		// Create new node and add to head
		ListNode* NewNode = new ListNode(val, n);
		head = NewNode;

		cout << "Inserting at head" << endl;

		// tie new node to next node
		NewNode->next = NodePtr;
	}

	// Else, loop through list
	else {
		while (NodePtr->next != NULL && index != target) {
			previousNodePtr = NodePtr;
			NodePtr = NodePtr->next;
			index += 1;
		}

		// If index is correct, append
		if (index == target) {
			// Create new node to add
			ListNode* NewNode = new ListNode(val, n);
			cout << "Inserting at index " << index << endl;

			// Tie previous node to new node
			previousNodePtr->next = NewNode;

			// Tie new node to next node
			NewNode->next = NodePtr;
		}

		// Else append to end
		else {
			cout << "Index too far, appending to end" << endl;
			NodePtr->next = new ListNode(val, n);
		}
	}

}

template<typename T>
void LinkedList<T>::search(int target) {
	ListNode *NodePtr = head;
	int index = 0;

	// If head is index, cout
	if (index == target) {
		cout << "----------------------------" << endl;
		cout << "Index: " << index << endl;
		cout << "Name: " << NodePtr->name << endl;
		cout << "Value: " << NodePtr->value << endl;
		cout << "----------------------------" << endl;
	}

	// Else go through the list looking for item
	else {
		while (NodePtr->next != NULL && index != target) {
			NodePtr = NodePtr->next;
			index += 1;
		}

		// If index == target
		if (index == target) {
			cout << "----------------------------" << endl;
			cout << "Index: " << index << endl;
			cout << "Name: " << NodePtr->name << endl;
			cout << "Value: " << NodePtr->value << endl;
			cout << "----------------------------" << endl;
		}

		// Else list is over, index doesn't exist
		else {
			cout << "Index " << target << " is out of scope" << endl;
		}
	}
}

template<typename T>
void LinkedList<T>::remove(int target) {
	ListNode *NodePtr, *previousNodePtr;
	NodePtr = head;
	previousNodePtr = head;
	int index = 0;

	// Thing Keith showed us in 151, I forget the exact function, only that it's important...
	if (!head) {
		return;
	}

	// Look for index
	while (NodePtr->next != NULL && index != target) {
		// Sequential search
		previousNodePtr = NodePtr;
		NodePtr = NodePtr->next;
		index += 1;
	}
	// Delete NodePtr if index is correct
	if (index == target) {
		// Link the previous node to the node after NodePtr
		cout << "Deleting item at index " << index << endl;
		previousNodePtr->next = NodePtr->next;
		delete NodePtr;
	}
	// Else, the list has been searched and index is out of scope
	else {
		cout << "The index " << target << " is out of scope" << endl;
	}
}

template<typename T>
void LinkedList<T>::displayList() const {
	// Start at the head of the list
	ListNode *NodePtr = head;
	int index = 0;

	// Out the linked list, node by node
	while (NodePtr) {
		// Print Current Node
		cout << "Index: " << index << endl;
		cout << "Name: " << NodePtr->name << endl;
		cout << "Value: " << NodePtr->value << endl;
		cout << "----------------------------" << endl;
		NodePtr = NodePtr->next;
		index += 1;
	}
}
#endif
