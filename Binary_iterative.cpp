#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;

    int result = binarySearchIterative(arr, target);
    if (result != -1)
        cout << "Iterative: Target " << target << " found at index " << result << endl;
    else
        cout << "Iterative: Target not found" << endl;

    return 0;
}
