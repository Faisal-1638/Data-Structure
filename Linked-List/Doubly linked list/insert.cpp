#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int v)
    {
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    int SIZE;

public:
    DoublyLinkedList()
    {
        head = NULL;
        SIZE = 0;
    }

    // Insert at first
    void insertFirst(int item)
    {
        Node* nn = new Node(item);

        nn->next = head;

        if(head != NULL)
            head->prev = nn;

        head = nn;
        SIZE++;
    }

    // Insert at last
    void insertLast(int item)
    {
        Node* nn = new Node(item);

        if(head == NULL)
        {
            head = nn;
            SIZE++;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = nn;
        nn->prev = temp;
        nn->next = NULL;

        SIZE++;
    }

    // Insert at position
    void insert(int item, int pos)
    {
        if(pos > SIZE + 1 || pos <= 0)
        {
            cout << "OUT of size" << endl;
            return;
        }

        if(pos == 1)
        {
            insertFirst(item);
            return;
        }

        if(pos == SIZE + 1)
        {
            insertLast(item);
            return;
        }

        Node* nn = new Node(item);

        Node* prevNode = head;
        for(int i = 0; i < pos - 2; i++)
            prevNode = prevNode->next;

        Node* curr = prevNode->next;

        nn->next = curr;
        nn->prev = prevNode;

        prevNode->next = nn;
        curr->prev = nn;

        SIZE++;
    }

    // Display forward
    void display()
    {
        Node* ptr = head;
        while(ptr != NULL)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertLast(4);
    list.insertLast(5);
    list.insertLast(6);

    list.insert(12, 4);
    list.insert(10, 5);
    list.insert(15, 6);

    list.display();

    return 0;
}