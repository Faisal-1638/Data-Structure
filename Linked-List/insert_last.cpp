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

 void insertfirst(int item)
{
   Node* nn = new Node;
   nn->val = item;
   nn->next = head;
   head = nn; 
}

    void insertlast(int item)
    {
        Node* nn = new Node;
        nn->val = item;
        nn->next = NULL;

        if(head == NULL)//handle empty list
        {
            head = nn;
            //insertfirst(item);// instead of head == nn we can handle it by call insertfirst
            return;
        }

            Node* ln = head;
            while(ln->next != NULL)
            {
                ln = ln->next;
            }

            ln->next = nn;
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
