#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode *next, *prev;
    DLLNode(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Deque {
private:
    DLLNode *front, *rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    ~Deque() {
        while (front != nullptr) {
            DLLNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void insertFront(int data) {
        DLLNode* temp = new DLLNode(data);
        if (front == nullptr) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        cout << "Inserted at Front: " << data << "\n";
    }

    void insertRear(int data) {
        DLLNode* temp = new DLLNode(data);
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        cout << "Inserted at Rear: " << data << "\n";
    }

    int deleteFront() {
        if (front == nullptr) {
            cout << "Underflow at Front!\n";
            return -1;
        }
        DLLNode* temp = front;
        int val = temp->data;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // List is now empty
        }
        delete temp;
        return val;
    }

    int deleteRear() {
        if (rear == nullptr) {
            cout << "Underflow at Rear!\n";
            return -1;
        }
        DLLNode* temp = rear;
        int val = temp->data;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // List is now empty
        }
        delete temp;
        return val;
    }

    void display() {
        if (front == nullptr) {
            cout << "Deque is Empty\n";
            return;
        }
        cout << "Deque Elements: ";
        DLLNode* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    cout << "--- Double-Ended Queue (Deque) Demo ---\n";
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);  // Inserts at the start
    dq.insertRear(30);  // Inserts at the end
    dq.display();       // Expected output: 5 10 20 30

    cout << "Deleted from Front: " << dq.deleteFront() << "\n";
    cout << "Deleted from Rear: " << dq.deleteRear() << "\n";
    dq.display();       // Expected output: 10 20

    return 0;
}