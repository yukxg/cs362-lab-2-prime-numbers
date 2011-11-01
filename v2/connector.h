#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <iostream>
#include <netdb.h>
#include <string>

using namespace std;

#define BACKLOG 10 // how many pending connections queue will hold
#define MAXDATASIZE 50000 // max number of bytes we can get at once
#define RECV_SIZE 50000 // how many character to use for the receiver variable

class Connector {

	public:
		Connector ();
		~Connector ();
		
		void set_port (int);
		void set_receiver (char *);
		void send_msg (const char *);
		void listen_msg ();
		char * get_msg ();
		
	private:
		friend void sigchld_handler (int);
		void listen_msg_helper ();
		
		int port;
		char * receiver;
		char * msg;
};


#endif

