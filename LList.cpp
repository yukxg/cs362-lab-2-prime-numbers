#include "LList.h"

// Default constructor
LList :: LList () {
	head = NULL;
	size = 0;
} 

// Overridden constructor
LList :: LList (int x) {
	head = new LList_Node (x);
	size = 1;
}

// Destructor
LList :: ~LList() {
	// Only need to something if there are nodes left to delete
	while (size > 0) {
		this -> remove_node ();
	}
}

// Automatically adds 1 through upper to the list
void LList :: populate_list (int upper) {
	for (int i = 0; i < upper; i++) {

	}
}

// Prints everything in the linked list
void LList :: printList () {
	this -> printList(size);
}

// Prints x first values of the linked list
void LList :: printList(int x) {
	for(int i = 0; i < x; i++) {
		//If node[i] -> has_next
			//Print node[i]
	}
}

// Removes the head node
void LList :: remove_node () {
	this -> remove_node (0);
}

// Removes a node at index
void LList :: remove_node (int index) {

}

//Check if there is a next node
bool LList :: has_next () {
	//Check for next node
	return false;
}
