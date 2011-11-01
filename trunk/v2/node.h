#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <set>
#include <string>
#include "bit_set.h"
#include "connector.h"

#define OFFSET 2
#define PORT 12323

#define CLARK "clark.cs.uwec.edu"
#define ANDY "andy.cs.uwec.edu"
#define SHIVA "shiva.cs.uwec.edu"

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
		char * ask_user_recv ();
		int get_first_value (Bit_Set *);
		void remove_multiples (int, Bit_Set *);
		void run_end (bool, bool, Bit_Set *);
		void add_to_prime_set (char *);
		string prime_set_to_string ();
		void print_primes();

		set<int> * prime_set;
		Connector * connector;
};

#endif
