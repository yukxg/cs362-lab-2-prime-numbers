#include "connector.h"

Connector :: Connector () {
	receiver = new char [RECV_SIZE];
	memset ((void *) receiver, '\0', (size_t) RECV_SIZE);
	
	port = 0;
	msg = new char [MAXDATASIZE];
}

Connector :: ~Connector () {
	delete[] receiver;
	delete[] msg;
}

void Connector :: set_port (int port_value) {
	port = port_value;
}

void Connector :: set_receiver (char * receiver_name) {

	int size = 0;
	while (receiver_name [size] != '\0') size++;

	strncpy (receiver, receiver_name, size);

	cout << "receiver set to: " << receiver << endl;
}

void sigchld_handler(int s) {
	while(wait (NULL) > 0);
}

/* From sender.c */
void Connector :: send_msg (const char * message) {

	int sockfd, new_fd; // listen on sock_fd, new connection on new_fd
	struct sockaddr_in my_addr; // my address information
	struct sockaddr_in their_addr; // connector’s address information
	int sin_size;
	struct sigaction sa;
	int yes = 1;
	
	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) == -1) {
		perror ("socket");
		exit(1);
	}

	if (setsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, & yes, sizeof(int)) == -1) {
		perror ("setsockopt");
		exit (1);
	}

	my_addr.sin_family = AF_INET; // host byte order
	my_addr.sin_port = htons (port); // short, network byte order
	my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
	memset(& (my_addr.sin_zero), '0', 8); // zero the rest of the struct
	
	if (bind (sockfd, (struct sockaddr *) & my_addr, sizeof (struct sockaddr)) == -1) {
		perror ("bind");
		exit (1);
	}
	
	if (listen (sockfd, BACKLOG) == -1) {
		perror ("listen");
		exit (1);
	}
	
	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset (& sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	
	if (sigaction (SIGCHLD, & sa, NULL) == -1) {
		perror ("sigaction");
		exit (1);
	}
	
	bool keep_going = true;

	while (keep_going) { // main accept() loop
		sin_size = sizeof (struct sockaddr_in);
		
		if ((new_fd = accept (sockfd, (struct sockaddr *) & their_addr, (socklen_t *) & sin_size)) == -1) {
			perror ("accept");
			continue;
		}
		
		printf ("server: got connection from %s\n", inet_ntoa (their_addr.sin_addr));
		
//		if (!fork ()) { // this is the child process
			close (sockfd); // child doesn't need the listener
			
			cout << "Sending message: " << message << endl;
			int bytes_sent;

			if ((bytes_sent = send (new_fd, message, MAXDATASIZE, 0)) == -1) {
				perror ("send");
			}
			
			if (bytes_sent == 0) {

			} else {
				keep_going = false;
			}

//			close (new_fd);
//			exit (0);
//		}
		
		close (new_fd); // parent doesn't need this
	}
}

void Connector :: listen_msg () {
	memset (msg, '\0', MAXDATASIZE);
	//sleep (1);
	usleep (50000);
	listen_msg_helper ();
}

/* From client.c */
void Connector :: listen_msg_helper () {
	
	int sockfd, numbytes;
	char buf [MAXDATASIZE];
	struct hostent * he;
	struct sockaddr_in their_addr; // connector's address information
	
	if ((he = gethostbyname (receiver)) == NULL) { // get the host info
		perror ("gethostbyname");
		exit (1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror ("socket");
		exit (1);
	}
	
	their_addr.sin_family = AF_INET; // host byte order
	their_addr.sin_port = htons (port); // short, network byte order
	their_addr.sin_addr = * ((struct in_addr *) he -> h_addr);
	memset(& (their_addr.sin_zero), '\0', 8); // zero the rest of the struct
	
	if (connect (sockfd, (struct sockaddr *) & their_addr, sizeof (struct sockaddr)) == -1) {
		perror ("connect");
		exit (1);
	}
	
	if ((numbytes = recv (sockfd, buf, MAXDATASIZE - 1, 0)) == -1) {
		perror ("recv");
		exit (1);
	}
	

	buf [numbytes] = '\0';
	strncpy (msg, buf, numbytes + 1);
	printf ("Received: %s\n",buf);
	close (sockfd);
}

char * Connector :: get_msg () {
	return msg;
}
