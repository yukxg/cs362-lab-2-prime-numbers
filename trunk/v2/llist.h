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
		void print_list (int);
		void remove ();
		char * to_string ();
		int get_size ();
		int get_node (int);

	protected:
		LList_Node * get_head ();

	private:
		LList_Node * head;
		int size;
		void remove_nodes ();
};

#endif
