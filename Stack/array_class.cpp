#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    // Push operation
    void push(int x) {
        if (top >= MAX - 1) 
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";

    return 0;
}