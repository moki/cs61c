CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: interactive_hello.out

interactive_hello.out: interactive_hello.o
	$(CC) $(CFLAGS) -o $@ $^

interactive_hello.o: interactive_hello.c

test: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./interactive_hello.out
	make clean

debug: all
	gdb -q -ex 'set args < test-input.txt' ./interactive_hello.out
	make clean

clean:
	$(RM) interactive_hello.out *.o vgcore.* .gdb_*