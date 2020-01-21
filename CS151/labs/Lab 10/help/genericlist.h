/*
File: genericlist.h
Michael R. Peterson
10/19/2011
For CS 151
From Savitch, Problem Solving with C++, 8th ed. Display 17.4
This is the interface for the class GenericList.  Objects of type
GenericList can be a list of items of any type for which the operators
<< and = are defined.  All of the items in any one list must be of
the same type.  A list that can hold up to max items all of type Type_Name
is declared as follows:
GenericList<Type_Name>the_object(max);
*/
#ifndef GENERICLIST_H
#define GENERICLIST_H

#include <iostream>
using namespace std;

namespace CS151GenericList
{
	template<class ItemType>
	class GenericList
	{
	public:
		/*
		Initializes the object to an empty list that can hold up to max items of type ItemType
		*/
		GenericList(int max);

		/*
		Returns all the dynamic memory used by the object to the heap
		*/
		~GenericList();

		// Returns the number of items on the list
		int length();

		/*
		Precondition: the list is not full.
		Postcondition: The new_item has been added to the list.
		*/
		void add(ItemType new_item);

		// returns true if the list is full
		bool full();

		// removes all items from the list so the list is empty
		void erase();

		/*
		Overloads the << operator so it can be used to output the contents of the list.
		The items are output one per line.
		Precondition: If outs is a file output stream, then outs has already been
		connected to a file.
		*/
		friend ostream& operator<< <ItemType>(ostream& outs, const GenericList<ItemType>& the_list);

	private:
		ItemType *item; // pointer to the dynamic array that holds the list.
		int max_length; // maximum number of items allowed on the list
		int current_length; // number of items currently in the list

	}; // end of class definition

}// end of namespace definition


#endif // GENERICLIST_H