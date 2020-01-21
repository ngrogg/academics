#include <iostream>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;

int main()
{
		// Number of cases
int cases;
cout << "Number of cases: ";
cin >> cases;
while(cases > 50 || cases < 0)
{
	cout << "Number of cases: ";
	cin >> cases;
}

for (int count = 0; count < cases; count++)
{
		// Declare Set
	set<string> countries;

		// Variable for number of countries
	int countrynum;

		// Variable for country name
	string input;

		// Input number of countries for case
	cout << "Case " << count + 1 <<  ", how many countries? ";
	cin >> countrynum;
	while(countrynum > 100)
	{
		cout << "Case " << count + 1 <<  ", how many countries? ";
		cin >> countrynum;
	}

		// Input data into set
	for (int count = 0; count < countrynum; count++)
	{
		cout << "Enter country name: ";
		cin >> input;
		while(input.length() > 20)
		{
			cout << "Enter country name: ";
			cin >> input;
		}
		countries.insert(input);
	}

		// Output size of country set
	cout << countries.size() << endl;
}
	
		// uncomment  for Visual Studio
	//system("pause");
	return 0;
}
