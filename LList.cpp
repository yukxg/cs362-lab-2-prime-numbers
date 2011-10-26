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

// add specified number of nodes, starting from 2
void LList :: populate_list (int upper) {
	for (int i = 0; i < upper; i++) {
		this -> add_node (i + 2);
	}
}

// Prints everything in the linked list
void LList :: printList () {
	this -> printList(size);
}

// Prints x first values of the linked list
void LList :: printList(int range) {
	LList_Node * current_node = head;

	// make sure range is acceptable...
	if (range > size) {
		range = size;
	}

	for(int i = 0; i < range; i++) {
		current_node -> print_node ();
		
		if (i < range - 1) {
			cout << ", ";
		}

		current_node = current_node -> next; 
	}

	cout << endl;
}

// Removes the head node and returns the value of the node
int LList :: remove_node () {
	int result = head -> get_value ();

	if (size == 1) {
		delete (head);
		size = 0;
	} else if (size > 1) {
		LList_Node * head_copy = head;
		head = head -> next;

		delete (head_copy);
		size--;
	}

	return result;
}

// Removes a node at index and returns the value of the node
int LList :: remove_node (int index) {
	int result = 0;

	if (index == 0) {
		result = remove_node ();
	} else if (index > 0 && index < size) {
		LList_Node * current_node = head;
		LList_Node * next_node;

		for (int i = 0; i < index - 1; i++) {
			current_node = current_node -> next;
		}

		next_node = current_node -> next;
		current_node -> next = next_node -> next;

		result = next_node -> get_value ();
		delete (next_node);
		size--;

	} else if (index >= size){
		perror ("LList:remove_node error - index is greater than size");
	} else {
		perror ("LList:remove_node error - unknown error");
	}

	return result;
}

// Adds an LList_Node to the end of our LList
void LList :: add_node (int node) {
	if (size == 0) {
		head = new LList_Node (node);
	} else {
		LList_Node * current_node = head;

		while (current_node -> has_next () ) {
			current_node = current_node -> next;
		}

		current_node -> next = new LList_Node (node);
	}

	size++;
}

// removes the first node, then removes all nodes
// that are multiples of the first node and then
// returns that first node
int LList :: remove_mult () {
	LList_Node * current_node = head -> next;
	int result = remove_node ();

	for (int i = 0; i < size; i++) {
		if (current_node -> get_value () % result == 0) {
			remove_node (i);
		}

		current_node = current_node -> next;
	}

	return result;
}
