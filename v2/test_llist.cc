#include "llist.h"

using namespace std;

int main (void) {

	LList * list = new LList ();

	/* Test the add method */
	list -> add (5);
	list -> add (7);
	list -> add (9);
	list -> add (11);

	list -> print_list ();

	/* Test the sorting */
	list -> add (6);
	list -> add (8);
	list -> add (7);

	list -> print_list ();
	list -> sort_list ();

	return 0;
}
