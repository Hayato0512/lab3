all: test

test: test.o List.o Node.o
	g++ -g -Wall test.o List.o Node.o -o test

test.o: test.cpp List.h
	g++ -Wall -c test.cpp -g 

List.o: List.h List.cpp Node.h
	g++ -Wall -c List.cpp -g 

Node.o: Node.h Node.cpp
	g++ -Wall -c Node.cpp -g 

clean:
	rm -f test *.o