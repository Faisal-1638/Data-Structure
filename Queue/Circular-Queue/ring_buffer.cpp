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
        if((rear + 1) % MAX == front)
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
            rear = (rear + 1) % MAX;
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

        return MAX - front + rear + 1;
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