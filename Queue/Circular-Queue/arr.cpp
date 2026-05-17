#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class CircularQueue
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if(front == 0 && rear == MAX -1 || rear + 1 == front)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if(front == -1)
        {
            front = rear = 0;
        }
        else if(rear == MAX -1)
        {
            rear = 0;
        }

        else 
         rear++;

        arr[rear] = x;
    }

    void dequeue()
    {
        if(front == -1)
        {
            cout << "Queue Underflow\n";
            return;
        }

        if(front == rear)
        {
            front = rear = -1;
        }

        else if(front == MAX - 1)
        {
          front = 0;
        }

        else
         front++;
    }

    int Front()
    {
        if(front == -1)
            return -1;

        return arr[front];
    }

    int Rear()
    {
        if(rear == -1)
            return -1;

        return arr[rear];
    }

    int size()
    {
        if(front == -1)
            return 0;

        if(rear >= front)
            return rear - front + 1;

        return MAX - front + rear + 1;
    }

    bool empty()
    {
        return front == -1;
    }

    void display()
    {
        if(front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;

        while(true)
        {
            cout << arr[i] << " ";

            if(i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << "\n";
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}