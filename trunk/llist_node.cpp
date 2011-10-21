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
