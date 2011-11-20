#include "connector.h"
#include <sstream>

Connector :: Connector (string addr_name, int port_num) {
	msg = new string ();
	addr = new string (addr_name);
	port = port_num;
	sock = new UDPSocket (port);
}

Connector :: ~Connector () {
	delete msg;
	delete addr;
	delete sock;
}

void Connector :: send_msg (string message) {
	sleep (1);
	int num_messages = 1;
	int index = 0;
	string msg2 = "";

		// break the message into smaller packets
	if (message.size () > MAX_MSG_SIZE) {
		num_messages = (int) (message.size ()/ MAX_MSG_SIZE);
		num_messages++;
	}

	cout << "number of messages to send: " << num_messages << endl;

	// Tell listener how many messages to expect after this message
	stringstream stream;
	stream << num_messages << endl;
	msg2 = stream.str ();
	cout << "msg2: " << msg2 << endl;
	sock -> sendTo (msg2.c_str (), MAX_MSG_SIZE, * addr, port);
	cout << "sending: " << msg2 << endl;
	
	// Break message into parts and send
	for (int i = 0; i < num_messages; i++) {
		msg2 = "";
		msg2 += message.substr (index, MAX_MSG_SIZE);
		index += MAX_MSG_SIZE;
		sock -> sendTo (msg2.c_str (), msg2.size (), * addr, port);
		cout << "sending: " << msg2 << endl;
	}
}

void Connector :: listen_msg () {
	cout << "listening" << endl;

	int num_messages = 1;
	stringstream stream;
		
	char buffer [MAX_MSG_SIZE];
	int bytes_rcvd = sock -> recvFrom (buffer, MAX_MSG_SIZE, * addr, port);
	buffer [bytes_rcvd] = '\0';
	* msg += buffer;
	
	stream << num_messages;
	num_messages = atoi (msg -> c_str ());
	cout << "number of messages to expect: " << num_messages << endl;
	* msg = "";

	for (int i = 0; i < num_messages; i++) {
		bytes_rcvd = sock -> recvFrom (buffer, MAX_MSG_SIZE, * addr, port);
		buffer [bytes_rcvd] = '\0';
		msg -> append (buffer);
	}

	cout << "message received: " << * msg << endl;
}

void Connector :: set_port (int port_num) { port = port_num;
}

void Connector :: set_receiver (string addr_name) {
	* addr = addr_name;
}

string Connector :: get_msg () {
	return * msg;
}

