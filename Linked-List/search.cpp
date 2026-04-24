#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;

void curr()
{
    Node* a = new Node{1};
    Node* b = new Node{2};
    Node* c = new Node{3};
    Node* d = new Node{4};
    head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = 0;
}


bool search(int key)
{
    Node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->val == key)
        {
            return true;
        }

        ptr = ptr->next;
    }

    return false;

}


int main()
{
    curr();
    
    int key = 3;

    bool find = search(key);

    if(find)
      cout << "found" <<"\n";

      else 
       cout << "Not found" << "\n";
}