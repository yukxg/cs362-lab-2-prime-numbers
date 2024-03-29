#include "llist_node.h"

LList_Node :: LList_Node () {
	value = 0;
	next = NULL;
}

// Creates a new node with value n
LList_Node :: LList_Node (int n) {
	value = n;
	next = NULL;
}

bool LList_Node :: has_next () {
	return !(next == NULL);
}

void LList_Node :: print_node () {
	cout << value;
}

int LList_Node :: get_value () {
	return value;
}
