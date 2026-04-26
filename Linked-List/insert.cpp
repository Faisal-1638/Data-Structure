#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;
int SIZE = 0;
// void curr()
// {
//     Node* a = new Node{1};
//     Node* b = new Node{2};
//     Node* c = new Node{3};
//     Node* d = new Node{4};
//     head = a;
//     a->next = b;
//     b->next = c;
//     c->next = d;
//     d->next = 0;
// }

 void insertfirst(int item)
{
   SIZE++;
   Node* nn = new Node;
   nn->val = item;
   nn->next = head;
   head = nn; 
}

    void insertlast(int item)
    {
        Node* nn = new Node;
        nn->val = item;

        if(head == NULL)
        {
            head = nn;
            //insertfirst(item);// instead of head == nn we can handle it by call insertfirst
            return;
        }

            SIZE++;
            Node* ln = head;
            while(ln->next != 0)
            {
                ln = ln->next;
            }

            ln->next = nn;
            nn->next = NULL;
    }
     
     void insert(int item, int pos)
     {
         if(pos > SIZE)
         {
            cout << "OUT of size" <<endl;
         }
         
         if(pos == 1)
         {
            insertfirst(item);//if their is no first function then write next two line
            // nn->next = head;
            // head = nn;
            return;
         }

        Node* nn = new Node;
        nn->val = item;
        
        //finding previous node (pos-1)
        Node* prev = head;
        for(int i = 1; i <=pos-2; i++)
        {
            prev = prev->next;
        }

        Node* curr = prev->next;// pointer of prev next

        nn->next = curr;
        prev->next = nn;

     }

        void display()
        {
            Node* ptr = head;
            while(ptr != 0)
            {
                cout << ptr->val << " ";
                ptr = ptr->next;
            }
        }

                void solve()
                {
                    //curr();
                    insertlast(4);
                    insertlast(5);
                    insertlast(6);
                    insert(12, 2);
                    insert(10, 1);
                    insert(15, 3);
                    
                    

                    display();
                }
int main()

{
    solve();

}


/*
⏱️ Time Complexity
🔹 1. Traversal Part
The loop runs:
(pos - 2) times
In worst case:
pos ≈ n  (end of list)

So traversal = O(n)

🔹 2. Insertion Part
nn->next = prev->next;
prev->next = nn;
This is just pointer change → O(1)
✅ Final Time Complexity
Case	Time
Best case (pos = 1)	O(1)
Worst case (pos ≈ n)	O(n)

👉 Overall:

O(n)
🔥 Simple Understanding
You must walk through the list to find the position
Walking takes time proportional to number of nodes

👉 That’s why:

Linked List insert (middle) = O(n)
🚀 Comparison (Very Important)
Operation	Time
Insert First	O(1)
Insert Last (without tail)	O(n)
Insert Last (with tail)	O(1)
Insert Middle	O(n)
*/