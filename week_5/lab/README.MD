## Lab 03

RISC-V

```
./lab-03.pdf
```

## Exercise 1: Familiarizing yourself with Venus

1. What do the .data, .word, .text directives mean (i.e. what do you use them for)? Hint: think about the 4 sections of memory.

```
.data - source file static data

.word - 4 byte data chunks starting at 0x10000000

.text - source code loaded in memory
```

2. Run the program to completion. What number did the program output? What does this number represent?

```
34

fib(9)
```

3. At what address is n stored in memory? Hint: Look at the contents of the registers.

```
0x10000010
```

4.Without using the "Edit" tab, have the program calculate the 13th fib number (0-indexed) by manually modifying the value of a register. You may find it helpful to first step through the code. If you prefer to look at decimal values, change the "Display Settings" option at the bottom.

```
1. step through program untill beq x28, x0 24 line
2. change register x28(t3) to the 0x0000000d(13)
3. run to completion

fib(13) = 233
```

## Exercise 2: Translating from C to RISC-V

1.The register representing the variable k.

```
t0
```

2. The registers acting as pointers to the source and dest arrays.

```
t1 - source
t2 - dest
```

3. The assembly code for the loop found in the C code.

```
loop:
    slli t3, t0, 2
    add t4, t1, t3
    lw t5, 0(t4)
    beq t5, x0, exit
    add t6, t2, t3
    sw t5, 0(t6)
    addi t0, t0, 1
    jal x0, loop
```

4. How the pointers are manipulated in the assembly code.

```
counter multiplied by chunk width
added to base address of the pointer
data from that address loaded into register

```

## Exercise 3: Factorial

```
factorial.s
```

## Exercise 4: RISC-V function calling with map

```
list_map.s
```
