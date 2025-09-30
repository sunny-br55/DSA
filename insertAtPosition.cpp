#include<iostream>
using namespace std;

int main(){
    int array[11], n, x, pos;
    cout << "Enter size of the array (max 10): ";
    cin >> n;

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    cout << "Enter the element to insert: ";
    cin >> x;
    cout << "Enter the position (0 to " << n << "): ";
    cin >> pos;

    if(pos < 0 || pos > n || n >= 10) {
        cout << "Invalid position or array full!" << endl;
    } else {
        // Shift elements to make space
        for(int i = n; i > pos; i--){
            array[i] = array[i-1];
        }
        array[pos] = x;
        n++;

        cout << "Updated array elements: ";
        for(int i = 0; i < n; i++){
            cout << array[i] << endl;
        }
    }

    return 0;
}
