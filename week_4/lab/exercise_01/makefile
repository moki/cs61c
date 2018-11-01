CC=gcc
CFLAGS=-std=c99 -Wall -g3 -Wno-pointer-arith

all: bit_ops.out

bit_ops.out: bit_ops.o
	$(CC) $(CFLAGS) -o $@ $^

bit_ops.o: bit_ops.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./bit_ops.out
	make clean

clean:
	$(RM) bit_ops.out *.o vgcore.*