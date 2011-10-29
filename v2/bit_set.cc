#include "bit_set.h"

// TODO : Constructor
Bit_Set :: Bit_Set () {
	cout << "Bit_Set :: Default constructor called" << endl;

	array_size = 0;
	pad = 0;
	bits = NULL;
}

// TODO : Constructor
Bit_Set :: Bit_Set (int num_bits) {
	cout << "Bit_Set :: Constructor (int) called" << endl;

	/* Set the array_size of the array to store the bits */
	pad = num_bits % BITS_PER_BYTE;

	if (pad == 0) {
		array_size = num_bits;
	} else {
		array_size = num_bits + 1;
	}

	/* Actually create the set of bits */
	bits = new char [array_size];

	for (int i = 0; i < array_size; i++) {
		bits [i] = '0';
	}
}

// TODO : Constructor 
Bit_Set :: Bit_Set (char * input_bits) {
	cout << "Bit_Set :: Constructor (char *) called" << endl;

	bits = input_bits;
	pad = -1; // Indicate that we didn't do any checking on it
	
	int i = 4;
//	while (bits [i] != NULL) i++;	
	array_size = i + 1;
}

// TODO : Destructor
Bit_Set :: ~Bit_Set () {
	cout << "Bit_Set :: Destructor called" << endl;

	delete [] bits;
}

// TODO : Method
/* Turns all of the bits on */
void Bit_Set :: set () {
	cout << "Bit_Set :: set () called" << endl;
}

// TODO : Method
/* Returns the index of the first 1 value found (going left to right).  Returns -1 on error */
int Bit_Set :: get_first_one_bit () {
	cout << "Bit_Set :: get_first_one_bit () called" << endl;

	return 0;
}

// TODO : Method
/* Checks to see if the bitset is a bunch of zeroes */
bool Bit_Set :: is_zero () {
	cout << "Bit_Set :: is_zero () called" << endl;

	return true;
} 

// TODO : Method
/* Returns the number of bits in the entire set */
int Bit_Set :: get_size () {
	cout << "Bit_Set :: get_size () called" << endl;

	return 0;
}

// TODO : Method
/* Returns wether the bit is a 1 or 0 at the given index */
int Bit_Set :: get_bit (int index) {
	cout << "Bit_Set :: get_bit called ()" << endl;

	return 0;
}

// TODO : Method
/* Sets the bit to a 1 or 0 at given index */
void Bit_Set :: set_bit (int index, int value) {
	cout << "Bit_Set :: set_bit () called" << endl;
}

// TODO : Method
char * Bit_Set :: to_string () {
	return NULL;
}
