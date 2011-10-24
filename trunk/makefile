all: main.o LList.o llist_node.o
	g++ main.o LList.o llist_node.o

main.o: main.cpp
	g++ -Wall -c main.cpp

LList.o: LList.cpp LList.h
	g++ -Wall -c LList.cpp LList.h

llist_node.o: llist_node.cpp llist_node.h
	g++ -Wall -c llist_node.cpp llist_node.h

clean: 
	rm -f *.o *.gch *.out
