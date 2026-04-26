#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
// Insert at end (helper function)
void insertEnd(int val) {
    Node* newNode = new Node{val, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at exact middle (slow & fast pointer)
void insertMiddle(int val) {
    Node* newNode = new Node{val, NULL};

    // Empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Find middle
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Insert before middle (before slow)
    newNode->next = slow;
    
     if (prev != NULL)
        prev->next = newNode;
     else
         head = newNode;
}


void printList() {

           Node* ptr = head;
            while(ptr != 0)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout<< endl;
}

// Main function
int main() {

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    //insertEnd(5);

    cout << "Original list:\n";
    printList();

    insertMiddle(100);

    cout << "After inserting in middle:\n";
    printList();

    return 0;
}