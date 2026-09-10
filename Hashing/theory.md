## What is Hashing?

Hashing is a technique that lets you find data very quickly by converting a key into an index.

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