#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) { // Node(int v) : data(v), next(nullptr) {}
        val = v;
        next = NULL;
        
    }
};

class LinkedList {
private:
    Node* head;
    int SIZE;

public:
    LinkedList() {
        head = NULL;
        SIZE = 0;
    }

    void insertFirst(int item) {
        SIZE++;
        Node* nn = new Node(item);
        nn->next = head;
        head = nn;
    }

    void insertLast(int item) {
        Node* nn = new Node(item);

        if (head == NULL) {
            head = nn;
            SIZE++;
            return;
            // alternatively: insertFirst(item);
        }

        SIZE++;
        Node* ln = head;

        while (ln->next != NULL) {
            ln = ln->next;
        }

        ln->next = nn;
    }

    void insertAtPosition(int item, int pos) {
        if (pos > SIZE + 1 || pos <= 0) {
            cout << "OUT of size\n";
            return;
        }

        if (pos == 1) {
            insertFirst(item);
            return;
        }

        if(pos == SIZE + 1)
        {
            insertLast(item);
            return;
        }

        Node* nn = new Node(item);

        // find previous node (pos-1)
        Node* prev = head;
        for (int i = 0; i < pos - 2; i++) {
            prev = prev->next;
        }

        Node* curr = prev->next;

        nn->next = curr;
        prev->next = nn;

        SIZE++;
    }

    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertLast(4);
    list.insertLast(5);
    list.insertLast(6);

    list.insertAtPosition(12, 4);
    list.insertAtPosition(10, 5);
    list.insertAtPosition(15, 6);

    list.display();

    return 0;
}