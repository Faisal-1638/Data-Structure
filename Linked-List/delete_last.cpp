#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

    void insertfirst(int item)
    {
        Node* nn = new Node;

        if(head == 0) tail = nn;
         nn->val = item;
         nn->next = head;
         head = nn;
    }

    void insertlast(int item)
    {
        if(head == 0) {
            insertfirst(item);
            return;
        }

        Node* nn = new Node;
        nn->val = item;

        tail->next = nn;
        tail = nn;
        nn->next = NULL;
    }

    void deletefirst()
    {
        if(head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deletelast()
    { 
        // If the list is empty, return
        if(head == NULL) 
          return;
          // If the list has only one node, delete it and return
          if(head->next == NULL) 
          {
            deletefirst();
            //delete head;
            return;
          }

        Node* ln_prev = head;
        while(ln_prev->next != tail)
        {
            ln_prev = ln_prev->next;
        }

        Node* temp = tail;
        ln_prev->next = 0;
        tail = ln_prev;
        delete temp;
    }

int main()
{
    
    insertlast(1);
    //insertlast(2);
    deletelast();

    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    return 0;
}


/*
To perform the deletion operation at the end of linked list,
we need to traverse the list to find the second last node, 
then set its next pointer to null. 
If the list is empty then there is no node to delete or has only one node then point head to null.

Step-by-step approach:

Check if list is empty then return NULL.
If the list has only one node then delete it and return NULL.
Traverse the list to find the second last node.
=> Set the next pointer of second last node to NULL

Time Complexity: O(n), traversal of the linked list till its end, so the time complexity required is O(n).
Auxiliary Space: O(1)


*/