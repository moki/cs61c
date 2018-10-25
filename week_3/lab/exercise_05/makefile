CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: ll_cycle.out

ll_cycle.out: ll_cycle.o
	$(CC) $(CFLAGS) -o $@ $^

ll_cycle.o: ll_cycle.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./ll_cycle.out
	make clean

debug: all
	gdb -q -ex 'set args < test-input.txt' ./ll_cycle.out
	make clean

clean:
	$(RM) ll_cycle.out *.o vgcore.* .gdb_*