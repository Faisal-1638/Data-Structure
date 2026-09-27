#include <bits/stdc++.h>
using namespace std;

class MaxPriorityQueue
{
    int arr[100];
    int size = 0;

public:

    // Insert a value
    void push(int value)
    {
        if (size == 100)
        {
            cout << "Queue Overflow\n";
            return;
        }

        size++;
        int i = size;

        // Put value at the end
        arr[i] = value;

        // Move upward
        while (i > 1 && arr[i] > arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    // Remove maximum
    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        // Move downward
        int i = 1;

        while (true)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    // Get maximum
    int top()
    {
        if (size == 0)
            return -1;

        return arr[1];
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    MaxPriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << pq.top() << endl;  // 50

    pq.pop();

    cout << pq.top() << endl;  // 40
}
