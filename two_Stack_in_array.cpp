#include <iostream>
using namespace std;

class NStack {
public:
    int *arr;
    int Top1, Top2;
    int size;

    // Constructor
    NStack(int n) {
        size = n;
        arr = new int[n];
        Top1 = -1;
        Top2 = n;
    }

    // Push function for stack 1
    void push1(int x) {
        if (Top1 + 1 == Top2) {
            cout << "Stack 1 is full" << endl;
            return;
        }
        Top1++;
        arr[Top1] = x;
    }

    // Push function for stack 2
    void push2(int x) {
        if (Top2 - 1 == Top1) {
            cout << "Stack 2 is full" << endl;
            return;
        }
        Top2--;
        arr[Top2] = x;
    }

    // Pop function for stack 1
    int pop1() {
        if (Top1 == -1) {
            cout << "Stack 1 is empty" << endl;
            return -1;
        }
        int elem = arr[Top1];
        Top1--;
        return elem;
    }

    // Pop function for stack 2
    int pop2() {
        if (Top2 == size) {
            cout << "Stack 2 is empty" << endl;
            return -1;
        }
        int elem = arr[Top2];
        Top2++;
        return elem;
    }
};

int main() {
    NStack s(6); // Create an array of size 6 for two stacks

    // Push elements into Stack 1
    s.push1(10);
    s.push1(20);
    s.push1(30);
    
    // Push elements into Stack 2
    s.push2(100);
    s.push2(200);

    // Pop elements
    cout << "Popped from Stack 1: " << s.pop1() << endl; // Should print 30
    cout << "Popped from Stack 2: " << s.pop2() << endl; // Should print 200

    // More pops
    cout << "Popped from Stack 1: " << s.pop1() << endl; // Should print 20
    cout << "Popped from Stack 2: " << s.pop2() << endl; // Should print 100

    // Trying to pop from empty stack
    cout << "Popped from Stack 2: " << s.pop2() << endl; // Should print empty message

    return 0;
}
