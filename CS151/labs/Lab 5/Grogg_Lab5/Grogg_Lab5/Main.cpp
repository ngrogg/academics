#include <iostream>
#include <cstdlib>
#include "StringVar.cpp"
#include "StringVar.h"

using namespace std;


//Program to demonstrate use of the class StringVar.

void conversation(int max_name_size);
//Carries on a conversation with the user. 


int main( )
{
    using namespace std;
    conversation(30);
    cout << "End of demonstration.\n";
    return 0;
}

// This is only a demonstration function:
void conversation(int max_name_size)
{
    using namespace std;

    StringVar your_name(max_name_size), our_name("Borg");

    cout << "What is your name?\n";
    your_name.input_line(cin);
    cout << "We are " << our_name << endl;
    cout << "We will meet again " << your_name << endl;
}
