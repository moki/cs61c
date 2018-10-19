CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3 -Wno-pointer-arith

all: int-stack.out

int-stack.out: main.o int-stack.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c int-stack.h
int-stack.o: int-stack.c int-stack.h

test: clean all
	@echo -e "\e[1;37m"
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./int-stack.out
	@echo -e "\e[0m"

clean:
	@echo -e "\e[1;34m"
	$(RM) main int-stack.out *.o vgcore.*
	@echo -e "\e[0m"