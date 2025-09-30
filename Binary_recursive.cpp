#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right)
        return -1; // Base case: not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;

    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    if (result != -1)
        cout << "Recursive: Target " << target << " found at index " << result << endl;
    else
        cout << "Recursive: Target not found" << endl;

    return 0;
}
