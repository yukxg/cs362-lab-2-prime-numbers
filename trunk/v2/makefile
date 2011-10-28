run: rem_a_out all a.out
	valgrind ./a.out | tee run.log

all: main.o node.o bit_set.o llist.o connector.o
	g++ main.o node.o bit_set.o llist.o connector.o

main.o: main.cc
	g++ -Wall -c main.cc

node.o: node.cc node.h
	g++ -Wall -c node.cc

bit_set.o: bit_set.cc bit_set.h
	g++ -Wall -c bit_set.cc

llist.o: llist.cc llist.h
	g++ -Wall -c llist.cc

connector.o: connector.cc connector.h
	g++ -Wall -c connector.cc

rem_a_out:
	rm -f a.out

clean:
	rm -f *.o *.out *.log

