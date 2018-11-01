CC=gcc
CFLAGS=-std=c99 -Wall -g3 -Wno-pointer-arith

all: lfsr.out

lfsr.out: lfsr.o
	$(CC) $(CFLAGS) -o $@ $^

lfsr.o: lfsr.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./lfsr.out
	make clean

clean:
	$(RM) lfsr.out *.o vgcore.*