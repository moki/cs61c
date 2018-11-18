## Section 08

Caches

```
./section-08.pdf
```

## 1. Tag Index Offset

When working with caches, we have to be able to break down the memory addresses we work with to understand
where they fit into our caches. There are three fields:

## 2. Direct mapped Cache

1. Let’s say we have a 8192KiB cache with an 128B block size, how many bits are in tag, index, and offset?
What parts of the address of 0xFEEDF00D fit into which sections?

```
		|      Tag	|	Index		|	Offset		|
Number of bits	|	9	|  	  16		|	   7		|
Bits of address |  1 1111 1101	|  1101 1011 1110 0000	|      000 1101		|	binary
		|     0x1FD	| 	0xDBE0		|	  0xOD		|	hex
```

2. Now fill in the table below. Assume that we have a write-through cache, so the number of bits per row
includes only the cache data, the tag, and the valid bit.

```
Address size (bits) | Cache Size | Block Size | Tag Bits | Index Bits | Offset Bits | Bits per row |
	16	    |     4KiB	 |      4B    |     4    |     10     |       2     |       37     |
	32	    |    32KiB	 |     16B    |    17    |     11     |       4     |      146     |
	32	    |    64KiB	 |     16B    |    16    |     12     |       4     |      145     |
	64	    |  2048KiB	 |    128B    |    43    |     14     |       7     |     1068     |
```

## 3. Cache Hits and Misses

### 3.1 Finding Hits and Misses

Assume we have a direct-mapped byte-addressed cache with capacity 32B and block size of 8B.
Of the 32 bits in each address, which bits do we use to find the index of the cache to use?
Classify each of the following byte memory accesses as a cache hit (H), cache miss (M), or cache miss with replacement(R).
It is probably best to try drawing out the cache before going through so that you can have an
easier time seeing the replacements in the cache. The following white space is to do this:

```
1. 0x00000004 - M compulsory
2. 0x00000005 - H
3. 0x00000068 - M compulsory
4. 0x000000C8 - R
5. 0x00000068 - R
6. 0x000000DD - M compulsory
7. 0x00000045 - R
8. 0x00000004 - R
9. 0x000000C8 - R
```

# 4. N-Way Set Associative Caches

1. Assuming 32 bits of physical memory, for an 8-way set associative 4KiB cache with 16B blocks, how big
are the T, I, and O fields?

```
T - 32 - 5 - 4 = 23
I - log2 32 = 5
O - log2 16 = 4
```
