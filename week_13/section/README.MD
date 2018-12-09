## Section 12

Spark and WSC

```
./section-12.pdf
```

## 1. Warehouse Scale Computing

### 1.1 Amdahl’s Law

```
1) You are going to train an image classifier on a training set of 50,000 images using a WSC of more than
50,000 servers. You notice that 99% of the execution can be parallelized. What is the speedup?

	1		1
________________  =  _______ = 1
	.99 	        .01
( .01 + ____ )
        50000

100%

```

### 1.2 Failure in a WSC

```
1) In this example, a WSC has 55,000 servers, and each server has four disks whose annual failure rate is
4%. How many disks will fail per hour?

(55000 * 4 * .04) / (365 * 24) = 1.00456621005

2) What is the availability of the system if it does not tolerate the failure? Assume that the time to repair a
disk is 30 minutes.s

1 / (1 + .5) = 2/3 = 66.6%

```

## 2. Map Reduce

```
Use pseudocode to write MapReduce functions necessary to solve the problems below. Also, make sure to
fill out the correct data types. Some tips:

• The input to each MapReduce job is given by the signature of the map() function.
• The function emit(key k, value v) outputs the key-value pair (k, v).
• The for(var in list) syntax can be used to iterate through Iterables or you can call the
hasNext() and next() functions.
• Usable data types: int, float, String. You may also use lists and custom data types composed of
the aforementioned types.
• The method intersection(list1, list2) returns a list that is the intersection of list1 and list2.

```

### 2.1

```
1. Given the student’s name and the course taken, output each student’s name and total GPA.

Declare any custom data types here:

CourseData:
 	int courseID
	float studentGrade // a number from 0-4


map(String student, CourseData value):
	emit(student, value.studentGrade)

reduce( String key, Iterable< float > values):
	points;
	classes;

	points = classes = 0;

	for (grade in grades)
		points += grade;
		++classes;

	emit(key, points / classes)

_

2. Given a person’s unique int ID and a list of the IDs of their friends, compute the list of mutual friends
between each pair of friends in a social network.

Declare any custom data types here:

FriendPair:
	int friendOne
	int friendTwo

map(int personID, list<int> friendIDs):
	for friendID in friendIDs
		emit(FriendPair(personID, friendID), friendIDs)

reduce( FriendPair key, Iterable< list<int> > values):
	emit(key, intersection(values.next(), values.next()))

_

3. a) Given a set of coins and each coin’s owner, compute the number of coins of each denomination that a
person has.

Declare any custom data types here:

CoinPair:
	String person
	String coinType

map(String person, String coinType):
	emit(CoinPair(person, coinType), 1)

reduce(CoinPair key, Iterable< int > values):
	n = 0;

	for (value in values)
		n += value

	emit(key, n)

b) Using the output of the first MapReduce, compute the amount of money each person has. The function
valueOfCoin(String coinType) returns a float corresponding to the dollar value of the coin.

map(CoinPair key, int amount):
	emit(key.person, valueOfCoin(key.coinType) * amount)

reduce(String key, Iterable< float > values):
	acc = 0;

	for (value in values)
		acc += value

	emit(key, acc)
```
