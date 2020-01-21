#include "Card.h"
#include <string>

		// Empty default constructor
card::card()
{

}

card::card(int n, char s, std::string v)
{
number = n;
suit = s;
value = v;
}

void card::setnumber(int n)
{
	number = n;
}

void card::setsuit(char s)
{
	suit = s;
}

void card::setvalue(std::string v)
{
	value = v;
}

int card::getnumber()
{
	return number;
}

char card::getsuit()
{
	return suit;
}

std::string card::getvalue()
{
	return value;
}
