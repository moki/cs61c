CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: int-linked-list.out

int-linked-list.out: main.o int-linked-list.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c int-linked-list.h
int-linked-list.o: int-linked-list.c int-linked-list.h

test: clean all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./int-linked-list.out

clean:
	$(RM) main int-linked-list.out *.o vgcore.*