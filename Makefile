all: test

CC = gcc
CFLAGS = -Wall -g

test: test.o cmlib.o
	$(CC) $(CFLAGS) -o test test.o cmlib.o

test.o: test.c cmlib.h
	$(CC) $(CFLAGS) -c test.c

cmlib.o: cmlib.c cmlib.h
	$(CC) $(CFLAGS) -c cmlib.c

clean:
	rm -f *.o test
