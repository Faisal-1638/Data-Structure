#include <bits/stdc++.h>
using namespace std;
#define MAX 10
class Queue{
private:
    int arr[MAX];
    int front;
    int rear;
public: 
     Queue()
     {
        front = -1;
        rear = -1;
     }

     void enqueue(int x)
     {
       if(rear == MAX - 1)
       {
        cout << "Overflow" << endl;
        return;
       }

       if(front == -1) 
         front = 0;

       arr[++rear] = x;
     }

     void dequeue()
     {
        if(front == -1)
        {
            cout << "underflow" << endl;
            return;
        }

        if(front == rear)
         front = rear = -1;

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
        return rear - front + 1;
     }

     void display()
     {
        if(front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        for(int i = front; i <= rear; i++)
        {
            cout<< arr[i] << " ";
        }

        cout << "\n";
     }

};



int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(10);
    q.display();
        cout << "front: " << q.Front() << endl;
        cout << "rear: " << q.Rear() << endl;
        cout << "size: " << q.size();

}

/*
Efficiency
Operation	Complexity
enqueue	O(1)
dequeue	O(1)
Front	O(1)
Rear	O(1)
display	O(n)
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if(rear == size - 1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if(front == -1)
            front = 0;

        rear++;
        arr[rear] = value;

        cout << value << " inserted into queue\n";
    }

    // Dequeue operation
    void dequeue()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed from queue\n";
        front++;

        // Reset queue when empty
        if(front > rear)
        {
            front = rear = -1;
        }
    }

    // Display queue
    void display()
    {
        if(front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";

        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

    // Front element
    void peek()
    {
        if(front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front element: " << arr[front] << "\n";
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.peek();

    return 0;
}
*/