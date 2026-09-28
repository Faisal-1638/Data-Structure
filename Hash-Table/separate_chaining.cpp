#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    static const int SIZE = 10;

    vector<int> table[SIZE];

    // Hash function
    int hashFunction(int key)
    {
        return key % SIZE;
    }

public:

    // Insert
    void insert(int key)
    {
        int index = hashFunction(key);

        table[index].push_back(key);
    }

    // Search
    bool search(int key)
    {
        int index = hashFunction(key);

        for (int value : table[index])
        {
            if (value == key)
                return true;
        }

        return false;
    }

    // Delete
    void remove(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin();
             it != table[index].end();
             it++)
        {
            if (*it == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    // Print
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";

            for (int value : table[i])
            {
                cout << value << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(12);

    h.display();

    if (h.search(25))
        cout << "25 Found\n";
    else
        cout << "25 Not Found\n";

    h.remove(25);

    cout << "\nAfter removing 25:\n";
    h.display();

    return 0;
}

/*
How the hash function works

We use:

int hashFunction(int key)
{
    return key % SIZE;
}

Since SIZE = 10:

15 % 10 = 5
25 % 10 = 5
35 % 10 = 5
12 % 10 = 2

Therefore:

Index 0:
Index 1:
Index 2: 12
Index 3:
Index 4:
Index 5: 15 25 35
Index 6:
...

Notice something important:

15 → index 5
25 → index 5
35 → index 5

They all go to the same index. This is called a collision.

We solve it here using separate chaining:

index 5 → [15 → 25 → 35]
The key idea

A manually implemented hash table is basically:

                HASH TABLE

key
 ↓
hash function
 ↓
array index
 ↓
bucket
 ↓
store/search value

For example:

        25
        ↓
    25 % 10
        ↓
        5
        ↓
   table[5]

This is the basic idea behind what unordered_set and unordered_map are doing internally, although the real C++ implementation is much more sophisticated.

For interviews, understand these four things very well:

Hash function
Collision
Collision handling — chaining / open addressing
Why lookup is O(1) average
*/