#include "llist.h"

//Constructor
LList :: LList () {
	
	head = NULL;
	size = 0;
}

//Destructor
LList :: ~LList () {

	while(size > 0) {
		remove();
	}	
}

//Adds a Node to the list with value == value
void LList :: add (int value) {
	
	if (size == 0) {
		head = new LList_Node (value);	
	} else {
		LList_Node * current = head;

		while(current -> has_next()) {
			current = current -> next;
		}

		current -> next = new LList_Node(value);
	}	

	size++;
}

/* Sorts the list by doing a mergesort on the members */
// TODO : Method
void LList :: sort_list () {

}

//Prints the LList by iterating through the nodes and printing the value
//of each, 20 per line;
void LList :: print_list () {
	
	LList_Node * current_node = head;

	cout << "{";

	for (int i = 0; i < size - 1; i++) {
		cout << current_node -> value << ", ";
		current_node = current_node -> next;
	}

	if (size > 0) {
		cout << current_node -> value;
	}

	cout << "}" << endl;
}

//Called by Destructor
void LList :: remove () {
	if(size == 1) {
		delete (head);
		size--;
	} else if(size > 1) {
		LList_Node * to_delete = head;
		head = head -> next;
		delete (to_delete);
		size--;	
	}
}

// TODO : Method
char * LList :: to_string () {
	
	return NULL;
}

/* Gets the value of the LList_Node at the given index */
int LList :: get_node (int index) {

	LList_Node * current_node = head;

	for (int i = 0; i < index; i++) {
		current_node = current_node -> next;
	}

	return current_node -> value;
}

LList_Node * LList :: get_head () {
	return head;
}

int LList :: get_size () {
	return size;
}

void LList :: print_list (int nodes) {

	cout << "{";

	for (int i = 0; i < nodes - 1; i++) {
		cout << get_node (i) << ", ";
	}

	cout << get_node (nodes - 1) << "}" << endl;
}

