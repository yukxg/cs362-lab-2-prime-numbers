#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <stdio.h>
#include "llist_node.h"

using namespace std;

class LList {
	public:
		LList();
		LList(int);
		~LList();

		void populate_list (int);
		void printList ();
		void printList(int);
		int remove_node ();
		int remove_node (int);
		void add_node (int);
		int remove_mult();
	
	private:
		LList_Node * head;
		int size;

};
#endif
