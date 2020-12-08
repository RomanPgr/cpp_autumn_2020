.PHONY: all clean tests
CC=g++
CFLAGS=-Wall -Wextra -std=c++17
CLINK=-c

all: main

main: main.o allocator.o
	$(CC) $(CFLAGS) main.o allocator.o -o main

allocator.o: allocator.cpp
	$(CC) $(CFLAGS) $(CLINK) allocator.cpp -o allocator.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(CLINK) main.cpp -o main.o
	
clean:
	rm -f *.o test? output.txt
	
test: allocator.o
	$(CC) $(CFLAGS) test1.cpp allocator.o -o test1
	./test1 > output.txt
	if diff output.txt outtest1.txt >> /dev/null ; then echo "Test 1 succed\n" ; else echo "Test 1 failed\n" ; fi
	
	$(CC) $(CFLAGS) test2.cpp allocator.o -o test2
	./test2 > output.txt
	if diff output.txt outtest2.txt >> /dev/null ; then echo "Test 2 succed\n" ; else echo "Test 2 failed\n" ; fi
	
	$(CC) $(CFLAGS) test3.cpp allocator.o -o test3
	./test3 > output.txt
	if diff output.txt outtest3.txt >> /dev/null ; then echo "Test 3 succed\n" ; else echo "Test 3 failed\n" ; fi
	
	rm -f test? output.txt
