#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverseDLL(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev after swap)
        current = current->prev;
    }

    // Update head
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

int main() {
    Node* head = NULL;

    // Create list: 1 ⇄ 2 ⇄ 3 ⇄ 4
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Original List: ";
    printList(head);

    // Reverse list
    head = reverseDLL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
/*
🔁 Core Idea
In a doubly linked list, every node has:


prev → points backward


next → points forward


👉 To reverse the list, we just swap these two pointers for every node.

🧠 Key Trick
After swapping:
current->prev = current->next;current->next = temp;
👉 The original next node is now in current->prev
So to move forward, we do:
current = current->prev;

🪜 Step-by-Step Example
Original List:
NULL <- 1 <-> 2 <-> 3 -> NULL

🧩 Step 1 (current = 1)
Before swap:
prev = NULLnext = 2
After swap:
prev = 2next = NULL
List becomes:
1 -> NULL↑2 <-> 3
Move:
current = current->prev = 2

🧩 Step 2 (current = 2)
Before:
prev = 1next = 3
After swap:
prev = 3next = 1
Now:
3 <-> 2 <-> 1
Move:
current = 3

🧩 Step 3 (current = 3)
Before:
prev = 2next = NULL
After swap:
prev = NULLnext = 2
Final reversed structure:
NULL <- 3 <-> 2 <-> 1 -> NULL

🎯 Final Head Fix
After loop:
if (temp != NULL) {    head = temp->prev;}
👉 Why?


temp holds previous node reference from last iteration


temp->prev becomes the new head (last node of original list)



⚠️ Common Confusion
👉 Why current = current->prev?
Because after swapping:


prev actually points to the next node



⏱ Complexity


Time: O(n)


Space: O(1) (in-place)



💡 Simple Analogy
Imagine every node flips its arrows:
← becomes →→ becomes ←
Then you just follow the flipped arrows.

*/