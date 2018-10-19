## Section 02

C Memory Management and RISCV Intro

```
./section-02.pdf
```

## 1. C Memory Management

### 1. Match the items on the left with the memory segment in which they are stored.
Answers may be used more than once, and more than one answer may be required.

```
1. Static variables     - B		A. Code
2. Local variables      - D		B. Static
3. Global variables     - B		C. Heap
4. Constants	        - A,B,D		D. Stack
5. Machine Instructions - A
6. Result of malloc()	- C
7. String Literals	- B
```

### 2. Write the code necessary to properly allocate memory (on the heap) in the following scenarios

1. An array arr of k integers

```
int *arr = malloc(sizeof(int) * k);
```

2. A string str containing p characters

```
char *str = malloc(sizeof(char) * p);
```

3. An n × m matrix mat of integers initialized to zeros

```
int *mat = calloc(n * m, sizeof(int));
```

### 3. What is wrong with the C code below?

```
int* pi = malloc(314 * sizeof(int));

if(!raspberry) {
	pi = malloc(1 * sizeof(int));
}

return pi;
```

```
memory leak size of 314 * size of the int type in bytes, if not "raspberry"
```

### 4. Write code to prepend (add to the start) to a linked list, and to free/empty the entire list.

```
cd int_linked_list/

make
```

## 2. Data Structures in C
In this question, we will implement a array-based stack of integers in C. The stack will be represented by the
struct below.

```
cd int_stack
make
```

## 3. RISC-V Intro

### 1. Explain RISC-V instructions

Assume we have an array in memory that contains int* arr = {1,2,3,4,5,6,0}.
Let the value of arr be a multiple of 4 and stored in register s0.
What do the snippets of RISC-V code do?
Note that these snippits all run immediately after each other (snippet a) runs, then snippet b) and so on).

```
a)	lw t0, 12(s0)

b)	slli t1, t0, 2
	add t2, s0, t1
	lw t3, 0(t2)
	addi t3, t3, 1
	sw t3, 0(t2)

c)	lw t0, 0(s0)
	xori t0, t0, 0xFFF
	addi t0, t0, 1
```

```
a) 	load 4th element of the array [arr] (4) into the temp register t0.

b)	1. multiply register t0 value (4) by 4 = 16 store in the temp register t1.
	2. store sum of the temp register t1 (16) and saved register s0(base array address) into the temp register t2.
    		(location of the 5th element of the array [arr] into t2(t2 = &arr[4]))
	3. load word from memory address stored in temporary register t2 into temp register t3.
		(load 5th element of the array [arr] into t3(t3 = 5))
    	4. increment value stored in the temp register t3 by one.
		(increment 5 by one, store into t3(t3 = 5 + 1 = 6))
    	5. write value from temp register t3 to the memory at the address stored in temp register t2.
		(write t3(6) into memory at address t2(&arr[4]) (arr[5] = 6))

    	Increment 5th element of the array [arr] by one.

c)	1. load first element of the array [arr] in the temp register t0
		(t0 = 1)
	2. apply xor mask 0xFFF on the t0 register value (1)
		(t0 = 0000 0000 0001 ^ 1111 1111 1111; t0 = 1111 1111 1110) -2
	3. add one to the value of the temp register t0 store into t0
		(t0 = 1111 1111 1110 + 0000 0000 0001 = 1111 1111 1111)

	Load first element of the array [arr] (1) into t0, take it's two's complement, store in t0
```

### 2. What are the instructions to branch to label on each of the following conditions?
The only branch instructions you may use are beq and bne.

```
a) 	s0 < s1

	slt t0, s0, s1
	bne t0, x0, label

b)  	s0 <= s1

	slt t0, s1, s0
	beq t0, x0, label

c)  	s0 > 1

	# shitty naive solution
	slti t0, s0, 1
	bne t0, x0, skip
	addi t1, s0, -1
	beq t1, x0, skip
	j label
	skip:

	# smart solution
	sltiu t0, s0, 2
	beq t0, x0, label

```

## 4. Translating between C and RSIC-V

Translate between the C and RISC-V code. You may want to use the RISC-V Reference Card for more
information on the instruction set and syntax. In all of the C examples, we show you how the different variables
map to registers – you don’t have to worry about the stack or any memory-related issues. You may assume all
registers are initialized to zero

### 1

```
C:
	/*
	 * s0 -> a
	 * s1 -> b
	 * s2 -> c
	 * s3 -> z
	 */

	int a = 4, b = 5, c = 6, z;
	z = a + b + c + 10;

RISC-V:
	addi s0, x0, 4 # a = 4
	addi s1, x0, 5 # b = 5
	addi s2, x0, 6 # c = 6

	add s3, s0, s1
	add s3, s3, s2
	addi s3, s3, 10
```

### 2

```
C:
	/*
	 * s0 -> int *p = intArr;
	 * s1 -> a;
	 */

	*p = 0;
	int a = 2;
	p[1] = p[a] = a;

RISC-V:
	sw x0, 0(s0)	# p[0] = 0
	addi s1, x0, 2	# a = 2

	sw s1, 4(s0)	# p[1] = 2

	slli t0, s1, 2  # t0 = a * 4
	add t0, t0, s0  # t0 = &p[2]

	sw s1, 0(t0)	# p[2] = 2

```

### 3

```
C:
	/*
	 * s0 -> a
	 * s1 -> b
	 */

	int a = 5, b = 10;

	if(a + a == b)
		a = 0;
	else
		b = a - 1;

RISC-V:
		addi s0, x0, 5
		addi s1, x0, 6

		add t0, s0, s0
		bne t0, s1, f

		add s0, x0, x0
		j skip

	f:	addi s1, s0, -1

	skip:

```

### 4

```
RISC-V:
		addi s0, x0, 0
		addi s1, x0, 1
		addi t0, x0, 30

	loop: 	beq s0, t0, exit
		add s1, s1, s1
		addi s0, s0, 1
		jal x0, loop

	exit:

C:
	int a;
	int b = 1;
	int c = 30;

	for (a = 0; a != c; a++)
		b += b;

```

### 5

```
C:
	/*
	 * s0 -> n
	 * s1 -> sum
	 * assume n > 0 to start
	 */

	for(int sum = 0; n > 0; n--)
		sum += n;

RISC-V:
		add s1, x0, x0

	loop:	beq s0, x0, exit
		add s1, s1, s0
		addi s0, s0, -1
		j loop

	exit:

```