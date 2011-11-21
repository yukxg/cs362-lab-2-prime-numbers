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
	int num_messages = 1;
	int index = 0;
	string msg2 = "";

	// Break the message into smaller packets
	if (message.size () > MAX_MSG_SIZE) {
		//Max message size with room for header
		num_messages = (int) (message.size ()/ (MAX_MSG_SIZE - 20));
		if(message.size() % (MAX_MSG_SIZE - 20) != 0) {
			num_messages++;
	   }
	}

	// Tell listener how many messages to expect after this message
	string header = "";
	stringstream stream;
	stream << num_messages << ":";
	header = stream.str();
	
	// Break message into parts and send
	for (int i = 0; i < num_messages; i++) {
		msg2.clear();
		msg2 += header;
		msg2 += message.substr (index, MAX_MSG_SIZE - header.size());
		index += (MAX_MSG_SIZE - header.size());
		sock -> sendTo (msg2.c_str (), msg2.size (), * addr, port);
	}
}

void Connector :: listen_msg () {
	msg -> clear();
	int num_messages = 1;
	stringstream stream;
		
	char buffer [MAX_MSG_SIZE];
	int bytes_rcvd = 0;
	int messagecount = 0;

	do { 
		bytes_rcvd = sock -> recvFrom (buffer, MAX_MSG_SIZE, * addr, port);
		buffer [bytes_rcvd] = '\0';
		messagecount++;
		
		string header = "";
		int count = 0;
		while(buffer[count] != ':') {
			header.push_back(buffer[count]);
			count++;
		}
		
		num_messages = atoi(header.c_str());

		string temp = "";
		temp = buffer;
		msg -> append(temp.substr(count + 1, MAX_MSG_SIZE));
		
	} while(messagecount < num_messages);
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

