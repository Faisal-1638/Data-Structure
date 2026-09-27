#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    int arr[100];
    int size = 0;

public:

    void insert(int value)
    {
        if(size == 100)
    {
        cout << "Queue Overflow\n";
        return;
    }
        int i;

        // Shift smaller elements right
        for(i = size - 1; i >= 0; i--)
        {
            if(arr[i] < value)
                arr[i + 1] = arr[i];
            else
                break;
        }

        arr[i + 1] = value;
        size++;
    }

    // Delete highest priority element
    void remove()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        //cout << "Deleted: " << arr[0] << endl;

        // Shift elements left
        for(int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    int Front()
   {
    if(size == 0)
    {
        cout << "Queue is empty\n";
        return -1;
    }

    return arr[0];
   }
    void display()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";

        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);

    pq.display();

    pq.remove();

    pq.display();
    cout << pq.Front() << endl;

    return 0;
}

/*
Time Complexity
Operation	Complexity
Insert	O(n)
Delete	O(n)
Peek Front	O(1)

The log n comes from the height of the heap.

Let's see it slowly.

1. Look at a heap
                50                 ← level 0
             /      \
           30        40             ← level 1
          /  \      /  \
        20   10   35   25           ← level 2
       / \
      5   8                         ← level 3

Count the nodes at each level:

Level 0 → 1 node
Level 1 → 2 nodes
Level 2 → 4 nodes
Level 3 → 8 nodes

So every time we go one level down, the number of possible nodes doubles.

2. Where does log n come from?

Suppose the heap has about 8 nodes.

Its height is:

1 → 2 → 4 → 8

How many times did we double?

1 → 2    (1)
2 → 4    (2)
4 → 8    (3)

So:

log₂(8) = 3

Therefore, an 8-node heap has about 3 levels.

For 16 nodes:

1 → 2 → 4 → 8 → 16

So:

log₂(16) = 4
3. Now insertion

Suppose we insert 60.

It first goes to the bottom:

                50
             /      \
           30        40
          /  \      /  \
        20   10   35   25
       / \
      5   8
     /
    60

Now 60 is bigger than 5, so swap:

60 moves ↑

Then it may swap with 20:

60 moves ↑

Then with 30:

60 moves ↑

Then with 50:

60 moves ↑

The important thing is:

It only moves along one path.

It doesn't check:

60 against every node

It only goes:

bottom
   ↑
   ↑
   ↑
root

How long can that path be?

The height of the heap.

And the height is:

O(log n)
4. Why does heap height become log n?

Because the tree grows like:

             1
           /   \
          2     2
        / |     | \
       4  ...   ...
      /
     8

More generally:

Level 0 → 1
Level 1 → 2
Level 2 → 4
Level 3 → 8
Level 4 → 16
...

So after h levels, you can have approximately:

2^h nodes

If there are n nodes:

n ≈ 2^h

Therefore:

h ≈ log₂(n)

That's where the log n comes from.

The key difference

In binary search:

n → n/2 → n/4 → n/8 ...

We literally reduce the search space by half.

In a heap:

1 → 2 → 4 → 8 → 16 ...

The number of nodes per level doubles, which means the height is log₂(n).

So both end up with O(log n), but for slightly different reasons.

Heap operation = travels through the height of the tree = O(log n).
*/

/*
#include<bits/stdc++.h>
using namespace std;

#define MAX 10

class PriorityQueue
{
private:

    int arr[MAX];
    int front;
    int rear;

public:

    PriorityQueue()
    {
        front = -1;
        rear = -1;
    }

    // Insert according to priority
    void Enqueue(int x)
    {
        if(rear == MAX - 1)
        {
            cout << "Overflow\n";
            return;
        }

        // First element
        if(front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
            return;
        }

        int i;

        // Shift smaller elements right
        for(i = rear; i >= front; i--)
        {
            if(arr[i] < x)
            {
                arr[i + 1] = arr[i];
            }
            else
            {
                break;
            }
        }

        arr[i + 1] = x;
        rear++;
    }

    // Delete highest priority element
    void Dequeue()
    {
        if(front == -1)
        {
            cout << "Underflow\n";
            return;
        }

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    int Front()
    {
        if(front == -1)
        {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front];
    }

    int size()
    {
        if(front == -1)
            return 0;

        return rear - front + 1;
    }

    void display()
    {
        if(front == -1)
        {
            cout << "Queue Empty\n";
            return;
        }

        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue q;

    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(15);

    q.display();

    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.Front() << endl;

    q.Dequeue();

    q.display();
}
*/

/*
If you don't keep the array sorted, you can make insertion faster:

Insert → O(1)
Remove highest → O(n)
Front/highest → O(n)

For example:

30 10 50 20

To remove the highest priority, you have to search for 50.

So there is a trade-off:

Implementation	Insert	Remove highest	Peek highest
Your sorted array	O(n)	O(n)	O(1)
Unsorted array	O(1)	O(n)	O(n)
Binary Heap	O(log n)	O(log n)	O(1)

And this is exactly why we use a heap for an efficient priority queue.

Your code → Heap

Your current structure:

Priority Queue
     ↓
Sorted Array
     ↓
Insert O(n)
Remove O(n)

With a heap:

Priority Queue
     ↓
Binary Heap
     ↓
Insert O(log n)
Remove O(log n)
Peek O(1)

So your current code is actually a very good way to understand why heaps are needed before learning priority_queue and binary heaps.
*/