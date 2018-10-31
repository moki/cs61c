## Section 03

RISC-V II Instruction Formats

```
./section-03.pdf
```

## 1. RISC-V with Arrays and Lists

Comment each snippet with what the snippet does. Assume that there is an array,

int arr[6] = {3, 1, 4, 1, 5, 9}, which is starts at memory address 0xBFFFFF00,

and a linked list struct (as defined below), struct ll* lst;, whose first element is located at address 0xABCD0000.

s0 then contains arr’s address, 0xBFFFFF00,

and s1 contains lst’s address, 0xABCD0000.

You may assume integers and pointers are 4 bytes and that structs
are tightly packed

```
struct ll {
	int val;
	struct ll* next;
}

1.

	lw t0, 0(s0) 	# load first element(3) of the array [arr] into temp reg t0
	lw t1, 8(s0)	# load third element(4) of the array [arr] into temp reg t1
	add t2, t0, t1	# store sum of the 3 and 4 (7) into temp reg t2
	sw t2, 4(s0)	# store temp reg 2 contents(7) as a second element of the array [arr]

	saves sum of the first and third element of the array as a second element of the array

2.

loop: 	beq s1, x0, end	# exit loop if s1 contains address(points) (to) x0 (null)
	lw t0, 0(s1)	# load first value [val] of the linked list node s1 currently points to
	addi t0, t0, 1	# increment value [val] by one store result into temp reg t0
	sw t0, 0(s1)	# store incremented value in the linked list node's field [val]
	lw s1, 4(s1)	# load pointer to the next linked list node in the s1 reg (update cursor)
	jal x0, loop	# jump to the start of the loop
end:

	increments every node's value [val] in the linked list by one.

3.

	add t0, x0, x0	# initialize temp reg t0 as zero
loop: 	slti t1, t0, 6	# set temp reg t1(flag) to one if temp reg t0 value is less than 6
	beq t1, x0, end	# if temp reg t1(flag) is zero(false) jump to end(exit loop)
	slli t2, t0, 2	# shift left logical temp reg t0 value by two(multiply by 4)
	add t3, s0, t2	# add temp reg t2 value(counter) to the address s0(linked list pointer) store
			# into temp reg t3 (store address to the next linked list node)
	lw t4, 0(t3)	# load into temp reg t4 word at the t3 address(next linked list node)
	sub t4, x0, t4	# subtract above linked list node's value [val] from zero store into temp reg t4
	sw t4, 0(t3)	# store negated value of the linked list node into it's [val] field
	addi t0, t0, 1	# add 1 to the temp reg t0(increment counter by one)
	jal x0, loop	# jump to the start of the loop
end:

	iterates over 6 linked list nodes and negates its field [val]

```

## 2. RISC-V Instruction Formats

### 2.1 Overview

Instructions in RISC-V can be turned into binary numbers that the machine actually reads. There are different
formats to the instructions, based on what information is need.

```
R-TYPE	funct7	rs2	rs1	funct3	rd	opcode
Bits	7	5	5	3	5	7

I-TYPE	imm[11:0]	rs1	funct3	rd	opcode
Bits	12		5	3	5	7

S-TYPE	imm[11:5]	rs2	rs1	funct3	imm[4:0]	opcode
Bits	7		5	5	3	5		7

SB-TYPE	imm[12]	imm[10:5]	rs2	rs1	funct3	imm[4:1]	imm[11]	opcode
Bits	1	6		5	5	3	4		1	7

U-TYPE	imm[31:12]	rd	opcode
Bits	20		5	7

UJ-TYPE	imm[20]	imm[10:1]	imm[11]	imm[19:12]	rd	opcode
Bits	1	10		1	8		5	7
```
Each of the fields above is filled in with binary that represents the information. Each of the registers takes a 5 bit number that is the numeric name of the
register (i.e. zero = 0, ra = 1, s1 = 9). See your reference card to know which register corresponds to which
number.
I type instructions fill the immediate into the code. These numbers are signed 12 bit numbers.

### 2.2 Exercises

1. Expand addi s0 t0 -1

```
imm[11:0]    rs1   f3  rd    opcode
111111111111 00101 000 01000 0010011

```

2. Expand lw s4 5(sp)

```
s4-x20
sp-x2

lw
imm[11:0]    rs1   f3  rd    opcode
000000000101 00010 010 10100 0000011

```

3. Write the format name of the following instructions:

```
(a) jal	 UJ
(b) lw	 I
(c) beq	 SB
(d) add  R
(e) jalr I
(f) sb   S
(g) lui  U
```

## 3. Translating between C and RISC-V

Translate between the C and RISC-V code. You may want to use the RISC-V Green Card as a reference.
We show you how the different variables map to registers – you don’t have to worry about the stack or any
memory-related issues.

```

C:
	// Nth_Fibonacci(n):
	// s0 -> n, s1 -> fib
	// t0 -> i, t1 -> j
	// Assume fib, i, j are already these values

	int fib = 1;
	int i 	= 1;
	int j 	= 1;

	if (n==0)
		return 0;
	if (n==1)
		return 1;

	n -= 2;

	while (n != 0) {
		fib = i + j;

		j = i;
		i = fib;

		n--;
	}

	return fib;

RISC-V:

	fib:	beq  s0, x0, r0
		addi s0, s0, -1
		beq  a0, x0, r1

		addi a0, a0, -1

	loop	beq  s0, x0, exit
		add  s1, t0, t1

		add  t1, x0, t0
		add  t0, x0, s1

		addi s0, s0, -1

		j    loop

	r0:
		add  a0, x0, x0
		ret
	r1:
		addi a0, x0, 1
		ret

	exit: 	a0, x0, s1
	ret
```

## 4. RISC-V Calling Conventions

1. How do we pass arguments into functions?

```
8 argument registers a0-a7
```

2. How are values returned by functions?

```
2 return values registers a0-a1
```

3. What is sp and how should it be used in the context of RISC-V functions?

```
sp is the stack pointer, growing when calling functions by subtracting from pointer
and shrinking upon function exit by adding to it, usually used to persist contents of the saved registers after function execution
```

4. Which values need to saved before using jal?

```
rd, temporary registers t0-t6, fn args/return values a0-a7
```

5. Which values need to be restored before using jalr to return from a function?

```
registers which values persisted to stack s0-s11, sp.
```
