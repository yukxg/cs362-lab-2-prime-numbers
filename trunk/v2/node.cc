#include "node.h"

// TODO : Constructor
Node :: Node () {
	cout << "Node - Default constructor called" << endl;

	prime_set = new LList ();
	connector = new Connector ();
	connector -> set_port (PORT);

}

// TODO : Destructor
Node :: ~Node () {
	cout << "Node - Destructor called" << endl;

	delete (prime_set);
	delete (connector);
}

/* Depending on the role, calls the appropriate method to run the algorithm */
void Node :: run (char role) {
	cout << "Node - run called" << endl;
	(role == 'i') ? run_initiator () : run_receiver ();
}

void Node :: run_initiator () {
	cout << "Node - run_initiator called" << endl;

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
		prime_set -> add (prime);
		remove_multiples (prime, bits);
		found_last_zero = bits -> is_zero ();
		connector -> send_msg (bits -> to_string ());

		if (found_last_zero) {
			continue;
		} else {
			connector -> listen_msg ();
			delete (bits);
			bits = new Bit_Set (connector -> get_msg ());
			received_zero = bits -> is_zero ();
		}
	}
	
	run_end (found_last_zero, received_zero, bits);
}

void Node :: run_receiver () {
	cout << "Node :: run_receiver () called" << endl;

	/* Initialize a few things */
	bool found_last_zero = false;
	bool received_zero = false;
	Bit_Set * bits = new Bit_Set ();

	/* Ask the user which machine will be the Initiator */
	char * receiver = ask_user_recv ();
	connector -> set_receiver (receiver);

	/* Run the sieve.  If we find the last prime, send a 0 to the receiver. */
	while (!found_last_zero && !received_zero) {
		connector -> listen_msg ();
		delete (bits);
		bits = new Bit_Set (connector -> get_msg ());
		received_zero = bits -> is_zero ();
		if (received_zero) continue;
		int prime = get_first_value (bits);
		prime_set -> add (prime);
		remove_multiples (prime, bits);
		connector -> send_msg (bits -> to_string ());
	}

	run_end (found_last_zero, received_zero, bits);
}

int Node :: ask_user_upper () {
	size_t result;

	cout << endl << "Please enter an upper bound for the range of numbers to consider: ";
	cin >> result;
	cout << endl;

	return result;
}

char * Node :: ask_user_recv () {
	char * result;
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
	cout << "Node :: get_first_value called" << endl;

	int result;

	/* Find the index position of the first 1 value bit */
	int index = bits -> get_first_one_bit ();

	/* Use the index to find out what the value is */
	// If there's 
	if (index == -1) {
		cout << "No bits have a 1 value..." << endl;
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
	cout << "Node :: remove_multiples called" << endl;

	int size = bits -> get_size ();

	for (int i = 0; i < size; i++) {
		if (bits -> get_bit (i) && (i + OFFSET) % value == 0) bits -> set_bit (i, 0);
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
		cout << "I found the last prime!" << endl;

		connector -> send_msg (prime_set -> to_string ()); // send our answers to the receiver
		connector -> listen_msg (); // get back the final solution
		add_to_prime_set (connector -> get_msg ());
	} else if (received_zero) {
		connector -> listen_msg (); // get the answers from the receiver
		add_to_prime_set (connector -> get_msg ());
		prime_set -> sort_list ();
		connector -> send_msg (prime_set -> to_string ()); // send the final solution
	} else {
		cout << "Error in Node :: run_initiator () - Something is seriously wrong here..." << endl;
		exit (0);
	}

	/* Finally, we print the answer out */
	prime_set -> print_list ();

	/* Clean up */
	delete (bits);
}

// TODO : Method
void Node :: add_to_prime_set (char * number_list) {
	cout << "Node :: add_to_prime_set () called" << endl;
}
