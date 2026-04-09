#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;
void insertfirst(int item)
{
   Node* nn = new Node;
   nn->val = item;
   nn->next = head;
   head = nn; 
}
 void solve()
 {
    insertfirst(5);
    insertfirst(6);
    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->val <<endl;
        ptr = ptr->next;
    }

 }
int main()

{
    solve();

}

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