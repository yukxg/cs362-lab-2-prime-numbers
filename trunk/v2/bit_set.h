#ifndef BIT_SET_H
#define BIT_SET_H

#include <iostream>

#define BITS_PER_BYTE 8

using namespace std;

class Bit_Set {

	public:
		Bit_Set ();
		Bit_Set (int);
		Bit_Set (char *);
		~Bit_Set ();

		void set ();
		int get_first_one_bit ();
		bool is_zero ();
		int get_size ();
		int get_bit (int);
		void set_bit (int, int);
		char * to_string ();
	
	private:
		char * bits;
		int pad;
		int array_size;
};

#endif
