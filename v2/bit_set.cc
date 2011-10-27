#include "bit_set.h"

// TODO : Constructor
Bit_Set :: Bit_Set () {
	cout << "Bit_Set :: Default constructor called" << endl;
}

// TODO : Constructor
Bit_Set :: Bit_Set (int num_bits) {
	cout << "Bit_Set :: Constructor (int) called" << endl;
}

// TODO : Destructor
Bit_Set :: ~Bit_Set () {
	cout << "Bit_Set :: Destructor called" << endl;
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

	return false;
} 

// TODO : Method
/* Returns the size of the list of bits */
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
