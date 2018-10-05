## Lab - 00

```
./lab-00.pdf
```

## Exercises

## Exercise 4: Binary Alphabet

Let's take 4-bit numbers. If we stack five 4-bit numbers on top of each other in binary, we can make patterns and pictures! To help visualize this, you can think of 0's and 1's as white and black instead. For example, what does the following bit pattern look like?

```

0 1 1 0 	□ ■ ■ □
1 0 0 1 	■ □ □ ■
1 1 1 1   -->   ■ ■ ■ ■
1 0 0 1 	■ □ □ ■
1 0 0 1 	■ □ □ ■
```

### What five decimal digits produce the pattern above? What five hexadecimal digits?

* dec - 6, 9, 15, 9, 9;
* hex - 0x6, 0x9, 0xF, 0x9, 0x9

### What letter is drawn with 1,1,9,9,6? 0xF8F88?

* J;
* F;


### What is the hexadecimal representation you would use to spell the letter 'B'? 'N' (you probably won't want to use 5 hex digits for this one)?

* 0xE9E9E
* 0x9DB9

## Exercise 5: 1,000 $1 Bills

I hand you a thousand $1 bills and ten envelopes. Your job is to find a way to put various numbers of dollar bills in those ten envelopes so that no matter what amount of money I ask you for (between $1-1000), you can simply hand me some combination of envelopes and always be assured of giving me the correct amount of cash.


```
2^10 - 1 = 1023

	| 512 | 256 | 128 | 64  | 32  | 16  | 8   | 4   | 2   | 1   |
        |     |     |     |     |     |     |     |     |     |     |
        |     |     |     |     |     |     |     |     |     |     |
	| 2^9 | 2^8 | 2^7 | 2^6 | 2^5 | 2^4 | 2^3 | 2^2 | 2^1 | 2^0 |
	|     |     |     |     |     |     |     |     |     |     |
	|     |     |     |     |     |     |     |     |     |     |
1023    | 1   |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |
        |     |     |     |     |     |     |     |     |     |     |
        |     |     |     |     |     |     |     |     |     |     |
 666    | 1   |  0  |  1  |  0  |  0  |  1  |  1  |  0  |  1  |  0  |
        |     |     |     |     |     |     |     |     |     |     |

alternative solution 2^9 - 1 between first 9 buckets, 10th bucket contains 1000 - (2^9 - 1)$
-> spread 511$ between (1-9buckets) - 1-256$
   489$ in the 10th
```