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
    /*
    Node* a = new Node;
    Node* b = new Node;
    Node* c = new Node;
    Node* d = new Node;
    */
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

 void insertfirst(int item)
{
   Node* nn = new Node;
   nn->val = item;
   nn->next = head;
   head = nn; 
}

 void lastnode(int item)
 {

    Node* nn = new Node;
    nn->val = item;

    while()


 }

void display()
{
    Node* ptr = head;
    while(ptr != 0)
    {
        cout << ptr->val <<endl;
        ptr = ptr->next;
    }
}
 
void solve()
{
        curr();
        display();

}
int main()

{
    solve();

}
