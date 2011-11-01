#include <iostream>
#include <string>
#include "node.h"

// Prototype
char ask_user_role ();

using namespace std;

int main(void) {
	system ("clear");

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "------ Starting E_Sieve ------" << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	/* Ask if we're the Initiator or Receiver */
	char role = ask_user_role ();

	/* Create the node that will do the work of the E_Sieve */
	Node * node = new Node ();
	node -> run (role);

	delete (node);

	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << "------ E_Sieve has run to completion! ------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;

	return 0;
}

char ask_user_role () {
	string result;

	cout << "Which node am I? (Initiatior - i, Receiver - r): ";
	cin >> result;
	cout << endl;

	while (! (result == "i" || result == "r")) {
		cout << "Incorrect input, please enter node type (Initiatior - i, Receiver - r): ";
		cin >> result;
		cout << endl;
	}

	return result[0];
}

