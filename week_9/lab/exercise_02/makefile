CC=gcc
CFLAGS=-std=c99 -Wall -O3 -Wno-pointer-arith

all: matrix-multiply.out

matrix-multiply.out: matrix-multiply.o
	$(CC) $(CFLAGS) -o $@ $^

matrix-multiply.o: matrix-multiply.c

test: all
	./matrix-multiply.out
	make clean

clean:
	$(RM) matrix-multiply.out *.o vgcore.*