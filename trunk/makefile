all: main.o LList.o
	g++ main.o LList.o

main.o: main.cpp
	g++ -Wall -c main.cpp

LList.o: LList.cpp
	g++ -Wall -c LList.cpp

clean: 
	rm -f *.o *.out
