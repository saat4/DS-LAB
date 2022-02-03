// Linear search
#include <bits/stdc++.h>
using namespace std;
void LinearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cout << "Enter element to search : ";
    cin >> x;
    LinearSearch(arr, n, x);
}

// Enter the size of array: 5
// Enter the elements of array: 1 4 7 5 2
// Enter element to search : 8
// Element not found

// Enter the size of array: 5
// Enter the elements of array: 1 4 8 5 2
// Enter element to search : 8
// Element found at index 2