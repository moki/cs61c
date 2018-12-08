CC=gcc
C_FLAGS=--std=c99

all: randomized sorted

clean:
	rm -f randomized sorted > /dev/null 2>&1

sorted: sorted.c common.h
	$(CC) $(C_FLAGS) sorted.c -o sorted

randomized: randomized.c common.h
	$(CC) $(C_FLAGS) randomized.c -o randomized
