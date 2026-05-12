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

    // Insert Last (for testing)
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

        SIZE++;
    }

    // 🔥 Delete First
    void deleteFirst()
    {
        if(head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;

        delete temp;
        SIZE--;
    }

    // 🔥 Delete Last
    void deleteLast()
    {
        if(head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            SIZE--;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;

        SIZE--;
    }

    // 🔥 Delete at Position
    void deleteAtPos(int pos)
    {
        if(pos <= 0 || pos > SIZE)
        {
            cout << "OUT of size\n";
            return;
        }

        if(pos == 1)
        {
            deleteFirst();
            return;
        }

        if(pos == SIZE)
        {
            deleteLast();
            return;
        }

        Node* curr = head;
        for(int i = 1; i < pos; i++)
            curr = curr->next;

        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete curr;
        SIZE--;
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
    DoublyLinkedList list;

    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.insertLast(4);

    cout << "Original: ";
    list.display();

    list.deleteFirst();
    cout << "After delete first: ";
    list.display();

    list.deleteLast();
    cout << "After delete last: ";
    list.display();

    list.deleteAtPos(2);
    cout << "After delete pos 2: ";
    list.display();

    return 0;
}