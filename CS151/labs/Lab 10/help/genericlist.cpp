/*
File: genericlist.cpp
Michael R. Peterson
10/19/2011
For CS 151
From Savitch, Problem Solving with C++, 8th ed. Display 17.6
This is the implementation of the class template named GenericList.
The interface is in the header file genericlist.h
*/

// we need these because we will include this file along with the .h
// file in the program file
#ifndef GENERICLIST_CPP
#define GENERICLIST_CPP

#include <iostream>
#include <cstdlib>
#include "genericList.h"

using namespace std;

// place the implementation functions in the same namespace defined in the .h file
namespace CS151GenericList
{
	template<class ItemType>
	GenericList<ItemType>::GenericList(int max)
	{
		max_length = max;
		current_length = 0;
		item = new ItemType[max];
	}

	template<class ItemType>
	GenericList<ItemType>::~GenericList()
	{
		delete [] item;
	}

	template<class ItemType>
	int GenericList<ItemType>::length()
	{
		return current_length;
	}

	template<class ItemType>
	void GenericList<ItemType>::add(ItemType new_item)
	{
		if(full())
		{
			cout << "Error: adding to a full list." << endl;
			exit(1);
		}
		// if we get here, the list is not full
		item[current_length] = new_item;
		current_length += 1;
	}

	template<class ItemType>
	bool GenericList<ItemType>::full()
	{
		return (current_length == max_length);
	}

	template<class ItemType>
	void GenericList<ItemType>::erase()
	{
		current_length = 0;
	}

	template<class ItemType>
	ostream& operator <<(ostream& outs, const GenericList<ItemType>& the_list)
	{
		for(int i = 0; i < the_list.current_length; i++)
		{
			outs << the_list.item[i] << endl;
		}
		return outs;
	}

}// end of namespace

#endif //GENERICLIST_CPP