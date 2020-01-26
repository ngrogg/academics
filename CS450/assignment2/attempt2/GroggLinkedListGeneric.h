#ifndef GROGGLINKEDLIST_H
#define GROGGLINKEDLIST_H

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

template<typename T>
class LinkedList {
protected:
	// Class variables, this time NOT in struct form
	LinkedList<T> * next;
	string name;
	T value;

public:
	LinkedList(){};
	LinkedList(T item, string alias, LinkedList<T>* nextPtr = NULL);
	// Used to get next node in list
	LinkedList<T>* nextNode;
	// Delete
	// LinkedList<T>* deleteNode;
	// Print
	LinkedList<T>* printNode;
	// Append
	void append(T item, string alias);
	// AppendSpecific
	void appendSpecific(int target, T item, string alias);
	// Find by index
	// Delete by index
	// Output list

	// Constructor
	
};

#endif
