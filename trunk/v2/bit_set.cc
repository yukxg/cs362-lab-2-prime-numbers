#include "bit_set.h"

/* Constructor */
Bit_Set :: Bit_Set () {

	array_size = 0;
	size = 0;
	pad = -1;
	bits = NULL;
}

/* Constructor */
Bit_Set :: Bit_Set (int num_bits) {

	/* Set the array_size of the array to store the bits */
	size = num_bits;
	pad = size % BITS_PER_BYTE;

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
Bit_Set :: Bit_Set (string input_bits) {
	
	size = input_bits.size ();
	pad = size % BITS_PER_BYTE;
	
	if (pad == 0) {
		array_size = size / BITS_PER_BYTE;
	} else {
		array_size = (size / BITS_PER_BYTE) + 1;
	}
	
	bits = new char [size];
	memset (bits, 0x00, size);

	for (int i = 0; i < array_size; i++) {
		char result = 0x00;

		for (int j = 0; j < BITS_PER_BYTE; j++) {
			if (i == array_size - 1 && j >= pad) {
				result = result << (BITS_PER_BYTE - pad);
				break;
			} else {
				if (input_bits [(i * BITS_PER_BYTE) + j] == '1') {
					result = result | 0x01;
				}
				
				if ((j < BITS_PER_BYTE - 1)) {
					result = result << 1;
				}
			}
		}	

		bits [i] = result;
	}
}

/* Destructor */
Bit_Set :: ~Bit_Set () {

	delete [] bits;
}

/* Turns all of the bits on */
void Bit_Set :: set () {

	for(int i = 0; i < array_size; i++) {
		bits[i] = 0xFF;
	}
}

/* Returns the index of the first 1 value found (going left to right).  Returns -1 on error */
int Bit_Set :: get_first_one_bit () {

	/*
	int bit = 0;
	int byte = 0;
	for(byte = 0; byte < array_size; byte++) {
		if(bits[byte] != 0x00) {
			break;
		}
	}

	cout << "First non-zero byte found at: " << byte << endl;

	while(!get_bit((byte * BITS_PER_BYTE) + bit)) bit++;
	cout << "first non-zero bit found at: " << bit << endl;
	*/


	int result = 0;

	for (int i = 0; i < size; i++) {
		if (get_bit (i)) {
			result = i;
			break;
		}
	}

	return result;
}

/* Checks to see if the bitset is a bunch of zeroes */
bool Bit_Set :: is_zero () {
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

	/*
	int result = 0;
	if (pad == 0) {
		result = array_size * BITS_PER_BYTE;
	} else {
		result = (((array_size - 1) * BITS_PER_BYTE) + pad);
	}
	
	cout << "bit_set :: get_size returns: " << result << endl;
	*/

	return size;	
}

/* Returns whether the bit is a 1 or 0 at the given index */
bool Bit_Set :: get_bit (int index) {

	char result = 0x00;
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


	return (result != 0x00);
}

/* Sets the bit to a 1 or 0 at given index */
void Bit_Set :: set_bit (int index, int value) {
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
string * Bit_Set :: to_string () {
	int size = get_size();

	// TODO : Check
	string * result = new string ();
		
	for(int i = 0; i < size; i++) {
		//(get_bit(i) ? *result += '1' : *result += '0');
		(get_bit(i) ? *result += "1" : *result += "0");
	}

	return result;
}

// TODO : ?
void Bit_Set :: print_bit_set() {
	cout << "[NRA] - Called print_bit_set() - function is empty\n";
//	int size = get_size();
}

