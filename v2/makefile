run: rem_a_out all a.out
	valgrind ./a.out | tee run.log

all: main.o node.o bit_set.o llist.o llist_node.o connector.o
	g++ main.o node.o bit_set.o llist.o llist_node.o connector.o

test_connector: test_connector.o connector.o
	g++ test_connector.o connector.o

test_llist: test_llist.o llist.o llist_node.o
	g++ test_llist.o llist.o llist_node.o

test_connector.o: test_connector.cc
	g++ -Wall -c test_connector.cc

test_llist.o: test_llist.cc
	g++ -Wall -c test_llist.cc

main.o: main.cc
	g++ -Wall -c main.cc

node.o: node.cc node.h
	g++ -Wall -c node.cc

bit_set.o: bit_set.cc bit_set.h
	g++ -Wall -c bit_set.cc

llist.o: llist.cc llist.h
	g++ -Wall -c llist.cc

llist_node.o: llist_node.cc llist_node.h
	g++ -Wall -c llist_node.cc

connector.o: connector.cc connector.h
	g++ -Wall -c connector.cc

rem_a_out:
	rm -f a.out

clean:
	rm -f *.o *.out *.log

