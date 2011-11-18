#ifndef BIT_SET_H
#define BIT_SET_H

#include <iostream>
#include <string.h>

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
		bool get_bit (int);
		void set_bit (int, int);
		string * to_string ();
		void print_bit_set();
		
	private:
		char * bits;
		int pad;
		int array_size;
		int size;
};

#endif
