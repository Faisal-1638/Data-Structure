#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    int arr[100];
    int size = 0;

public:

    void insert(int value)
    {
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

        cout << "Deleted: " << arr[0] << endl;

        // Shift elements left
        for(int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display queue
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

    return 0;
}

/*
Time Complexity
Operation	Complexity
Insert	O(n)
Delete	O(n)
Peek Front	O(1)
*/