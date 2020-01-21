//Program to demonstrate use of the class template List.
// This code was modified from Savitch. Here, you need to define the code for the 
// << operator inside the class declaration so that the operator knows about the
// template type. It's not elegant, but it does work. Savitch's version does not. 
#include <iostream>
#include <cstdlib>
using namespace std;

template<class ItemType>

 class List
    {
    public:
        List(int max);
        //Initializes the object to an empty list that can hold up to
        //max items of type ItemType.

        ~List( );
        //Returns all the dynamic memory used by the object to the free store.

        int length( ) const;
        //Returns the number of items on the list.

        void add(ItemType new_item);
        //Precondition: The list is not full.
        //Postcondition: The new_item has been added to the list.

        bool full( ) const;
        //Returns true if the list is full.

        void erase( );
        //Removes all items from the list so that the list is empty.

        friend ostream& operator <<(ostream& outs, const List<ItemType>& the_list)
		{
			for (int i = 0; i < the_list.current_length; i++)
			{
				outs << the_list.item[i] << endl;
			}
			return outs;
		} 
        //Overloads the << operator so it can be used to output the
        //contents of the list. The items are output one per line.
        //Precondition: If outs is a file output stream, then outs has 
        //already been connected to a file.
    private:
        ItemType *item; //pointer to the dynamic array that holds the list.
        int max_length; //max number of items allowed on the list.
        int current_length; //number of items currently on the list.
    };


int main( )
{
    List<int> first_list(2);
    first_list.add(1);
    first_list.add(2);
	cout << "first_list = \n" ;
		cout << first_list;  
	

	List<char> second_list(10);
    second_list.add('A');
    second_list.add('B');
    second_list.add('C');
 cout << "second_list = \n"
         << second_list;   

    return 0;
}


    //Uses cstdlib:
    template<class ItemType>
    List<ItemType>::List(int max) : max_length(max), current_length(0)

    {
          item = new ItemType[max];
    }

    template<class ItemType>
    List<ItemType>::~List( )
    {
        delete [] item;
    }

    template<class ItemType>
    int List<ItemType>::length( ) const
    {
        return (current_length);
    }

    //Uses iostream and cstdlib:
    template<class ItemType>
    void List<ItemType>::add(ItemType new_item)
    {
        if ( full( ) )
        {
            cout << "Error: adding to a full list.\n";
            exit(1);
        }
        else
        {
            item[current_length] = new_item;
            current_length = current_length + 1;
        }
    }

    template<class ItemType>
    bool List<ItemType>::full( ) const
    {
        return (current_length == max_length);
    }

    template<class ItemType>
    void List<ItemType>::erase( )
    {
        current_length = 0;
    }

    
	
	//This was Savitch's original code for <<. It does not work, so I removed it. 
	//Please count it as dead code.
 /*   template<class ItemType>
    ostream& operator <<(ostream& outs, const List<ItemType>& the_list)
    {
        for (int i = 0; i < the_list.current_length; i++)
		{
            outs << the_list.item[i] << endl;
		}
        return outs;
    }  */ 