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
}

// Removes the head node
void LList :: remove_node () {
	if (size == 1) {
		free (head);
		size = 0;
	} else if (size > 1) {
		LList_Node * head_copy = head;
		head = head -> next;

		free (head_copy);
		size--;
	}
}

// Removes a node at index
void LList :: remove_node (int index) {
	if (index == 0) {
		remove_node ();
	} else if (index > 0 && index < size) {
		LList_Node * current_node = head;
		LList_Node * next_node;

		for (int i = 0; i < index; i++) {
			current_node = current_node -> next;
		}

		next_node = current_node -> next;
		current_node -> next = next_node -> next;

		free (next_node);
		size--;

	} else if (index >= size){
		perror ("LList:remove_node error - index is greater than size");
	} else {
		perror ("LList:remove_node error - unknown error");
	}
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

