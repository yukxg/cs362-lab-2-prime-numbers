#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>

using namespace std;

class Connector {

	public:
		Connector ();
		~Connector ();

		void set_port (int);
		void set_receiver (char *);
		void send (char *);
		void listen ();
		char * get_msg ();

	private:

};

#endif
