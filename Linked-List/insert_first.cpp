#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;//initially empty list
//Time complexity best case o(1), worst/average case o(n)
void insertfirst(int item)
{  
   //Node* nn = new Node{item, NULL};
   Node* nn = new Node;
   nn->val = item;
   nn->next = head;
   head = nn; 
}

//Time complexity o(n)
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
    insertfirst(5);
    insertfirst(6);
    display();

 }
int main()

{
    solve();

}


/*
Works for:
Empty list (head = NULL)
Non-empty list
Time Complexity: O(1) (constant time)
*/



/*
🧠 What is head?

👉 head is a pointer that stores the address of the first node of the linked list.

Node* head;
Node* → pointer to a node
head → points to the first node
🔗 Visual Understanding

Suppose your list is:

10 -> 20 -> 30 -> NULL

Memory view:

head
  ↓
[10 | next] → [20 | next] → [30 | NULL]
*/


/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    display(head);
}
*/