all: main.o node.o bit_set.o connector.o
	g++ main.o node.o bit_set.o connector.o

shiva: main.o node.o bit_set.o connector.o -lnsl -lsocket -lresolv
	g++ -o shiva.out main.o node.o bit_set.o connector.o -lnsl -lsocket -lresolv

run: rem_a_out all a.out
	valgrind ./a.out | tee run.log

test_connector: test_connector.o connector.o
	g++ test_connector.o connector.o

test_connector.o: test_connector.cc
	g++ -Wall -c test_connector.cc

main.o: main.cc
	g++ -Wall -c main.cc

node.o: node.cc node.h
	g++ -Wall -c node.cc

bit_set.o: bit_set.cc bit_set.h
	g++ -Wall -c bit_set.cc

connector.o: connector.cc connector.h
	g++ -Wall -c connector.cc

rem_a_out:
	rm -f a.out

clean:
	rm -f *.o *.log

