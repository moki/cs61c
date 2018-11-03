## Section 04

RISC-V Addressing, Inst. Formats, and CALL

```
./section-04.pdf
```

## 1. RISC-V Addressing

### 1.1 Overview

We have several addressing modes to access memory (immediate not listed):

1. Base displacement addressing: Adds an immediate to a register value to create a memory address
(used for lw, lb, sw, sb)

2. PC-relative addressing: Uses the PC and adds the immediate value of the instruction (multiplied
by 2) to create an address (used by branch and jump instructions)

3. Register Addressing: Uses the value in a register as a memory address (jr)

### 1.2 Exercises

1. What is range of 32-bit instructions that can be reached from the current PC using a branch instruction?

```
-2^11 to 2^11 - 1 / 2 (2 bytes, but instructions are 4 bytes)

PC + [-2^10, 2^10 - 1]
```

2. What is the range of 32-bit instructions that can be reached from the current PC using a jump instruction?

```
-2^19 to 2^19 - 1 / 2 (2 bytes, but instructions are 4 bytes)


PC + [-2^18, 2^18 - 1]
```

3. Given the following RISC-V code (and instruction addresses), fill in the blank fields for the following
instructions (you’ll need your RISC-V green card!).

```
0x002cff00: loop: add t1, t2, t0 |_0000000|___00101|___00111|_____000|___00110|__0x33__|
0x002cff04: jal   ra, foo 	 |_____________0x14|_____________________00001|__0x6F__|
0x002cff08: bne   t1, zero, loop |_1111111|___00000|___00110|_____001|___11001|__0x63__|
...
0x002cff2c: foo: jr ra ra=0x002cff08
```

## 2. Powerful RISC-V Functions

1. Write a function double in RISC-V that, when given an integer x, returns 2x.

```
double: add  a0, a0, a0

	jr ra
```

2. Write a function power in RISC-V that takes in two numbers x and n, and returns x^n. You may assume
that n ≥ 0 and that multiplication will always result in a 32-bit number.

```
power:	beq  a1, x0, r-0
	addi t1, x0, 1
	add  t0, x0, x0

loop:	beq  t0, a1, return
	mul  t1, t1, a0

	addi t0, t0, 1
	j    loop

return: add  a0, t1, x0
	jr   ra

r-0:	addi a0, x0, 1
```

## 3. Compile, Assemble, Link, Load, and Go!

### 3.1 Overview

### 3.2 Exercises

a. What is the Stored Program concept and what does it enable us to do?

```
Code of the program stored in memory, so one doesn't have to rebuild computer
from scratch everytime it needs to solve different problem.
```

b. How many passes through the code does the Assembler have to make? Why?

```
Two, 1 to find labels, 2 to resolve forward references
```

c. What are the different parts of the object files output by the Assembler?

```
header - size and pos of otherr pieces of object file

text - machine code

data - binary rep of static data in the source

reloc table - lines of code to be fixed later

sym table - list of this file labels and static data that can be referenced

debug info - info for debuggers

```
d. Which step in CALL resolves relative addressing? Absolute addressing?

```
relative - assembler
absolute - linker
```

e. What does RISC stand for? How is this related to pseudoinstructions?

```
restricted instruction set computer

pseudos - not much of the makes life easier converted to normal ones by the assembler
```

## 4. Writing RISC-V Functions

Write a function sumSquare in RISC-V that, when given an integer n, returns the summation below. If n is
not positive, then the function returns 0.

```
n^2 + (n − 1)^2 + (n − 2)^2 + . . . + 1^2
```

For this problem, you are given a RISC-V function called square that takes in an integer and returns its square.
Implement sumSquare using square as a subroutine.

```
sumsqr: addi sp, sp, -12
	sw   ra, 8(sp)
	sw   s0, 4(sp)
	sw   s1, 0(sp)

	add  s0, a0, x0
	add  s1, x0, x0

loop:	beq  s0, x0, return

	add  a0, s0, x0
	jal  ra, square
	add  s1, s1, a0

	addi s0, s0, -1
	j    loop

return	add  a0, s1, x0

	lw   ra, 8(sp)
	lw   s0, 4(sp)
	lw   s1, 0(sp)

	jr   ra

```