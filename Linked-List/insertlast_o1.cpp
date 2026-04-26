#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;//tail pointer for O(1) insertLast
// void curr()
// {
//     Node* a = new Node{1};
//     Node* b = new Node{2};
//     Node* c = new Node{3};
//     Node* d = new Node{4};
    
//     head = a;// important .... we assign head == NULL , now head = a;

//     a->next = b;
//     b->next = c;
//     c->next = d;
//     d->next = 0;

//     tail = d;// if use initializer list must the tail point to d;
// }

    void insertlast(int item)
    {
        Node* nn = new Node;
        nn->val = item;
        nn->next = NULL;

        if(head == NULL)//handle empty list
        {
            head = tail = nn;
            return;
        }

            else 
              {
                tail->next = nn;
                tail = nn;
              }
    }

        void display()
        {
            Node* ptr = head;
            while(ptr != NULL)
            {
                cout << ptr->val << " ";
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

