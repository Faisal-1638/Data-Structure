#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

class Queue 
{
private:
    Node* front;
    Node* rear;

public:
    Queue() 
    {
        front = rear = NULL;
    }

    // Enqueue (Insert at rear)
    void enqueue(int val) 
    {
        Node* newNode = new Node(val);

        if (rear == NULL) 
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue (Remove from front)
    void dequeue() 
    {
        if (front == NULL) 
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Peek (Front element)
    int peek() 
    {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Check empty
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}