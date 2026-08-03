#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

bool search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return true;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }

    return false;
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    insert(15);
    insert(25);
    insert(35);
    insert(45);

    cout << "Hash Table:\n";
    for (int i = 0; i < SIZE; i++)
        cout << i << " -> " << hashTable[i] << endl;

    cout << "\nSearching 35: ";
    if (search(35))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}

/*
Time Complexity
Insertion: O(1) average, O(n) worst case.
Search: O(1) average, O(n) worst case.
Deletion: O(1) average, O(n) worst case.

For unsorted data, Binary Search cannot be used directly because it requires the data to be sorted.

Options for Unsorted Data
Linear Search (Best choice)
No sorting required.
Time Complexity: O(n).
Sort first, then Binary Search
Sorting: O(n log n)
Binary Search: O(log n)
Total: O(n log n).
Useful only if you need to perform many searches on the same data.
Hashing (Hash Table)
Average search: O(1).
Best choice if frequent searches are needed and order is not important.

For unsorted data, Binary Search is not suitable because it requires a sorted array. The best search method is Linear Search, which works directly on unsorted data with O(n) time complexity. If many searches are required, the data can first be sorted or stored in a hash table for faster searches.
*/