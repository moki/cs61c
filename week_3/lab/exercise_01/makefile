CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: eccentric.out

eccentric.out: eccentric.o
	$(CC) $(CFLAGS) -o $@ $^

eccentric.o: eccentric.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./eccentric.out
	make clean

clean:
	$(RM) eccentric.out *.o vgcore.*