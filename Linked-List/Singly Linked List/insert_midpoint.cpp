#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at middle using length
void insertMiddle(Node*& head, int val) 
{
    Node* newNode = new Node{val, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    int len = 0;
    Node* temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }

    // Step 3: move to (pos - 1)
    temp = head;
    for (int i = 1; i < len/2; i++) {
        temp = temp->next;
    }

    // Step 4: insert
    newNode->next = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head) 
{
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Main
int main() 
{
    Node* head = nullptr;

    // Create: 1 → 2 → 3 → 4 → 5
    head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    cout << "Original: ";
    printList(head);

    insertMiddle(head, 100);

    cout << "After insert: ";
    printList(head);

    return 0;
}