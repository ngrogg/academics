#include <iostream>
#include <cstdlib>
#include <string>
#include <cstddef>

#include "linkedlist.cpp"

using namespace std;

int main()
{

//create linked list
LinkedList LinkedL;

//Add item to linked list
LinkedL.add(42);
LinkedL.add(21);
LinkedL.add(9001);
LinkedL.add(1701);
LinkedL.add(302);

//Add number a to linked list before position b.
LinkedL.insert_middle(4500, 9001);
LinkedL.insert_middle(351, 302);
LinkedL.insert_middle(1,22);

//find number (if possible) in linked list
LinkedL.searchS(9001);
LinkedL.searchS(1);

//remove number from linked list
LinkedL.remove(21);

//output linked list
LinkedL.displayList();

system("pause");
return 0;
}
