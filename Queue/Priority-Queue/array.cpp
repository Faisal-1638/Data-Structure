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

        cout << "Deleted: " << arr[front] << endl;

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