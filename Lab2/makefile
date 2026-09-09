CC=gcc
CFLAGS=-c -Wall

all: program

program: main.o isOdd.o	
	$(CC) main.o isOdd.o -o program

main.o: main.c isOdd.h
	$(CC) $(CFLAGS) main.c

isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) isOdd.c

clean:
	rm -f *.o program

