## Section 14

Parity, ECC, RAID

```
./section-14.pdf
```

## 1. Hamming ECC

### 1.1 How many bits do we need to add to 0011 to allow single error correction?

```
3

floor(log2(n_bits)) + 1
```

### 1.2 Which locations in 0011 would parity bits be included?

```
p1 p2 0 p4 0 1 1
1  2  3 4  5 6 7
```

### 1.3 Which bits does each parity bit cover in 0011?

```
1 2 3 4 5 6 7
p p 0 p 0 1 1

p1 - 1, 3, 5, 7
   -    0, 0, 1

p2 - 2, 3, 6, 7
   -    0, 1, 1

p4 - 4, 5, 6, 7
   -    0, 1, 1
```

### 1.4 Write the completed coded representation for 0011 to enable single error correction.

```
1 2 3 4 5 6 7
p p d p d d d
1 2 1 4 2 3 4

1 0 0 0 0 1 1
	      2
```

### 1.5 How can we enable an additional double error detection on top of this?

```
add additional parity bit over the whole seq.
```

### 1.6 Find the original bits given the following SEC Hamming Code: 0110111

```
1 2 3 4 5 6 7
0 1 1 0 1 1 1
p p d p d d d
1 2 1 4 2 3 4

p1 - bit = 0; seq = 1; error

p2 - bit = 1; seq = 1; match

p4 - bit = 0; seq = 1; error

1 + 4 = 5;

flip 5th to fix error
1 2 3 4 5 6 7
0 1 1 0 0 1 1	=>

1 0 1 1
	2
```

### 1.7 Find the original bits given the following SEC Hamming Code: 1001000

```
1 2 3 4 5 6 7
1 0 0 1 0 0 0
p p d p d d d
1 2 1 4 2 3 4

p1 - bit = 1; seq = 0; error

p2 - bit = 0; seq = 0; match

p4 - bit = 1; seq = 0; error

1 + 4 = 5;

flip 5th to fix error
1 2 3 4 5 6 7
1 0 0 1 1 0 0	=>

0 1 0 0
	2
```

## 2. RAID

```
		Configuration 			Pro 				Con

RAID 0		striping of data		simple storage			no redundancy
		across disks			management

RAID 1		traditional mirroring		easy cope with failures		amount of disks
		every data write also		by going to the mirror		expensive
		goes to backup disk
RAID 4
		independent read/write,		small reads			blocking write
		error detection within

RAID 5
		parity spread across the disks	multiple writes simultaneously
						as long as parity bits not
						located at the same disks

```