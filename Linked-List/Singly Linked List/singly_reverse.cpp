#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at last
    void insertLast(int item)
    {
        Node* nn = new Node(item);

        if(head == NULL)
        {
            head = nn;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = nn;
    }

    // Reverse list
    void reverseList()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev; // update head
    }

    // Display
    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.insertLast(4);

    cout << "Original: ";
    list.display();

    list.reverseList();

    cout << "Reversed: ";
    list.display();

    return 0;
}

/*
Time: O(n)
Space: O(1)
*/