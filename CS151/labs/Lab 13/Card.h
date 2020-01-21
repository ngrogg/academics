#pragma once

#include <string>

#ifndef CARD_H

class card
{	
public:
		
		// Constructor

	card();
	card(int number, char suit, std::string value);
	
		// Mutators

	void setnumber(int n);
	void setsuit(char s);
	void setvalue(std::string v);

		// Accessors

	int getnumber();
	char getsuit();
	std::string getvalue();

	friend std::ostream& operator<< (std::ostream& os, card c)
	{
	      os << c.getnumber() << " " << c.getsuit() << " " << c.getvalue(); 
      return os;	      
	}

protected:

		// Numeric value of card, ace is low
	int number;

		// Suit of card (C, D, H, S)
	char suit;

		// Value of card (2, jack, ace, etc)
	std::string value;



};
#endif
