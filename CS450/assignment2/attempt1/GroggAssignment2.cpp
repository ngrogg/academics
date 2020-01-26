#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

// Windows file path
//#include "..\Project1\GroggLinkedList.cpp"

// Linux file path
#include "GroggLinkedListOverride.cpp"

using namespace std;

// I used chars because the letters are more descriptive than numbers
char chooseType() {
	char dataType;

	// Simple to validate, yet more helpful for the user than ints
	cout << "Enter 'd' to create a list of data type double" << endl;
	cout << "Enter 'i' to create a list of data type int" << endl;
	cout << "Enter 's' to create a list of data type string" << endl;
	cout << "Enter 'c' to create a list of data type char" << endl;
	cin >> dataType;

	while ((dataType != 'd' && dataType != 'i') && (dataType != 's' && dataType != 'c')) {
		cout << "d double, i int, s string, or c char: ";
		cin >> dataType;
	}

	return dataType;
}

// Function to take input and call program
void generateList(char dataType) {
	// Create Linked List and list input variable based on input
	if (dataType == 'd') {
		//LinkedList<double> programListd;
		//programListd.runProgram();
		ListOverride<double> programListd;
		programListd.runProgramNew();
	}
	else if (dataType == 'i') {
		//LinkedList<int> programListi;
		//programListi.runProgram();
		ListOverride<int> programListi;
		programListi.runProgramNew();
	}
	else if (dataType == 's') {
		//LinkedList<string> programLists;
		//programLists.runProgram();
		ListOverride<string> programLists;
		programLists.runProgramNew();
	}
	else { //dataType == c
		//LinkedList<char> programListc;
		//programListc.runProgram();
		ListOverride<char> programListc;
		programListc.runProgramNew();
	}
}


int main() {
	// User chooses data type
	char type = chooseType();

	// Generate listbased on input type
	generateList(type);

	//system("pause");
	return 0;
}
