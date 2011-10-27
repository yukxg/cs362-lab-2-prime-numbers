#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "bit_set.h"
#include "llist.h"

#define OFFSET 2

using namespace std;

class Node {

	public:
		Node ();
		~Node ();

		void run (char);

	private:
		void run_initiator ();
		void run_receiver ();
		int ask_user_upper ();
		int get_first_value (Bit_Set *);
		void remove_multiples (int, Bit_Set *);
		void send (Bit_Set *);
		void send (LList *);
		bool listen (Bit_Set *);
		void listen (LList *);
		void run_end (bool, bool, Bit_Set *);

		LList * prime_set;
};

#endif
