.PHONY: all clean test
CC=g++
CFLAGS=-Wall -Wextra -std=c++17 -march=native -O2
CLINK=-c

all: main

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main
	
clean:
	rm -f test1 test2 test3 output.txt
	
test: 
	$(CC) $(CFLAGS) test1.cpp -o test1
	./test1 > output.txt
	if diff output.txt outtest1.txt >> /dev/null ; then echo "Test succed\n" ; else echo "Test failed\n" ; fi
	
	$(CC) $(CFLAGS) test2.cpp -o test2
	./test2 > output.txt
	if diff output.txt outtest2.txt >> /dev/null ; then echo "Test succed\n" ; else echo "Test failed\n" ; fi
	
	$(CC) $(CFLAGS) test3.cpp -o test3
	./test3 > output.txt
	if diff output.txt outtest3.txt >> /dev/null ; then echo "Test succed\n" ; else echo "Test failed\n" ; fi
	
	rm -f test1 test2 test3 output.txt
