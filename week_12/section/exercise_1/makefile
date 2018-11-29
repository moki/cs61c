CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -O3 -mavx2 -freorder-blocks -Wno-pointer-arith

all: vector-product.out

vector-product.out: main.o vector-product.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c vector-product.h
vector-product.o: vector-product.c vector-product.h

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./vector-product.out
	make clean

clean:
	$(RM) vector-product.out *.o vgcore.*