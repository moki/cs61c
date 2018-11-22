CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -O3 -mavx2 -Wno-pointer-arith

all: dgemm.out

dgemm.out: main.o dgemm.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c dgemm.h
dgemm.o: dgemm.c dgemm.h

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./dgemm.out
	make clean

clean:
	$(RM) dgemm.out *.o vgcore.*