#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "llist_node.h"

using namespace std;

class LList {

	public:
		LList ();
		~LList ();

		void add (int);
		void sort_list ();
		void print_list ();
		void remove ();
		char * to_string ();

	private:
		LList_Node * head;
		int size;
};

#endif
