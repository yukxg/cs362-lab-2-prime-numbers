#ifndef LLIST_NODE_H
#define LLIST_NODE_H

#include <iostream>

using namespace std;

class LList_Node {
	public:
		// allow LList to get access to our private members
		friend class LList;

		LList_Node ();
		LList_Node (int);

		bool has_next ();

	protected:
		int value;
		LList_Node * next;
};

#endif
