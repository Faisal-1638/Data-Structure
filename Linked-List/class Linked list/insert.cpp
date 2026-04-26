#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // 🔹 Insert at Beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 🔹 Insert at End (Last)
    void insertEnd(int val) {
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
    }

    // 🔹 Insert at Middle (Position-based)
    void insertMiddle(int pos, int val) {
        if (pos <= 1) {
            insertBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // If position is beyond length → insert at end
        if (temp == NULL) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 🔹 Display
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // 🔹 Insert at beginning
    list.insertBeginning(30);
    list.insertBeginning(10);

    // 🔹 Insert at end
    list.insertEnd(40);
    list.insertEnd(50);

    // 🔹 Insert in middle
    list.insertMiddle(2, 20);  // position 2
    list.insertMiddle(4, 35);  // position 4

    cout << "Linked List:\n";
    list.display();

    return 0;
}