## Lab 04

Data Locality and Caches!

```
./lab-07.pdf
```

## Exercise 2: Loop Ordering and Matrix Multiplication

```
cd exercise_02
make test
```

Which ordering(s) perform best for these 1000-by-1000 matrices? Why?

```
jki
	j is the largest stride producing the biggest spread
	because of it being in the j * n expression
	=> so it better be most outer loop
```

Which ordering(s) perform the worst? Why?

```
ikj
kij
	anything with j as the most inner loop
	j is the largest stride producing the biggest spread
	because of it being in the j * n expression
```

## Exercise 3: Cache Blocking and Maxtrix Transposition

```
cd exercise_03
make test
```

### Part 1: Changing Array Sizes

Fix the blocksize to be 20, and run your code with n equal to 100, 1000, 2000, 5000, and 10000. At what point does cache blocked version of transpose become faster than the non-cache blocked version? Why does cache blocking require the matrix to be a certain size before it outperforms the non-cache blocked code?

```
at 2000x2000 dimension blocking version starting to outperform naive

```

### Part 2: Changing Blocksize

Fix n to be 10000, and run your code with blocksize equal to 50, 100, 500, 1000, 5000. How does performance change as the blocksize increases? Why is this the case?

```
performance increasing up to the point of the 500 cache size, and falls afterwards

```