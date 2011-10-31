#include "bit_set.h"

/* Constructor */
Bit_Set :: Bit_Set () {
	cout << "Bit_Set :: Default constructor called" << endl;

	array_size = 0;
	pad = -1;
	bits = NULL;
}

/* Constructor */
Bit_Set :: Bit_Set (int num_bits) {
	cout << "Bit_Set :: Constructor (int) called" << endl;

	/* Set the array_size of the array to store the bits */
	pad = num_bits % BITS_PER_BYTE;

	if (pad == 0) {
		array_size = num_bits / BITS_PER_BYTE;
	} else {
		array_size = (num_bits / BITS_PER_BYTE) + 1;
	}

	/* Actually create the set of bits */
	bits = new char [array_size];

	/* Initialize char array to all 0 */
	for (int i = 0; i < array_size; i++) {
		bits [i] = 0x00;
	}
}

/* Constructor */
Bit_Set :: Bit_Set (char * input_bits) {
	cout << "Bit_Set :: Constructor (char *) called" << endl;

	bits = input_bits;
	pad = 0; // Indicate that we didn't do any checking on it
	
	int i = 0;
	while (bits[i] != '\0') i++;
	array_size = i + 1;
}

/* Destructor */
Bit_Set :: ~Bit_Set () {
	cout << "Bit_Set :: Destructor called" << endl;

	delete [] bits;
}

/* Turns all of the bits on */
void Bit_Set :: set () {
	cout << "Bit_Set :: set () called" << endl;

	for(int i = 0; i < array_size; i++) {
		bits[i] = 0xFF;
	}
}

/* Returns the index of the first 1 value found (going left to right).  Returns -1 on error */
int Bit_Set :: get_first_one_bit () {
	cout << "Bit_Set :: get_first_one_bit () called" << endl;
	int bit = 0;
	int byte = 0;
	for(byte = 0; byte < array_size; byte++) {
		if(bits[byte] != 0) {
			break;
		}
	}
	while(!get_bit((byte * BITS_PER_BYTE) + bit)) bit++;

	return ((byte * BITS_PER_BYTE) + bit);
}

/* Checks to see if the bitset is a bunch of zeroes */
bool Bit_Set :: is_zero () {
	cout << "Bit_Set :: is_zero () called" << endl;
	bool result = true;

	for(int i = 0; i < array_size; i++) {
		if(bits[i] != 0) {
			result = false;
			break;
		}
	}
	return result;
} 

//Verified
/* Returns the number of bits in the entire set */
int Bit_Set :: get_size () {
	int result = 0;
	if(pad == 0) {
		result = array_size * BITS_PER_BYTE;
	} else {
		result = (((array_size - 1) * BITS_PER_BYTE) + pad);
	}
	
	return result;	
}

/* Returns whether the bit is a 1 or 0 at the given index */
bool Bit_Set :: get_bit (int index) {
	cout << "Bit_Set :: get_bit called (); index is " << index << endl;
	bool result = true;
	int byte = index / BITS_PER_BYTE;
	int bit = index % BITS_PER_BYTE;	
	char row = bits[byte];

	switch(bit) {
		case 0:
			result = (row & 0x80);
			break;
		case 1:
			result = (row & 0x40);
			break;
		case 2:
			result = (row & 0x20);
			break;
		case 3:
			result = (row & 0x10);
			break;
		case 4:
			result = (row & 0x08);
			break;
		case 5:
			result = (row & 0x04);
			break;
		case 6:
			result = (row & 0x02);
			break;
		case 7:
			result = (row & 0x01);
			break;
		default:
			cout << "Error in Bit_Set :: get_bit(index); given: " << index << endl;
	}

	return result;
}

/* Sets the bit to a 1 or 0 at given index */
void Bit_Set :: set_bit (int index, int value) {
	cout << "Bit_Set :: set_bit () called" << endl;
	int byte = index / BITS_PER_BYTE;
	int bit = index % BITS_PER_BYTE;
	char row = bits[byte];

	switch(bit) {
		case 0:
			(value == 0) ? (bits[byte] = row & 0x7F) : (bits[byte] = row | 0x80);
			break;
		case 1:
         (value == 0) ? (bits[byte] = row & 0xBF) : (bits[byte] = row | 0x40);
			break;
		case 2:
         (value == 0) ? (bits[byte] = row & 0xDF) : (bits[byte] = row | 0x20);
			break;
		case 3:
         (value == 0) ? (bits[byte] = row & 0xEF) : (bits[byte] = row | 0x10);
			break;
		case 4:
			(value == 0) ? (bits[byte] = row & 0xF7) : (bits[byte] = row | 0x08);
			break;
		case 5:
			(value == 0) ? (bits[byte] = row & 0xFB) : (bits[byte] = row | 0x04);
			break;
		case 6:
			(value == 0) ? (bits[byte] = row & 0xFD) : (bits[byte] = row | 0x02);
			break;
		case 7:
			(value == 0) ? (bits[byte] = row & 0xFE) : (bits[byte] = row | 0x01);
			break;
		default:
			cout << "Error in Bit_Set :: set_bit(index, value); index = " << index << endl;
	}
}

/* Returns a char * of 0's and 1's with no spaces (i.e. "001100") */
char * Bit_Set :: to_string () {
	cout << "Bit_Set :: to_string() called" << endl;
	int size = get_size();
	char * result = new char[size];
	
	for(int i = 0; i < size; i++) {
		(get_bit(i) ? result[i] = '1' : result[i] = '0');
	}

	return result;
}

void Bit_Set :: print_bit_set() {
	int size = get_size();
	
	for(int i = 0; i < size; i++) {
		get_bit(i) ? cout << "1" : cout << "0";
	}
	cout << endl;
}

