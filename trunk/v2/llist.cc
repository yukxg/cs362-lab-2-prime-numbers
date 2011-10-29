#include "llist.h"

//Constructor
LList :: LList () {
	cout << "LList :: Constructor called" << endl;
	
	head = NULL;
	size = 0;
}

//Destructor
LList :: ~LList () {
	cout << "LList :: Destructor called" << endl;

	while(size > 0) {
		remove();
	}	
}

//Adds a Node to the list with value == value
void LList :: add (int value) {
	cout << "LList :: add () called" << endl;
	
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

// TODO : Method
void LList :: sort_list () {
	cout << "LList :: sort_list () called" << endl;
}

//Prints the LList by iterating through the nodes and printing the value
//of each, 20 per line;
void LList :: print_list () {
	cout << "LList :: print_list () called" << endl;
	int count = 0;
	
	if(size == 0) {
		cout << "LList is empty!\n";
	} else {
		LList_Node * current = head;
		while(current -> has_next()) {
			if(count == 19) {
				cout << current -> value << ",\n";
				count = 0;
			} else {
				cout << current -> value << ", ";
				count++;
			}
			current = head -> next;
		}
	}
}

//Called by Destructor
void LList :: remove () {
	if(size == 1) {
		delete (head);
		size--;
	} else if(size > 1) {
		LList_Node * to_delete = head;
		head = head -> next;
		
		delete(to_delete);
		size--;	
	}
}

// TODO : Method
char * LList :: to_string () {
	
	return NULL;
}
