#include <iostream> 

using namespace std;

// Prototypes
bool node_check (char);

int main (void) {

	char node = 'a';

	// Determine which node we are
	cout << "Are you the initiator (i) or the receiver (r)? ";

	do {
		cin >> node;
	} while (node_check (node)); 

	if (node == 'i') {
		cout << "Running as initiator\n";
	} else {
		cout << "Running as receiver\n";
	}
}

bool node_check (char node) {
	bool result = true;

	if (node == 'i' || node == 'r') {
		result = false;
	} else {
		cout << "Invalid input, try again (i - initiator, r - receiver): ";
	}

	return result;
}
