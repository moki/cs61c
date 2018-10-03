## Section 00

Number Representation


```
./section-00.pdf
```

## 1 Unsigned Integers

### 1.1.1 Convert the following numbers from their initial radix into the other two common radices

```
(a) 0b10010011 -decimal-> 147
	       -hex-> 0x93

(b) 0xD3AD     -decimal-> 54189
	       -binary-> 1101 0011 1010 1101

(c) 63	       -binary-> 0011 1111
	       -hex-> 0x3F

(d) 0b00100100 -decimal-> 36
	       -hex-> 0x24

(e) 0xB33F     -decimal-> 45887
	       -binary-> 1011 0011 0011 1111

(g) 39	       -binary-> 0010 0111
	       -hex-> 0x27

(h) 0x7EC4     -decimal-> 32452
	       -binary-> 0111 1110 1100 0100

(i) 437        -binary-> 0001 1011 0101
	       -hex-> 0x1B5

```

## 2 Signed Integers

### 2.1 Two's compliment

MSB has a negative value, all others are positive.

Assume 8-bit integers, answer for cases unsigned integers, biased bias -127, two's compliment.

### 2.2.1 What is the largest integer? The largest integer’s representation + 1?

* (a) [Unsigned]	 255, 0
* (b) [Biased]		 128, -127
* (c) [Two’s Complement] 127, -128

### 2.2.2 How do you represent the numbers 0, 1, and -1?

* (a) [Unsigned]	 0000 0000, 0000 0001, -
* (b) [Biased]		 0111 1111, 1000 0000, 0111 1110
* (c) [Two’s Complement] 0000 0000, 0000 0001, 1111 1111

### 2.2.3 How do you represent 17, -17?

* (a) [Unsigned]	 0001 0001, -
* (b) [Biased]		 1001 0000, 0110 1110
* (c) [Two’s Complement] 0001 0001, 1110 1111

### 2.2.6 Explain where each of the three radices shines and why it is preferred over other bases in a given context.

* binary  - computers
* decimal - humans
* hex	  - shorthand for binary, inbetween

## 3 Counting

Bitstrings can be used to represent anything inside the computer n bits can be used to represent 2^n distinct things

### 3.1.1 How many bits do we need to represent a variable that can only take on the values 0, π or e?

```
2
```

### 3.1.3 If the only value a variable can take on is e, how many bits are needed to represent it?

```
0
```