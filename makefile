run: rem_a_out all a.out
	valgrind ./a.out | tee run.log

all: main.o node.o
	g++ main.o node.o

main.o: main.cc
	g++ -Wall -c main.cc

node.o: node.cc node.h
	g++ -Wall -c node.cc

rem_a_out:
	rm -f a.out

clean:
	rm -f *.o *.out *.log
