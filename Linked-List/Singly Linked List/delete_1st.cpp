#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head = NULL;//initially empty list
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

void deletefirst()
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main()

{
    curr();
    deletefirst();

    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

}

/*
Insert amd delete

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Insert at last (O(1))
void insertLast(int item) {
    Node* nn = new Node{item, nullptr};

    if (head == nullptr) {
        head = tail = nn;
    } else {
        tail->next = nn;
        tail = nn;
    }
}

// ✅ Delete First (safe)
void deleteFirst() {
    // handle empty list
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;

    // if list becomes empty
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}

// Display
void display() {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main() {

    insertLast(10);
    insertLast(20);
    insertLast(30);

    display();

    deleteFirst(); // remove 10
    display();

    deleteFirst(); // remove 20
    display();

    deleteFirst(); // remove 30
    display();

    deleteFirst(); // try deleting from empty list (safe)
    
    return 0;
}
*/
