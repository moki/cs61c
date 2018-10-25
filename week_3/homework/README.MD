## Homework 01

C to RISC-V Practice Problems

```
./homework-01.pdf
```

## Problem 1 - Useful Snippets

In this section, we’ll take the same problem (that of printing a string) and approach it using different C
constructs.

This should allow you to see how various C constructs are translated into RISC-V.

Suppose that we have a print function, but that this function only takes one character and prints it to
the screen.

It expects the character to be in the lower 8 bits of a0.

### A Translate into RISC-V, while preserving the while loop structure

```
C:
	void string_print(char *print_me) {
		while (*print_me != ’\0’) {
			print(*print_me);
			print_me++;
		}
	}

RISC-V:
	string_print:	addi sp, sp, -8
			sw   ra, 4(sp)
			sw   s0, 0(sp)

			add  s0, a0, x0

			lbu  a0, 0(s0)

	loop:		beq  a0, x0, return
			jal  print

			addi s0, s0, 1
			lbu  a0, 0(s0)

			j loop

	return:		lw   s0, 0(sp)
			lw   ra, 4(sp)
			addi sp, sp, 8
			jr   ra
```

### B Translate into RISC-V, while preserving the for loop structure (your function is given the string length)

```
C:
	void string_print(char *print_me, int slen) {
		for (int i = 0; i < slen; i++) {
			print(*(print_me+i));
		}
	}

RISC-V:
	string_print:	addi sp, sp, -16
			sw   ra, 12(sp)
			sw   s0, 8(sp)
			sw   s1, 4(sp)
			sw   s2, 0(sp)

			add  s0, a0, x0
			add  s1, s1, x0
			add  s2, x0, x0

			lbu  a0, 0(s0)

	loop:		beq  s2, s1, return

			add  a0, s0, s2
			lbu  a0, 0(a0)

			jal  print

			addi s2, s2, 1

			j loop

	return:		lw   s2, 0(sp)
			lw   s1, 4(sp)
			lw   s0, 8(sp)
			lw   ra, 12(sp)
			addi sp, sp, 16
			jr   ra
```

### C Translate into RISC-V, while preserving the do while loop structure:

```
C:
	void string_print(char *print_me) {
		if (!(*print_me))
			return;

		do {
			print(*print_me);
			print_me++;
		} while (*print_me);
	}

RISC-V:
	string_print:	addi sp, sp, -8
			sw   ra, 4(sp)
			sw   s0, 0(sp)

			add  s0, a0, x0
			lbu  a0, 0(sp)
			beq  a0, x0, return

	loop:		jal  print

			addi  s0, s0, 1
			lbu  a0, 0(s0)

			bne a0, x0, loop

	return:		lw   s0, 0(sp)
			lw   ra, 4(sp)
			addi sp, sp, 8
			jr   ra
```

## Problem 2 - Recursive Fibonacci

Convert the following recursive implementation of Fibonacci to MIPS. Do not convert it to an iterative
solution

```
C:
	int fib(int n) {
		if (n == 0) {
			return 0;
		else if (n == 1)
			return 1;

		return fib(n-1) + fib(n-2);
	}

RISC-V:
	fib:	addi sp, -12
		sw   ra, 8(sp)
		sw   a0, 4(sp)
		sw   s0, 0(sp)

		beq  a0, x0, r0
		addi t0, a0, -1
		beq  t0, x0, r1

		addi a0, a0, -1
		jal  fib
		add  s0, a0, x0

		lw   a0, 4(sp)
		addi a0, a0, -2
		jal  fib

		add  a0, a0, s0

		lw   ra, 8(sp)
		lw   s0, 0(sp)
		addi sp, sp, 12

		jr ra

	r0:	lw   ra, 8(sp)
		lw   s0, 0(sp)
		addi sp, sp, 12

		add  a0, x0, x0

		jr   ra

	r1:	lw   ra, 8(sp)
		lw   s0, 0(sp)
		addi sp, sp, 12

		addi a0, x0, 1

		jr   ra
```