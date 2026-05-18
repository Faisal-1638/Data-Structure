#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class MyStack 
{
    Node* top;
    int count;
    
public:
    MyStack() {
        top = NULL;
        count = 0;
    }

    void push(int x) 
    {
        Node* nn = new Node(x);
        nn->next = top;
        top = nn;
        
        count++;
    }

    int pop() 
    {
        if (top == NULL) 
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node* temp = top;
        top = top->next;
        int val = temp->data;
        
        count--;
        delete temp;
        return val;
    }

    int peek() 
    {
        if (top == NULL) 
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return top->data;
    }

        bool isEmpty() 
        {
            return top == NULL;
        }

        int size()
        {
            return count;
        }

        void show()
        {
            Node* ptr = top;
            while(ptr != 0)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
};

int main() 
{
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.pop() << endl;

    cout << "Top element: " << st.peek() << endl;

    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    cout << "Current size: " << st.size() << endl;
    st.show();

    return 0;
}

/*
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);

        if (!newNode) {
            cout << "Stack Overflow\n";
            return;
        }

        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;

        delete temp;
    }

    // Peek (top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    // Check empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor (free memory)
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
*/