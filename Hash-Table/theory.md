## What is Hashing?

Hashing is a technique that lets you find data very quickly by converting a key into an index.
Hashing refers to the process of generating a small sized output (that can be used as index in a table) from an input of typically large and variable size. Hashing uses mathematical formulas known as hash functions to do the transformation. This technique determines an index or location for the storage of an item in a data structure called Hash Table.

## Summary of Trade-offs

* Linear Search: Zero overhead, works on any unsorted sequence, best for tiny inputs.

* Binary Search: Optimal when data is already sorted, space-efficient, supports range and order queries.

* Hashing: Fastest average-case lookup ($\mathcal{O}(1)$), ideal for exact match lookups (dictionaries, databases, caches), but uses more memory and loses ordering.

## Hash Table Data Structure Overview

It is one of the most widely used data structure after arrays.
It mainly supports search, insert and delete in O(1) time on average which is more efficient than other popular data structures like arrays, Linked List and Self Balancing BST.
We use hashing for dictionaries, frequency counting, maintaining data for quick access by key, etc.
Real World Applications include Database Indexing, Cryptography, Caches, Symbol Table and Dictionaries.
There are mainly two forms of hash typically implemented in programming languages.
Hash Set : Collection of unique keys (Implemented as Set in Python, Set in JavaScrtipt, unordered_set in C++ and HashSet in Java.
Hash Map : Collection of key value pairs with keys being unique (Implemented as dictionary in Python, Map in JavaScript, unordered_map in C++ and HashMap in Java)

## Components of Hashing

There are majorly three components of hashing:

* Key: A Key can be anything string or integer which is fed as input in the hash function the technique that determines an index or location for storage of an item in a data structure.

* Hash Function: Receives the input key and returns the index of an element in an array called a hash table. The index is known as the hash index .

* Hash Table: Hash table is typically an array of lists. It stores values corresponding to the keys. Hash stores the data in an associative manner in an array where each data value has its own unique index.

Imagine you have:

Array:
index:  0   1   2   3   4
value:  -   -   -   -   -

Suppose you want to store:

25

We can create a simple hash function:

index = key % 5;

So:

25 % 5 = 0

Therefore, store 25 at index 0:

index:  0   1   2   3   4
value: 25   -   -   -   -

Now searching for 25:

index = 25 % 5;

We immediately get:

index = 0

So we don't need to search through the array.

That's the main idea of hashing:

Key → Hash function → Index → Data

Why is hashing so fast?

Compare the three:

**Linear Search**

10  25  7  80  15  42  9
 ↑   ↑   ↑   ↑   ↑
check one by one

Worst case:

O(n)

**Binary Search**

Requires sorted data:

7  9  10  15  25  42  80
         ↑
       middle

Time:

O(log n)


**Hashing**

25 → hash function → index 0

Average:

O(1) ⭐

That's why hash tables are extremely useful.

But there's a problem... 

What happens if we have:

25 % 5 = 0

and

10 % 5 = 0

Both want index 0.

This is called a collision.

25 ──┐
     ├──→ index 0
10 ──┘

And handling collisions is one of the most important parts of learning hashing.

There are two major approaches:

Separate Chaining
Open Addressing
Linear Probing
Quadratic Probing
Double Hashing

### Recommended: learning hashing in this order

1. Hashing concept
       ↓
2. Hash function
       ↓
3. Collision
       ↓
4. Separate Chaining
       ↓
5. Open Addressing
       ↓
6. Linear Probing
       ↓
7. C++ unordered_map / unordered_set
       ↓
8. Time & Space Complexity
       ↓
9. Real-world applications

Since you're learning DSA implementation, I'd suggest we learn it from scratch in C++ first, without using unordered_map. Then we'll see how C++ implements hashing for you.

For interviews, it helps to separate hashing into two levels:

How we calculate the hash value → hash-function techniques.
How we handle collisions → hash-table techniques.

These are often mixed together, which makes hashing confusing.

1. What is hashing?

Suppose we have:

Key = 42

A hash function converts it into an index:

hash(42) → 2

Then we store the value in:

table[2]

The goal is to make:

search, insertion, and deletion approximately O(1) on average.

A. Types of Hash Functions

There are several techniques.

1. Division / Modulo Method ⭐⭐⭐⭐⭐

The simplest and most common idea:

index = key % tableSize;

Example:

tableSize = 10

15 % 10 = 5
25 % 10 = 5
37 % 10 = 7
42 % 10 = 2

So:

15 → index 5
25 → index 5
37 → index 7
42 → index 2
Benefits
Very simple
Very fast
Easy to implement
Excellent for learning hash tables
Common interview example
Problem

Different keys can produce the same index.

15 % 10 = 5
25 % 10 = 5
35 % 10 = 5

This is called a collision.

B. Multiplication Method

Instead of:

key % tableSize

we multiply the key by a constant.

Conceptually:

hash(key) = floor(m × fractional_part(key × A))

where:

0 < A < 1

For example:

key = 25
A = 0.618

Then we take the fractional part and map it to a table index.

Benefits
Can distribute keys well
Less dependent on choosing a particular table size
Useful in some theoretical/advanced implementations
For interviews

Know the idea, but you usually don't need to memorize the mathematical formula unless you're taking an algorithms course.

C. String Hashing

Hashing isn't only for integers.

Suppose:

"cat"

We need to convert characters into a number.

One simple approach:

c = 3
a = 1
t = 20

Then combine them.

A common polynomial-style idea is:

hash = hash * base + character

For example:

long long hash = 0;

for(char c : str)
{
    hash = hash * 31 + c;
}
Benefits

Useful for:

Dictionary lookup
Comparing strings
Duplicate detection
Pattern matching
Competitive programming

For example:

"apple"
"banana"
"apple"

You can hash the strings and use a hash table to detect duplicates.

Now the more important part:
2. Collision Handling

Even a good hash function can produce collisions.

Suppose:

table size = 10

15 → 5
25 → 5
35 → 5

What do we do?

There are two major approaches:

                Collision Handling
                       |
             ┌─────────┴─────────┐
             ↓                   ↓
        Chaining          Open Addressing
                                 |
                    ┌────────────┼────────────┐
                    ↓            ↓            ↓
                Linear       Quadratic      Double
                Probing       Probing       Hashing

These are very important for interviews.

3. Separate Chaining ⭐⭐⭐⭐⭐

This is the easiest to understand.

Instead of storing only one value at each index, each index contains a list.

Example:

15 % 10 = 5
25 % 10 = 5
35 % 10 = 5

We get:

Index 0 → empty
Index 1 → empty
Index 2 → empty
Index 3 → empty
Index 4 → empty
Index 5 → 15 → 25 → 35
Index 6 → empty
...

The bucket at index 5 contains multiple values.

Implementation
vector<int> table[10];

int index = key % 10;

table[index].push_back(key);
Benefits
Very simple
Easy to implement
Can handle many collisions
Table doesn't have to be completely empty before inserting
Deletion is relatively straightforward
Disadvantage

If too many keys go into one bucket:

5 → 15 → 25 → 35 → 45 → 55 → ...

Searching can become:

O(n)

So a good hash function is important.

4. Open Addressing

Instead of creating a linked list/vector, we keep everything inside the hash table array.

If the desired position is occupied, we look for another position.

There are three major types.

4.1 Linear Probing ⭐⭐⭐⭐

Suppose:

15 → 5
25 → 5

But index 5 is already occupied.

Try:

5
6
7
8
...

So:

15 → index 5
25 → index 6
35 → index 7

Formula:

index = (hash(key) + i) % tableSize

where:

i = 0, 1, 2, 3...
Benefits
Very simple
Fast
Good cache performance
No extra linked-list memory
Problem

Primary clustering.

You can get:

[15][25][35][45][55]

A large continuous cluster forms.

5. Quadratic Probing

Instead of checking:

5
6
7
8

we jump using squares:

5 + 1²
5 + 2²
5 + 3²
5 + 4²

Formula:

index = (hash(key) + i²) % tableSize

So the positions might be:

5
6
9
4
...
Benefits

It reduces the primary clustering problem of linear probing.

Disadvantage

It can still have another type of clustering called secondary clustering.

6. Double Hashing ⭐⭐⭐⭐

This uses two hash functions.

Instead of:

hash(key) + i

we use something like:

index = (hash1(key) + i * hash2(key)) % tableSize

Example:

hash1(key) = key % 10
hash2(key) = 7 - (key % 7)

If the first position is occupied, the second hash function determines the jump.

Benefits
Better distribution
Reduces clustering significantly
Usually better than linear and quadratic probing
Disadvantage
More complicated
Requires designing two good hash functions
7. Perfect Hashing

This is a more specialized technique.

The goal is:

No collisions for a known fixed set of keys.

Suppose you know beforehand that your keys are:

10, 20, 30, 40

You can construct a hash function that maps each key to a unique position.

10 → 0
20 → 1
30 → 2
40 → 3
Benefits

Lookup can be:

O(1) worst case

rather than merely average O(1).

Where useful?

When the set of keys is static or changes very rarely.

8. Universal Hashing

Universal hashing means choosing a hash function randomly from a family of hash functions.

The idea is to reduce the probability that an attacker or bad input can deliberately cause many collisions.

Benefits
Better protection against pathological collision patterns
Useful in theoretical algorithms
Useful when input may be adversarial

You don't usually implement this from scratch in beginner interviews.

The BIG picture

Remember this diagram:

                         HASHING
                            |
                 ┌──────────┴──────────┐
                 |                     |
           Hash Function          Collision Handling
                 |                     |
       ┌─────────┼─────────┐    ┌──────┴───────────┐
       ↓         ↓         ↓    ↓                  ↓
    Division Multiplication String            Chaining
    Method    Method       Hashing                 |
                                                   |
                                           Open Addressing
                                                   |
                                  ┌────────────────┼───────────────┐
                                  ↓                ↓               ↓
                              Linear          Quadratic       Double
                              Probing          Probing         Hashing
Which ones should YOU learn?

Since you're learning DSA for software engineering interviews, I would prioritize them like this:

🔥 Must know

1. Hash function

Understand:

key % tableSize

2. Collision

Understand why:

15 → 5
25 → 5

can happen.

3. Separate Chaining

Know how to implement it.

4. Linear Probing

Know how it works and its complexity.

5. unordered_set

unordered_set<int> s;

6. unordered_map

unordered_map<int, int> mp;
⭐ Know conceptually

7. Quadratic Probing

8. Double Hashing

9. Perfect Hashing

10. Universal Hashing

You don't need to implement all of these immediately.

Complexity you should remember
Technique	Average Search	Worst Search	Extra idea
Linear Search	O(n)	O(n)	No hashing
Hash Table + Chaining	O(1)	O(n)	Lists/buckets
Linear Probing	O(1)	O(n)	Array
Quadratic Probing	O(1)	O(n)	Array
Double Hashing	O(1)	O(n)	Two hashes
Perfect Hashing	O(1)	O(1)	Fixed keys

And this is the most important distinction:

unordered_set
      ↓
Hash table
      ↓
Average:
insert  O(1)
search  O(1)
delete  O(1)

But don't say "hashing is always O(1)" in an interview.

Say:

Hash-table operations are O(1) on average, but can degrade to O(n) in the worst case because of collisions.