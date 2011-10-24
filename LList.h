#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
		void remove_node ();
		void remove_node (int);
		void add_node (int);

		//void remove_mult(int);
		bool has_next();
	
	private:
		LList_Node * head;
		int size;

};
#endif
