#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Priority Queue using Linked List
class PriorityQueue
{
    Node* head;

public:
    
    PriorityQueue()
    {
        head = NULL;
    }

    // Insert operation
    void insert(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        // Insert at beginning if queue is empty
        // or value has higher priority
        if(head == NULL || value > head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;

            // Find correct position
            while(temp->next != NULL &&
                  temp->next->data >= value)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << value << " inserted successfully.\n";
    }

    // Delete operation
    void remove()
    {
        if(head == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Deleted element: "
             << temp->data << endl;

        head = head->next;

        delete temp;
    }

    // Display queue
    void display()
    {
        if(head == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Priority Queue: ";

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
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