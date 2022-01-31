// Binary search
#include <bits/stdc++.h>
using namespace std;
void BinarySearch(int arr[], int, int, int);
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int x;
    cout << "Enter element to search : ";
    cin >> x;
    BinarySearch(arr, 0, n - 1, x);
}
void BinarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            cout << "Element found at index " << mid << endl;
            return;
        }
        if (arr[mid] > x) {
            BinarySearch(arr, l, mid - 1, x);
        } else {
            BinarySearch(arr, mid + 1, r, x);
        }
    } else {
        cout << "Element not found";
    }
}

// Enter the size of array: 5
// Enter the elements of array: 1 4 7 5 2
// Enter element to search : 8
// Element not found

// Enter the size of array: 6
// Enter the elements of array: 1 4 7 8 5 2
// Enter element to search : 5
// Element not found