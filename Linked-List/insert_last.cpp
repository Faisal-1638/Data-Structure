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
    
    head = a;// important .... we assign head == NULL , now head = a;

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

    void insertlast(int item)
    {
        if(head == NULL)//handle empty list
        {
            //head = nn;//if not use insertfirst()
            insertfirst(item);// instead of head == nn we can handle it by call insertfirst
            return;
        }

            Node* nn = new Node;
            //Node* nn = new Node{item, NULL};// this line automatic add item and item->next = NULL:
            nn->val = item;

            Node* ln = head;
            while(ln->next != NULL)
            {
                ln = ln->next;
            }

            ln->next = nn;
            nn->next = NULL;
    }

        void display()
        {
            Node* ptr = head;
            while(ptr != NULL)
            {
                cout << ptr->val <<endl;
                ptr = ptr->next;
            }
        }

                void solve()
                {
                    //curr();
                    insertlast(10);
                    insertlast(12);
                    insertlast(14);
                    insertlast(16);

                    display();
                }
int main()

{
    solve();

}


/*
Code Reminder
void insertLast(Node*& head, int item) {
    Node* nn = new Node;
    nn->val = item;
    nn->next = nullptr;

    if (head == nullptr) {
        head = nn;
        return;
    }

    Node* ln = head;
    while (ln->next != nullptr) {
        ln = ln->next;  // traverse to the last node
    }

    ln->next = nn;
}
🔹 Step by Step
Empty list check (head == nullptr) → O(1)
Traversal:
Node* ln = head;
while (ln->next != nullptr)
    ln = ln->next;
We start from head and go node by node until the last node
If the list has n nodes, we make n steps
Each step is O(1)
Link new node → O(1)
🔹 Time Complexity
Operation	Complexity
Empty list (head == nullptr)	O(1)
Non-empty list traversal	O(n)
Total worst-case	O(n)

✅ So insertLast is O(n) in a normal singly linked list.


Optimization

If you maintain a tail pointer, you can insert at the end in O(1):

Node* tail = nullptr;

void insertLast(Node*& head, Node*& tail, int item) {
    Node* nn = new Node{item, nullptr};
    if (head == nullptr) {
        head = tail = nn;
    } else {
        tail->next = nn;
        tail = nn;
    }
}
No traversal needed → constant time insert
Tail pointer is highly recommended for efficiency.

*/