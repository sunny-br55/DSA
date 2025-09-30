#include <iostream>
using namespace std;

int main() {
    const int SIZE = 100; // Maximum size of the array
    int numbers[SIZE] = {2, 3, 4, 5}; // Initial array
    int currentSize = 4; // Current number of elements

    int newNumber; // Number to insert
    int position;  // Where to insert the number

    // Ask user for input
    cout << "Enter the number to insert: ";
    cin >> newNumber;

    cout << "Enter the position (0 to " << currentSize << "): ";
    cin >> position;

    // Check if position is valid
    if (position < 0 || position > currentSize) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    // Shift elements to the right to make space
    for (int i = currentSize; i > position; i--) {
        numbers[i] = numbers[i - 1];
    }

    // Insert the new number
    numbers[position] = newNumber;
    currentSize++;

    // Display updated array
    cout << "Array after insertion: ";
    for (int i = 0; i < currentSize; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
