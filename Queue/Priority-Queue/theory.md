A Priority Queue is commonly implemented using a Heap.

Max Heap → Max Priority Queue → largest element has highest priority.
Min Heap → Min Priority Queue → smallest element has highest priority.

## 1. Max Heap Priority Queue

The main operations are:

Operation	Time
**Insert**	O(log n)
**Get maximum**	O(1)
**Remove maximum**	O(log n)

## 2. Why does arr[i / 2] find the parent?

For a heap stored in an array:

             50
           /    \
         40      30
        /  \
      10    20

Array:

index:  1   2   3   4   5
value: 50  40  30  10  20

For any node:

parent = i / 2
left   = 2 * i
right  = 2 * i + 1

For example, node 10 is at index 4:

parent = 4 / 2
       = 2

So its parent is arr[2] = 40.

## 3. How insertion works

Suppose we insert:

60

First put it at the end:

             50
           /    \
         40      30
        /  \     /
      10   20   60

60 is bigger than its parent 30, so swap:

             50
           /    \
         40      60
        /  \     /
      10   20   30

Then 60 is bigger than 50, so swap again:

             60
           /    \
         40      50
        /  \     /
      10   20   30

That's heapify up.

Because the heap's height is log n, insertion takes:

O(log n).

Min Heap

For a min-priority queue, the only major difference is that the parent must be smaller than its children.

Change:

arr[i] > arr[i / 2]

to:

arr[i] < arr[i / 2]

And during heapify-down, choose:

int smallest = i;

instead of:

int largest = i;

So remember:

MAX HEAP
Parent > Children
top() = largest


MIN HEAP
Parent < Children
top() = smallest

This heap implementation + understanding why insertion/deletion are O(log n) is very important for software-engineering interviews.