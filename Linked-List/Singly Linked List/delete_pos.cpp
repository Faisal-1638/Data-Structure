#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;//initially empty list
void curr()
{
    Node* a = new Node{1};
    Node* b = new Node{2};
    Node* c = new Node{3};
    Node* d = new Node{4};
    
    head = a;// important .... we assign head == NULL , now head = a;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = 0;
}

//Time complexity o(1)
void deletefirst()
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

//Time complexity best case o(1), worst/average case o(n)
void Delete (int pos)
{
    if(pos == 1)
    {
        deletefirst();
        return;
    }
        Node* prev = head;
        for(int i = 0; i <pos-2; i++)
        {
            prev = prev->next;
        }

        Node* target = prev->next;

        Node* temp = target; // hold target to temp
        prev->next = target->next;// link the target->next to prev->next
        delete temp;

}
int main()

{
    curr();
    Delete(1);
    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    return 0;
}

