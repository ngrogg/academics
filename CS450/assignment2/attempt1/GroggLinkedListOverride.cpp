#include "GroggLinkedList.h"

using namespace std;

template<typename T>
class ListOverride : public LinkedList<T> {
	protected:
		struct ListNode {
		string name;
		T value;
		ListNode *next;
		ListNode(T newVal, string newName, ListNode *nextNode = NULL) {
			name = newName;
			value = newVal;
			next = nextNode;
		}
		};
		ListNode *head;

	public:
		// Run the new menu function
		void menuNew(){
			cout << "Enter 'a' to add a value" << endl;
			cout << "Enter 's' to add a value at a specific index" << endl;
			cout << "Enter 'd' to delete a value at a specific index" << endl;
			cout << "Enter 'r' to remove a node with a specific name" << endl;
			cout << "Enter 'f' to find a value at a specific index" << endl;
			cout << "Enter 'l' to look for a node with a specific name" << endl;
			cout << "Enter 'o' to output the linked list" << endl;
			cout << "Enter 'q' to quit" << endl;
		}

		// Constructor
		ListOverride(){ head = NULL;};
		// Destructor
		~ListOverride();
		// Delete function to look by name
		void removeByString(string target);

		// Find function to look by name
		void searchByString(string target);

		// New run Program with new features
		void runProgramNew();	
};

// Destructor
template<typename T>
ListOverride<T>::~ListOverride() {
	ListNode *NodePtr = head;
	while (NodePtr != NULL) {
		// Declare garbage pointer to delete
		ListNode *garbage = NodePtr;

		// Move to next node before deleting
		NodePtr = NodePtr->next;

		// Delete node
		delete garbage;
	}

}

template<typename T>
void ListOverride<T>::removeByString(string target){
ListNode *NodePtr, *previousNodePtr;
NodePtr = head;
previousNodePtr = head;

cout << "Looking for node named '" << target <<"'" << endl;

// Look for target
cout << "Starting search" << endl;
while (NodePtr->next != NULL && NodePtr->name != target) {
	// Sequential search
	previousNodePtr = NodePtr;
	NodePtr = NodePtr->next;
}
cout << "Looked through loop" << endl;
// Delete NodePtr if index is correct
if (NodePtr->name == target) {
	cout << "Deleting node with name " << target << endl;
	// Link the previous node to the node after NodePtr
	previousNodePtr->next = NodePtr->next;
	delete NodePtr;
}
// Else, the list has been searched and index is out of scope
else {
	cout << "Target " << target << " is not in list" << endl;
	}
}

template<typename T>
void ListOverride<T>::searchByString(string target){
ListNode *NodePtr = head;
int index = 0;
cout << "looking for node named " << target << endl;

cout << "Starting search" << endl;
while (NodePtr->next != NULL && NodePtr->name != target) {
	cout << "Searching" << endl;
	//cout << "Current node named " << NodePtr->name << ", continuing search" << endl;
	NodePtr = NodePtr->next;
	index += 1;
}
cout << "Finished search" << endl;

// If index == target
if (NodePtr) {
	cout << "----------------------------" << endl;
	cout << "Index: " << index << endl;
	cout << "Name: " << NodePtr->name << endl;
	cout << "Value: " << NodePtr->value << endl;
	cout << "----------------------------" << endl;
}

// Else list is over, node doesn't exist
else {
	cout << "Node " << target << " is not in list" << endl;
}
}

template<typename T>
void ListOverride<T>::runProgramNew(){
T listInput;
char input;
string name;

menuNew();
cin >> input;

while (input != 'q') {
	if (input == 'a') {
		cout << "Name of node to create: ";
		// Cleans input buffer, otherwise getline doesn't work
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, name);
		cout << "Node value to append: ";
		cin >> listInput;
		ListOverride::append(listInput, name);
	}
	else if (input == 's') {
		int targetIndex;
		cout << "Target index (initial index 0): ";
		cin >> targetIndex;
		cout << "Name of node to create: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, name);
		cout << "Node value to append: ";
		cin >> listInput;
		ListOverride::appendSpecific(listInput, targetIndex, name);
	}
	else if (input == 'd') {
		int targetIndex;
		cout << "Index to remove (initial index 0): ";
		cin >> targetIndex;
		ListOverride::remove(targetIndex);
	}
	else if (input == 'r'){
		string nodeName;
		cout << "Function will remove first instance of matching node name" << endl;
		cout << "Function IS case and space sensitive" << endl;
		cout << "Enter name of node to remove: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, nodeName);
		ListOverride::removeByString(nodeName);
	}
	else if (input == 'f') {
		int targetIndex;
		cout << "Index to search (initial index 0): ";
		cin >> targetIndex;
		ListOverride::search(targetIndex);
	}
	else if (input == 'l'){
		string nodeName;
		cout << "Function will print the first instance of matching node name" << endl;
		cout << "Function IS case and space sensitive" << endl;
		cout << "Enter name of node to look for: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, nodeName);
		ListOverride::searchByString(nodeName);
		
	}
	else if (input == 'o') {
		cout << "Outputting List" << endl;
		ListOverride::displayList();
	}
	else if (input == 'q') {
		cout << "quitting" << endl;
	}
	else {
		cout << "Invalid option" << endl;
	}
	menuNew();
	cin >> input;
	}
}
