.PHONY: all clean tests
CC=g++
CFLAGS=-Wall -Wextra -std=c++17 -march=native -O2
CLINK=-c

all: main

main: main.o mymatrix.o
	$(CC) $(CFLAGS) main.o mymatrix.o -o main

mymatrix.o: mymatrix.cpp
	$(CC) $(CFLAGS) $(CLINK) mymatrix.cpp -o mymatrix.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(CLINK) main.cpp -o main.o
	
clean:
	rm -f mymatrix.o main.o
	
test: mymatrix.o
	$(CC) $(CFLAGS) test.cpp mymatrix.o -o test
	./test > output.txt
	if diff output.txt outtest.txt >> /dev/null ; then echo "Test succed\n" ; else echo "Test failed\n" ; fi
	
	rm -f test output.txt
