#include "llist.h"

using namespace std;

int main (void) {

	LList * list = new LList ();

	/* Test the add method */
	list -> add (6);
	list -> add (4);
	list -> add (2);
	list -> add (5);
	list -> add (3);
	list -> add (1);

	list -> print_list ();

	/* Test get_node () */
	cout << endl;

	for (int i = 0; i < list -> get_size (); i++) {
		cout << "value of node at " << i << ": " << list -> get_node (i) << endl;
	}

	cout << endl;

	/* Test the sorting */
	list -> sort_list ();
	list -> print_list ();

	return 0;
}
