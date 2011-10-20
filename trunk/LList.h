#ifndef LLIST_H
#define LLIST_H

#include<iostream>
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

		//void removeMult(int);
	private:
		LList_Node * head;
		int size;

};
#endif
