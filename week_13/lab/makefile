CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -O3 -fopenmp -pthread -mavx2 -Wno-pointer-arith

all: v-add.o dot-p.o

v-add.o: v-add.c
	$(CC) $(CFLAGS) v-add.c -o v-add.out

test-v-add: v-add.o
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./v-add.out
	make clean

dot-p.o: dot-p.c
	$(CC) $(CFLAGS) dot-p.c -o dot-p.out

test-dot-p: dot-p.o
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./dot-p.out
	make clean

clean:
	$(RM) v-add.out dot-p.out *.o vgcore.*