#pragma once

#ifndef StringVar_h
#define StringVar_h

#include <iostream>
using namespace std;

    class StringVar
    {
    public:
        StringVar(int size);
        //Initializes the object so it can accept string values up to size
        //in length. Sets the value of the object equal to the empty string.

        StringVar( );
        //Initializes the object so it can accept string values of length 100
        //or less. Sets the value of the object equal to the empty string.

        StringVar(const char a[]);
        //Precondition: The array a contains characters terminated with '\0'.
        //Initializes the object so its value is the string stored in a and
        //so that it can later be set to string values up to strlen(a) in length

        StringVar(const StringVar& string_object);
        //Copy constructor.

        ~StringVar( );
        //Returns all the dynamic memory used by the object to the freestore.

        int length( ) const;
        //Returns the length of the current string value.

         void input_line(istream& ins);
        //Precondition: If ins is a file input stream, then ins has been
        //connected to a file.
        //Action: The next text in the input stream ins, up to '\n', is copied
        //to the calling object. If there is not sufficient room, then 
        //only as much as will fit is copied.
        friend ostream& operator <<(ostream& outs, const StringVar& the_string);
		 
		//Overloads the << operator so it can be used to output values
		//of type StringVar
		//Precondition: If outs is a file output stream, then outs
		//has already been connected to a file.

 		private:
 			char *value; //pointer to dynamic array that holds the string value.
 			int max_length; //declared max length of any string value.
 		};

#endif