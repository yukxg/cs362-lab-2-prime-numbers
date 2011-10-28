#include "connector.h"

// TODO : Constructor
Connector :: Connector () {
	cout << "Connector Default constructor called" << endl;
}

// TODO : Destructor
Connector :: ~Connector () {
	cout << "Connector destructor called" << endl;
}

// TODO : Method
void Connector :: set_port (int) {
	cout << "Connector :: set_port called" << endl;
}

// TODO : Method
void Connector :: send (char *) {
	cout << "Connector :: send () called" << endl; 
}

// TODO : Method
void Connector :: listen () {
	cout << "Connector :: listen () called" << endl;
}

// TODO : Method
void Connector :: set_receiver (char *) {
	cout << "Connector :: set_receiver () called" << endl;
}

// TODO : Method
char * Connector :: get_msg () {
	cout << "Connector :: get_msg () called" << endl;
	return NULL;
}
