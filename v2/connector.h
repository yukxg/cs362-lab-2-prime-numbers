#ifndef CLIENT_H
#define CLIENT_H

#include <iostream> 
#include <cstdlib>
#include <string>
#include "practical_socket.h"

using namespace std;

class Connector {
	public:
		Connector (string, int);
		~Connector ();

		void send_msg (string);
		void listen_msg ();

		void set_port (int);
		void set_receiver (string);
		string get_msg ();

	private:
		string * msg;
		string * addr;
		UDPSocket * sock;
		unsigned short port;
		int buf_size;
		
		// TCP client handling function
//		void HandleTCPClient (); 
};

#endif
