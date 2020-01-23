#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// This program is a revised edition based on class feedback

// Function to calculate approximate value of Pi
double piApprox(int n) {
	// (-1^0)/(2*0+1)
	double value = 1;

	for (int it = 1; it <= n; it++) {
		value += (pow(-1.0, it)) / (2.0*it + 1.0);
	}

	return 4 * value;
}

int main() {
	// Instantiate variables
	char input = 'y';
	double pi;
	int n;
	cout << "Enter an integer value for n: ";
	cin >> n;

	while (input != 'n' && input != 'N') {
		// Call function to approximate pi
		pi = piApprox(n);
		cout << "Pi approx. " << pi << endl;
		cout << "Again? (y/n): ";
		cin >> input;

		if (input == 'y' || input == 'Y') {
			cout << "Enter a new integer value for n: ";
			cin >> n;
		}
	}

	// I don't know if you want or need this
	//system("pause");
	return 0;
}
