#include<iostream>
using namespace std;

int main(){
    int array[10], n, x;
    cout << "Enter size of an array: ";
    cin >> n;
    
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    cout << "Enter the element to add at the end: ";
    cin >> x;

    array[n] = x; // Add element at the end
    n++;          // Increase the size

    cout << "Array elements are: ";
    for(int i = 0; i < n; i++){
        cout << array[i] << endl;
    }

    return 0;
}
