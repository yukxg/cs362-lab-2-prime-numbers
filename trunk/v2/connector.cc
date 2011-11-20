#include "connector.h"

Connector :: Connector (string addr_name, int port_num) {
	msg = new string ();
	addr = new string (addr_name);
	port = port_num;
	buf_size = 63000;
	sock = new UDPSocket (port);
}

Connector :: ~Connector () {
	delete msg;
	delete addr;
	delete sock;
}

void Connector :: send_msg (string message) {
	cout << "sending" << endl;
	sock -> sendTo (message.c_str (), message.size (), * addr, port);
}

void Connector :: listen_msg () {
	char buffer [buf_size];

	cout << "listening..." << endl;
	int bytes_rcvd = sock -> recvFrom (buffer, buf_size, * addr, port);
	buffer [bytes_rcvd] = '\0';
	* msg = buffer;
	cout << "received: " << *msg << endl;
}

void Connector :: set_port (int port_num) {
	port = port_num;
}

void Connector :: set_receiver (string addr_name) {
	* addr = addr_name;
}

string Connector :: get_msg () {
	return * msg;
}

