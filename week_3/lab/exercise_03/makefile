CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: ll_equal.out

ll_equal.out: ll_equal.o
	$(CC) $(CFLAGS) -o $@ $^

ll_equal.o: ll_equal.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./ll_equal.out
	make clean

clean:
	$(RM) ll_equal.out *.o vgcore.*