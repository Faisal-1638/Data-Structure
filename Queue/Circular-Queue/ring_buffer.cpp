#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class RingBuffer
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    RingBuffer()
    {
        front = -1;
        rear = -1;
    }

    // Insert element
    void enqueue(int x)
    {
        // Queue Full
        if((rear + 1) % MAX == front)// for 1-based index ----> 
        {
            cout << "Buffer Overflow\n";
            return;
        }

        // First element
        if(front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;// for 1-based index ----> rear = rear % max + 1
        }

        arr[rear] = x;
    }

    // Remove element
    void dequeue()
    {
        // Queue Empty
        if(front == -1)
        {
            cout << "Buffer Underflow\n";
            return;
        }

        // Only one element
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    // Front element
    int Front()
    {
        if(front == -1)
            return -1;

        return arr[front];
    }

    // Rear element
    int Rear()
    {
        if(rear == -1)
            return -1;

        return arr[rear];
    }

    // Current size
    int size()
    {
        if(front == -1)
            return 0;

        if(rear >= front)
            return rear - front + 1;

        return (MAX - front) + (rear + 1); //Queue has wrapped around
    }

    // Check empty
    bool empty()
    {
        return front == -1;
    }

    // Display queue
    void display()
    {
        if(front == -1)
        {
            cout << "Buffer is empty\n";
            return;
        }

        for(int i = front; ; i = (i + 1) % MAX)
        {
            cout << arr[i] << " ";

            if(i == rear)
                break;
        }

        cout << endl;
    }
};

int main()
{
    RingBuffer rb;

    rb.enqueue(10);
    rb.enqueue(20);
    rb.enqueue(30);
    rb.enqueue(40);

    rb.display();

    rb.dequeue();
    rb.dequeue();

    rb.display();

    rb.enqueue(50);
    rb.enqueue(60);

    rb.display();

    cout << "Front: " << rb.Front() << endl;
    cout << "Rear : " << rb.Rear() << endl;
    cout << "Size : " << rb.size() << endl;

    return 0;
}

/*
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int data) {
        if ((rear + 1) % capacity == front) {
            cout << "Overflow! Queue is full.\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        cout << "Enqueued: " << data << "\n";
    }

    int dequeue() {
        if (front == -1) {
            cout << "Underflow! Queue is empty.\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) { // Reset queue when it becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return val;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main() {
    cout << "--- Circular Queue Demo ---\n";
    CircularQueue cq(3);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cout << "Dequeued element: " << cq.dequeue() << "\n";
    cq.display();

    // Unlike linear queue, circular queue successfully reuses index 0:
    cout << "Attempting to enqueue 40...\n";
    cq.enqueue(40); 
    cq.display();

    return 0;
}
*/