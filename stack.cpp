#include<iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        if(top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack 1 Overflow\n";
        }
    }

    void push2(int x) {
        if(top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack 2 Overflow\n";
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            cout << "Stack 1 Underflow\n";
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            cout << "Stack 2 Underflow\n";
            return -1;
        }
    }

    void displayStacks() {
        cout << "Stack 1: ";
        for(int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nStack 2: ";
        for(int i = size - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    int capacity;
    cout << "Enter size of the array: ";
    cin >> capacity;

    TwoStacks ts(capacity);

    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);
    ts.displayStacks();

    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;

    ts.displayStacks();

    return 0;
}
