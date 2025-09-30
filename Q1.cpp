#include <iostream>
using namespace std;

int main() {
    const int SIZE = 100; // Maximum size of the array
    int numbers[SIZE] = {2, 3, 4, 5}; // Starting array
    int currentSize = 4; // Number of elements in the array
    int newNumber = 3; // Number we want to add at the beginning

    // Move each element one position to the righta
    for (int i = currentSize; i > 0; i--) {
        numbers[i] = numbers[i - 1];
    }

    // Put the new number at the front
    numbers[0] = newNumber;
    currentSize++; // Increase the count of elements

    // Show the updated array
    cout << "Updated array: ";
    for (int i = 0; i < currentSize; i++) {
        cout << numbers[i] << " ";
    }

    
    return 0;
}

