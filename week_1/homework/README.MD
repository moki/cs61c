## homework 00

```
./homework-00.pdf
```

## Problem 1: Number representation

Assume we are dealing with 8 bit numbers for this problem. Complete the following tables to practice encoding decimal values into unsigned and two's complement. The first table is unsigned and the second table is two's complement. The first row of each column has been filled out for you.

### UNSIGNED

```
Decimal |      Binary      | Hexadecimal|
========================================
   10   |   0b 0000 1010   |    0x0A    |
  240   |   0b 1111 0000   |    0xF0    |
   15   |   0b 0000 1111   |    0x0F    |
  161   |   0b 1010 0001   |    0xA1    |
  250   |   0b 1111 1010   |    0xFA    |
  255   |   0b 1111 1111   |    0xFF    |
  204   |   0b 1100 1100   |    0xCC    |
  -35   |        -         |     -      |
  128   |   0b 1000 0000   |    0x80    |
  105   |   0b 0110 1001   |    0x69    |
```

### TWO'S COMPLEMENT

```
Decimal |      Binary      | Hexadecimal|
========================================
  -10   |   0b 1111 0110   |    0xF6    |
  -16   |   0b 1111 0000   |    0xF0    |
   15   |   0b 0000 1111   |    0x0F    |
  -95   |   0b 1010 0001   |    0xA1    |
  250   |        -         |     -      |
   -1   |   0b 1111 1111   |    0xFF    |
  -52   |   0b 1100 1100   |    0xCC    |
  -35   |   0b 1101 1101   |    0xDD    |
  128   |        -         |     -      |
  105   |   0b 0110 1001   |    0x69    |
```

## Problem 2: Picking representations

Assume we are working with 8-bit numbers for the entirety of this question.

1. You would like to represent the temperature in degrees Celsius:

```
two's compliment (negative numbers)
```

2. You would like to maximize the range (distance between most negative represented number, and most positive represented number):

```
two's compliment (negative numbers)
```

3. You would like to represent the number of boxes a factory has shipped:

```
unsigned (only positive numbers)
```


## Problem 3: Counting

1. For a system of n-digit unsigned base 4 numbers (n > 1), how many numbers can be represented?

```
4^n - 1
```

2. For an n-digit 2's complement binary number (n > 1), what is the number of negative integers?

```
2^(n-1)
```

3. For an n-digit 2's complement number (n > 1), how many zeros are there?

```
1
```

4. For an n-digit 2's complement number (n > 1), what is the difference between the most positive number and the most negative number?

```
(base^n) - 1
```

## Problem 4: Overflow

The following addition and subtraction operations are to be carried out with 8-bit 2's complement numbers. For each operation, calculate the result and label as OVERFLOW or CORRECT

1. 64 + 64 -128

```
 01

  0100 0000
+ 0100 0000
 -----------
  1000 0000

  -128

  overflow
```

2. -127 + 30 = -97

```
  1000 0001
+ 0001 1110
 -----------
  1001 1111

  -97

  correct
```

3. -127 - 1 = -128

```
 11111 111
  1000 0001
+ 1111 1111
 -----------
  1000 0000

  -128

  correct
```

4. 38 - 40 = -2

```
  0010 0110
+ 1101 1000
 -----------
  1111 1110

  -2

  correct
```

