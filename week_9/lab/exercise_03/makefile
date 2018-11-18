CC=gcc
CFLAGS=-std=c99 -Wall -O3 -Wno-pointer-arith

TEST_INPUT_1_1=100 20
TEST_INPUT_1_2=1000 20
TEST_INPUT_1_3=2000 20
TEST_INPUT_1_4=5000 20
TEST_INPUT_1_5=10000 20

TEST_INPUT_2_1=10000 50
TEST_INPUT_2_2=10000 100
TEST_INPUT_2_3=10000 500
TEST_INPUT_2_4=10000 1000
TEST_INPUT_2_5=10000 5000

all: matrix-transpose.out

matrix-transpose.out: matrix-transpose.o
	$(CC) $(CFLAGS) -o $@ $^

matrix-transpose.o: matrix-transpose.c

test: all
	@echo -e "\e[1;32mn: 100 block_size: 20\e[0m"
	./matrix-transpose.out ${TEST_INPUT_1_1}
	@echo -e "\e[1;32mn: 1000 block_size: 20\e[0m"
	./matrix-transpose.out ${TEST_INPUT_1_2}
	@echo -e "\e[1;32mn: 2000 block_size: 20\e[0m"
	./matrix-transpose.out ${TEST_INPUT_1_3}
	@echo -e "\e[1;32mn: 5000 block_size: 20\e[0m"
	./matrix-transpose.out ${TEST_INPUT_1_4}
	@echo -e "\e[1;32mn: 10000 block_size: 20\e[0m"
	./matrix-transpose.out ${TEST_INPUT_1_5}
	@echo ""
	@echo ""
	@echo ""
	@echo -e "\e[1;32mn: 10000 block_size: 50\e[0m"
	./matrix-transpose.out ${TEST_INPUT_2_1}
	@echo -e "\e[1;32mn: 10000 block_size: 100\e[0m"
	./matrix-transpose.out ${TEST_INPUT_2_2}
	@echo -e "\e[1;32mn: 10000 block_size: 500\e[0m"
	./matrix-transpose.out ${TEST_INPUT_2_3}
	@echo -e "\e[1;32mn: 10000 block_size: 1000\e[0m"
	./matrix-transpose.out ${TEST_INPUT_2_4}
	@echo -e "\e[1;32mn: 10000 block_size: 5000\e[0m"
	./matrix-transpose.out ${TEST_INPUT_2_5}
	make clean

clean:
	$(RM) matrix-transpose.out *.o vgcore.*