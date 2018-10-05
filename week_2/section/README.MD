## Section 01

Programming in C

```
./section-01.pdf
```

## 2 C Uncommented Code? Yuck!

The following functions work correctly (note: this does not mean intelligently), but have no comments.

Document the code to prevent it from causing further confusion.

### 2.1

```
/* foo - calculates acc. sum of the array elements
 * @int *a   - array of ints
 * @size_t n - number of elements in the array
 * recursive function that calculates acc sum of the elements
 * and returns it, if n > 0, 0 otherwise.
 */

 int foo(int *a, size_t n) {
   return n ? a[0] + foo(a + 1, n - 1) : 0;
 }
```

### 2.2

```
/* bar - calculates number of zero elements
 * @int *a   - array of ints
 * @size_t n - number of elements in the array
 * recursive function that calculates acc sum of the elements
 * and returns it, if n > 0, 0 otherwise.
 */

 int bar(int *a, size_t n) {
   int sum = 0, i;

   for (i = n; i > 0; i--) {
	sum += !a[i - 1];
   }

   return sum;
 }
```

### 2.3

```
/* baz - swaps two variables x and y in place, in fn's scope.
 * @int x - int value x
 * @int y - int value y
 * fn that swaps two variables in place using bitwise XOR swap algorithm,
 * changes never propagates to outer scope.
 */

 void baz(int x, int y) {
   x = x ^ y;
   y = x ^ y;
   x = x ^ y;
 }
```

## 3 Programming with Pointers

Implement the following functions so that they perform as described in the comments.

### 3.1

```
/* Swaps the value of two ints outside of this function. */
static void swap(int *x, int *y) {
  if (x == y) return;

  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}
```

### 3.2

```
/* Returns the number of characters in a string. Does not use strlen. */
static size_t mystrlen(char *s) {
  char *p = s;

  while (*p++);

  return p - s - 1;
}
```

## 4 Problem?

The following code segments may contain logic and syntax errors. Find and correct them.

### 4.1

```
/* Returns the sum of all the elements in SUMMANDS. */
static int sum(int* summands, size_t n) {
  int sum = 0;
  int i = 0;

  while (i < n)
    sum += summands[i++];

  return sum;
}
```

### 4.2

```
/* Increments all the letters in the string STRING, held in an array of length N.
 * Does not modify any other memory which has been previously allocated.
 */
static void increment(char* string, int n) {
  int i = 0;

  while (i < n && *(string + i))
    (*(string + i++))++;
}
```

### 4.3

```
/* Overwrites an inputted string with "61C is awesome!" if there’s room.
 * Does nothing if there is not. Assume that dst_len correctly represents
 * the length of dst.
 */
static void CS61C(char* dst, size_t dst_len) {
  char *src = "61C is awesome!";

  if (dst_len < 15)
    return;

  while (*dst++ = *src++);

  *dst = '\0';
}

/*
 * by overwriting the pointer
 */
static void _CS61C(char** src, size_t srcLength) {
  if (srcLength < 15)
    return;

  *src = "61C is awesome!";
}
```
