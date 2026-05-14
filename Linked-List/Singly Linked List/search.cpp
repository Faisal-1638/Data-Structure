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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at first (head)
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Search element
    bool search(int key) {
        Node* ptr = head;

        while (ptr != NULL) {
            if (ptr->val == key) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    // Display list (for checking)
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Insert at first (reverse order will appear)
    list.insertFirst(4);
    list.insertFirst(3);
    list.insertFirst(2);
    list.insertFirst(1);

    list.display();  // Output: 1 2 3 4

    int key = 3;

    if (list.search(key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}