#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

// Insert function
void insert(int key)
{
    int index = key % SIZE;
    hashTable[index] = key;
}

// Search function
bool search(int key)
{
    int index = key % SIZE;
    return (hashTable[index] == key);
}

int main()
{
    // Initialize with -1
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    // Insert values
    insert(15);
    insert(22);
    insert(37);

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    if(search(x))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}