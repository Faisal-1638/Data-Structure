#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) { 
        val = v;
        next = NULL;
        
    }
};

class Queue
{
    private:
        Node* head;
        Node* tail;
        int SIZE;

    public:
        Queue() {
            head = NULL;
            tail = NULL;
        }

        void enqueue(int item)
        {
            Node* nn = new Node(item);

            if(head == NULL)
            {
                head = tail = nn;
            }

            else 
            {
                tail->next = nn;
                tail = nn;
            }
        }

        void dequeue()
        {
            if(head == NULL)
              return ;

              Node* temp = head;
              head = head->next;
              delete temp;
        }

        int front()
        {
            if(head == NULL)
              return -1;

              else
               return head->val;
        }
        void display()
        {
            Node* ptr = head;
            while(ptr != NULL)
            {
                cout << ptr->val << endl;
                ptr = ptr->next;
            }
            
            cout << "\n";
        }
};

int main()
{
  Queue q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.dequeue();
  cout << q1.front() << endl;
  q1.display();

}
