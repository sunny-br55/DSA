#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

// Stack using linked list
class Stack {
    Node* head;

public:
    Stack() {
        this->head = nullptr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Push an element onto stack
    void push(int new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Return the top element
    int peek() {
        if (!isEmpty()) return head->data;
        return INT_MIN;
    }
};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    st.pop();

    cout << st.peek() << endl;

    return 0;
}