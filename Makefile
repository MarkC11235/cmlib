all: test

CC = gcc
CFLAGS = -Wall -g

test: test.o cmlib.o
	$(CC) $(CFLAGS) -o test test.o cmlib.o

clean:
	rm -f *.o test
