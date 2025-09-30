#include <iostream>
using namespace std;

class KStacks {
    int *arr;    // Array to store elements
    int *top;    // Top index of each stack
    int *next;   // Next free or next element
    int n, k;    // n = size of array, k = number of stacks
    int freeTop; // Index of the first free spot

public:
    KStacks(int k1, int n1) {
        k = k1;
        n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // Initialize all stacks as empty
        for (int i = 0; i < k; i++)
            top[i] = -1;

        // Initialize free list
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;

        freeTop = 0; // First free index
    }

    // Check if array is full
    bool isFull() {
        return freeTop == -1;
    }

    // Push an element to stack number 'sn'
    void push(int item, int sn) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        int i = freeTop;          // Get free index
        freeTop = next[i];        // Update freeTop
        arr[i] = item;            // Insert item
        next[i] = top[sn];        // Link new item to previous top
        top[sn] = i;              // Set new top
    }

    // Pop an element from stack number 'sn'
    int pop(int sn) {
        if (top[sn] == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int i = top[sn];          // Get top index
        top[sn] = next[i];        // Set new top
        next[i] = freeTop;        // Link free list
        freeTop = i;              // Update freeTop
        return arr[i];
    }
};

int main() {
    KStacks ks(3, 10); // 3 stacks, array size 10

    ks.push(15, 0);
    ks.push(45, 0);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 2);
    ks.push(9, 2);
    ks.push(7, 2);

    cout << "Popped from stack 2: " << ks.pop(2) << endl;
    cout << "Popped from stack 1: " << ks.pop(1) << endl;
    cout << "Popped from stack 0: " << ks.pop(0) << endl;

    return 0;
}
