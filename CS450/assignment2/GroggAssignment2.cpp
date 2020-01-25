#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

// Virgin Windows file path
//#include "..\Project1\GroggLinkedList.cpp"

// VS

// Chad Linux file path
#include "GroggLinkedList.cpp"

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
		LinkedList<double> programListd;
		programListd.runProgram();
	}
	else if (dataType == 'i') {
		LinkedList<int> programListi;
		programListi.runProgram();
	}
	else if (dataType == 's') {
		LinkedList<string> programLists;
		programLists.runProgram();
	}
	else { //dataType == c
		LinkedList<char> programListc;
		programListc.runProgram();
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
