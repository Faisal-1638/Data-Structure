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

        if(head == 0)
        {
            head = nn;
            //insertfirst(item);// instead of head == nn we can handle it by call insertfirst
            return;
        }

            Node* ln = head;
            while(ln->next != 0)
            {
                ln = ln->next;
            }

            ln->next = nn;
    }
     
     void insert(int item, int pos)
     {
        if(pos == 1)
        {
            insertfirst(item);
            return;
        }
        Node* nn = new Node;
        nn->val = item;
        //finding previous node
        Node* prev = head;
        for(int i = 1; i <=pos-2; i++)
        {
            prev = prev->next;
        }

        Node* curr = prev->next;

        nn->next = curr;
        prev->next = nn;

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
                    //curr();
                    insert(5, 1);
                    insert(12, 1);
                    insert(14, 3);

                    display();
                }
int main()

{
    solve();

}
