#include "node.h"

/* Constructor */
Node :: Node () {

	prime_set = new set<int>;
	connector = NULL;

}

/* Destructor */
Node :: ~Node () {

	delete (prime_set);
	delete (connector);
}

/* Depending on the role, calls the appropriate method to run the algorithm */
void Node :: run (char role) {
	/* Ask the user which machine will be the Initiator */
	string receiver = ask_user_recv ();
	connector = new Connector (receiver, PORT);

	(role == 'i') ? run_initiator () : run_receiver ();
}

void Node :: run_initiator () {
	/* Some initialization */
	bool found_last_zero = false;
	bool received_zero = false;

	/* Ask the user how many integers to consider and create a bitset */
	int upper = ask_user_upper ();
	Bit_Set * bits = new Bit_Set (upper);
	bits -> set ();

	/* Run the sieve.  If we find the last prime, send a 0 to the receiver. */
	while (!found_last_zero && !received_zero) {
		int prime = get_first_value (bits);
			
		prime_set -> insert (prime);
		cout << "Primes = ";
		print_primes();
		remove_multiples (prime, bits);
		found_last_zero = bits -> is_zero ();

		string * bits_string = bits -> to_string();

		connector -> send_msg (bits_string -> c_str ());

		if (found_last_zero) {
			continue;
		} else {
			connector -> listen_msg ();

			bits = new Bit_Set (connector -> get_msg ());
			received_zero = bits -> is_zero ();
		}
	}
	
	run_end (found_last_zero, received_zero, bits);

	/* Clean up */
	delete (bits);
}

void Node :: run_receiver () {

	/* Initialize a few things */
	bool found_last_zero = false;
	bool received_zero = false;
	Bit_Set * bits = new Bit_Set ();

	/* Run the sieve.  If we find the last prime, send a 0 to the receiver. */
	while (!found_last_zero && !received_zero) {
		connector -> listen_msg ();

		delete (bits);
		bits = new Bit_Set (connector -> get_msg ());
		received_zero = bits -> is_zero ();
		
		if (received_zero) continue;
		
		int prime = get_first_value (bits);
		prime_set -> insert (prime);
		cout << "Primes = ";
		print_primes();
		remove_multiples (prime, bits);
		connector -> send_msg ((char *) ((bits -> to_string ()) -> c_str ()));
	}

	run_end (found_last_zero, received_zero, bits);

	/* Clean up */
	delete (bits);
}

int Node :: ask_user_upper () {
	size_t result;

	cout << endl << "Please enter an upper bound for the range of numbers to consider: ";
	cin >> result;
	cout << endl;

	return result;
}

string Node :: ask_user_recv () {
	string result;
	int input;

	cout << endl;
	cout << "Who is going to be on the receiving end?" << endl;
	cout << "0 - Clark" << endl;
	cout << "1 - Andy" << endl;
	cout << "2 - Shiva" << endl;

	cout << endl << "Input: ";
	cin >> input;

	while (input < 0 || input > 2) {
		cout << endl;
		cout << "Input is out of range, please try again..." << endl;
		cout << "0 - Clark" << endl;
		cout << "1 - Andy" << endl;
		cout << "2 - Shiva" << endl;

		cout << endl << "Input: ";
		cin >> input;
	}

	if (input == 0) {
		result = CLARK;
	} else if (input == 1) {
		result = ANDY;
	} else if (input == 2) {
		result = SHIVA;
	}

	return result;
}
/* 
 * Grabs first bit that's a 1 and returns the associated position with the value
 *	Ex: at index 5, the bit represents a 7
 */
int Node :: get_first_value (Bit_Set * bits) {

	int result;

	/* Find the index position of the first 1 value bit */
	int index = bits -> get_first_one_bit ();

	/* Use the index to find out what the value is */
	if (index == -1) {
		exit (0);
	} else {
		result = index + OFFSET;
	}
	

	return result;
}

/*
 * Takes the first on bit and turns off any bit that's a multiple of the value associated
 * with the first found bit
 * Ex: If we find the prime 5, turn off any bits that's a multiple of 5
 * The return value is based on whether we find any multiples that we've removed
 */ 
void Node :: remove_multiples (int value, Bit_Set * bits) {
	int size = bits -> get_size ();

	for (int i = 0; i < size; i++) {
		if (bits -> get_bit (i) && (i + OFFSET) % value == 0) {
			bits -> set_bit (i, 0);
		} 
	}
}

/* The last part that both run_initiator and run_receiver call */
void Node :: run_end (bool found_last_zero, bool received_zero, Bit_Set * bits) {
	/* Combine the set of primes found by Initiator and Receiver to get final answer */
	if (found_last_zero && received_zero) {
		cout << "Error in Node :: run_initiator () - found_last_zero and received_zero are TRUE\n";
		exit (0);
	} else if (!found_last_zero && !received_zero) {
		cout << "Error in Node :: run_initiator () - found_last_zero and received_zero are FALSE\n";
		exit (0);
	} else if (found_last_zero) {
		cout << "Last prime found!" << endl;

		connector -> send_msg(prime_set_to_string()); // send our answers to the receiver
		connector -> listen_msg (); // get back the final solution
		add_to_prime_set (connector -> get_msg ());
	} else if (received_zero) {
		connector -> listen_msg (); // get the answers from the receiver
		add_to_prime_set (connector -> get_msg ());
		connector -> send_msg(prime_set_to_string()); // send the final solution
	} else {
		cout << "Error in Node :: run_initiator () - Something is seriously wrong here..." << endl;
		exit (0);
	}

	/* Finally, we print the answer out */
	cout << "Final Result: ";
	print_primes();
}

void Node :: add_to_prime_set (string number_list) {
	int temp = 2;
	int size = number_list.size();
	string str = "";
	
	for(int i = 0; i < size; i++) {
		if(number_list[i] != ' ' && number_list[i] != '|') {
			str.push_back(number_list[i]);
		} else {
			temp = atoi(str.c_str());
			if(temp > 0) {
				prime_set -> insert(temp);
				str.clear();
			}
		}
	}
}

string Node :: prime_set_to_string() {
	string result = "";
	stringstream stream;
	set<int>::iterator itr;
	
	for(itr = prime_set -> begin(); itr != prime_set -> end(); itr++) {
		stream << *itr << " ";
	}
	result = stream.str();
	result += "|";
	
	return result;
}

void Node :: print_primes() {
	set<int>::iterator itr;

	if(prime_set -> size() <= 30) {
		for(itr = prime_set -> begin(); itr != prime_set -> end(); itr++) {
			cout << " " << *itr;
		}
	} else {
		set<int>::iterator first10;
		first10 = prime_set -> begin();
		advance(first10, 10);
		for(itr = prime_set -> begin(); distance(itr, first10) > 0; itr++) {
			cout << " " << *itr;
		}
		cout << "...   ...";
		advance(first10, ((prime_set -> size()) - 20));
		for(; first10 != prime_set -> end(); first10++) {
			cout << " " << *first10;
		}
	}
	cout << endl;
}

